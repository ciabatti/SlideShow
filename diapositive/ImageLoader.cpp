#include "ImageLoader.h"
#include <wx/dir.h>

ImageLoader::ImageLoader() : currentImageIndex(0) {}

void ImageLoader::LoadImagesFromFolder(const wxString& folderPath) {
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
        Notify(imageFiles[currentImageIndex]); // Notifica gli osservatori con la prima immagine
    }
}

wxString ImageLoader::GetNextImage() {
    if (imageFiles.empty()) return wxEmptyString;

    currentImageIndex = (currentImageIndex + 1) % imageFiles.size();
    Notify(imageFiles[currentImageIndex]); // Notifica gli osservatori
    return imageFiles[currentImageIndex];
}

bool ImageLoader::HasImages() const {
    return !imageFiles.empty();
}
