#include <wx/wx.h>
#include "MyFrame.h"

// Classe dell'applicazione principale
class MyWxApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyWxApp);

bool MyWxApp::OnInit() {
    wxInitAllImageHandlers();
    MyFrame* frame = new MyFrame("My Wx App");
    frame->Show(true);
    return true;
}
