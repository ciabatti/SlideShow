#include "MyFrame.h"
#include <wx/dir.h>

// Definizione dell'evento table
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, MyFrame::OnSelectFolder)
    EVT_TIMER(wxID_ANY, MyFrame::OnNextImage) // Evento per il timer
wxEND_EVENT_TABLE()

MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)), 
      currentImageIndex(0), slideshowTimer(this, wxID_ANY) {
    
    // Crea il pulsante per selezionare la cartella
    selectFolderButton = new wxButton(this, wxID_ANY, "Seleziona Cartella");
    imageDisplay = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap); // Inizializza il bitmap

    // Layout
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(selectFolderButton, 0, wxALL | wxCENTER, 5);
    sizer->Add(imageDisplay, 1, wxALL | wxEXPAND, 5);
    SetSizer(sizer);
}

void MyFrame::OnSelectFolder(wxCommandEvent& event) {
    wxDirDialog dirDialog(this, "Seleziona una cartella", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
    
    if (dirDialog.ShowModal() == wxID_OK) {
        wxString folderPath = dirDialog.GetPath(); // Ottieni il percorso della cartella selezionata
        LoadImagesFromFolder(folderPath); // Carica le immagini dalla cartella
    }
}

void MyFrame::LoadImagesFromFolder(const wxString& folderPath) {
    wxDir dir(folderPath);
    wxString filename;
    bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES); // Filtra per immagini

    imageFiles.clear(); // Pulisci la lista esistente
    currentImageIndex = 0; // Resetta l'indice corrente

    while (cont) {
        imageFiles.push_back(folderPath + "/" + filename); // Aggiungi il percorso dell'immagine
        cont = dir.GetNext(&filename); // Ottieni il successivo
    }

    if (!imageFiles.empty()) {
        ShowImage(imageFiles[currentImageIndex]); // Mostra la prima immagine
        slideshowTimer.Start(3000);  // Avvia il timer per 3 secondi
    }
}

void MyFrame::ShowImage(const wxString& imagePath) {
    wxImage image;
    if (image.LoadFile(imagePath)) {
        imageDisplay->SetBitmap(wxBitmap(image)); // Mostra l'immagine
        Layout(); // Aggiorna il layout
    }
}

void MyFrame::OnNextImage(wxTimerEvent& event) {
    if (imageFiles.empty()) return;

    // Passa all'immagine successiva
    currentImageIndex = (currentImageIndex + 1) % imageFiles.size();

    // Mostra la nuova immagine
    ShowImage(imageFiles[currentImageIndex]);
}
