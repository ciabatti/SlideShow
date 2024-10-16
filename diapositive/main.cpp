#include <wx/wx.h>
#include "MyFrame.h"
#include "Subject.h" 

// Classe dell'applicazione principale
class SlideShow : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(SlideShow);

bool SlideShow::OnInit() {
    wxInitAllImageHandlers();

    // Crea un oggetto Subject
    Subject* slideshowSubject = new Subject();

    // Passa il Subject al frame
    MyFrame* frame = new MyFrame("Slide Show", slideshowSubject);
    frame->Show(true);

    return true;
}
