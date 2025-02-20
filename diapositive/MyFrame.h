#ifndef MYFRAME_H
#define MYFRAME_H

#include <wx/wx.h>
#include <wx/timer.h>
#include "Observer.h"
#include "ImageLoader.h"

class MyFrame : public wxFrame, public Observer {
private:
    wxStaticBitmap* imageDisplay;
    wxButton* selectFolderButton;
    wxTimer slideshowTimer;
    ImageLoader* imageLoader; // Nuovo oggetto per la gestione delle immagini

public:
    MyFrame(const wxString& title, ImageLoader* loader);

    void OnSelectFolder(wxCommandEvent& event);
    void OnNextImage(wxTimerEvent& event);
    void ShowImage(const wxString& imagePath);
    void Update(const wxString& imagePath) override; // Metodo Observer

    wxDECLARE_EVENT_TABLE();
};

#endif
