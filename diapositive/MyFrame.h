#ifndef MYFRAME_H
#define MYFRAME_H

#include <wx/wx.h>
#include <wx/timer.h>
#include <vector>
#include "Observer.h"
#include "Subject.h"

class MyFrame : public wxFrame, public Observer {
private:
    wxStaticBitmap* imageDisplay; // Per mostrare le immagini
    wxButton* selectFolderButton; // Pulsante per selezionare la cartella
    wxTimer slideshowTimer;       // Timer per il slideshow
    std::vector<wxString> imageFiles; // Lista delle immagini
    int currentImageIndex;        // Indice corrente dell'immagine
    Subject* subject;             // Riferimento al Subject

public:
    MyFrame(const wxString& title, Subject* slideshowSubject);
    
    void OnSelectFolder(wxCommandEvent& event); // Gestione selezione cartella
    void LoadImagesFromFolder(const wxString& folderPath); // Carica immagini
    void OnNextImage(wxTimerEvent& event); // Cambia immagine dopo 3 secondi
    void ShowImage(const wxString& imagePath); // Mostra immagine
    void Update(const wxString& imagePath) override; // Metodo Observer per aggiornare l'immagine

    wxDECLARE_EVENT_TABLE();
};

#endif // MYFRAME_H
