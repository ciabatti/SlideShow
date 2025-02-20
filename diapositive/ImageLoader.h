#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <vector>
#include <wx/string.h>
#include "Subject.h"

class ImageLoader : public Subject {
private:
    std::vector<wxString> imageFiles;
    int currentImageIndex;

public:
    ImageLoader();

    void LoadImagesFromFolder(const wxString& folderPath);
    wxString GetNextImage();
    bool HasImages() const;
};

#endif
