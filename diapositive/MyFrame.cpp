#include "MyFrame.h"
#include <wx/dir.h>

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, MyFrame::OnSelectFolder)
    EVT_TIMER(wxID_ANY, MyFrame::OnNextImage) // Evento per il timer
wxEND_EVENT_TABLE()

MyFrame::MyFrame(const wxString& title, Subject* slideshowSubject)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)),
      currentImageIndex(0), slideshowTimer(this, wxID_ANY), subject(slideshowSubject) {

    selectFolderButton = new wxButton(this, wxID_ANY, "Seleziona Cartella");
    imageDisplay = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap); // Inizializza il bitmap

    // Layout
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(selectFolderButton, 0, wxALL | wxCENTER, 5);
    sizer->Add(imageDisplay, 1, wxALL | wxEXPAND, 5);
    SetSizer(sizer);

    subject->Attach(this); // Registra MyFrame come osservatore
}

void MyFrame::OnSelectFolder(wxCommandEvent& event) {
    wxDirDialog dirDialog(this, "Seleziona una cartella", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
    
    if (dirDialog.ShowModal() == wxID_OK) {
        wxString folderPath = dirDialog.GetPath();
        LoadImagesFromFolder(folderPath);
    }
}

void MyFrame::LoadImagesFromFolder(const wxString& folderPath) {
    wxDir dir(folderPath);
    wxString filename;
    bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES); 

    imageFiles.clear();
    currentImageIndex = 0;

    while (cont) {
        imageFiles.push_back(folderPath + "/" + filename); 
        cont = dir.GetNext(&filename); 
    }

    if (!imageFiles.empty()) {
        subject->Notify(imageFiles[currentImageIndex]); // Notifica agli osservatori
        slideshowTimer.Start(3000);  
    }
}

void MyFrame::OnNextImage(wxTimerEvent& event) {
    if (imageFiles.empty()) return;

    currentImageIndex = (currentImageIndex + 1) % imageFiles.size();
    subject->Notify(imageFiles[currentImageIndex]); // Notifica agli osservatori
}

void MyFrame::Update(const wxString& imagePath) {
    ShowImage(imagePath);
}

void MyFrame::ShowImage(const wxString& imagePath) {
    wxImage image;
    if (image.LoadFile(imagePath)) {
        imageDisplay->SetBitmap(wxBitmap(image));
        Layout();
    }
}
