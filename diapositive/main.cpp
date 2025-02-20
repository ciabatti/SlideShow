#include <wx/wx.h>
#include "MyFrame.h"
#include "ImageLoader.h"

class SlideShow : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(SlideShow);

bool SlideShow::OnInit() {
    wxInitAllImageHandlers();
    ImageLoader* imageLoader = new ImageLoader();
    MyFrame* frame = new MyFrame("Slide Show", imageLoader);
    frame->Show(true);

    return true;
}
