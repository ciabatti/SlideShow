#include "MyFrame.h"

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, MyFrame::OnSelectFolder)
    EVT_TIMER(wxID_ANY, MyFrame::OnNextImage)
wxEND_EVENT_TABLE()

MyFrame::MyFrame(const wxString& title, ImageLoader* loader)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)),
      slideshowTimer(this, wxID_ANY), imageLoader(loader) {

    selectFolderButton = new wxButton(this, wxID_ANY, "Seleziona Cartella");
    imageDisplay = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(selectFolderButton, 0, wxALL | wxCENTER, 5);
    sizer->Add(imageDisplay, 1, wxALL | wxEXPAND, 5);
    SetSizer(sizer);

    imageLoader->Attach(this); // Registra MyFrame come osservatore
}

void MyFrame::OnSelectFolder(wxCommandEvent& event) {
    wxDirDialog dirDialog(this, "Seleziona una cartella", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

    if (dirDialog.ShowModal() == wxID_OK) {
        wxString folderPath = dirDialog.GetPath();
        imageLoader->LoadImagesFromFolder(folderPath);

        if (imageLoader->HasImages()) {
            slideshowTimer.Start(3000);
        }
    }
}

void MyFrame::OnNextImage(wxTimerEvent& event) {
    if (imageLoader->HasImages()) {
        imageLoader->GetNextImage(); // Notifica direttamente gli osservatori
    }
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
