#ifndef MYFRAME_H
#define MYFRAME_H

#include <wx/wx.h>
#include <wx/timer.h>
#include <vector>

class MyFrame : public wxFrame {
private:
    wxStaticBitmap* imageDisplay; // Per mostrare le immagini
    wxButton* selectFolderButton; // Pulsante per selezionare la cartella
    wxTimer slideshowTimer;       // Timer per il slideshow
    std::vector<wxString> imageFiles; // Lista delle immagini
    int currentImageIndex;        // Indice corrente dell'immagine

public:
    MyFrame(const wxString& title);
    
    void OnSelectFolder(wxCommandEvent& event); // Gestione selezione cartella
    void LoadImagesFromFolder(const wxString& folderPath); // Carica immagini
    void OnNextImage(wxTimerEvent& event); // Cambia immagine dopo 3 secondi
    void ShowImage(const wxString& imagePath); // Mostra immagine

    wxDECLARE_EVENT_TABLE();
};

#endif // MYFRAME_H
