#include "ImageLoader.h"
#include <wx/dir.h>
#include <wx/filename.h>

ImageLoader::ImageLoader() : currentImageIndex(0), loopImages(false), notificationCount(0) {} // 🔹 Inizializza notificationCount

void ImageLoader::LoadImagesFromFolder(const wxString& folderPath) {
    wxDir dir(folderPath);
    if (!dir.IsOpened()) {
        imageFiles.clear();
        currentImageIndex = 0;
        Notify(wxEmptyString);
        return;
    }

    wxString filename;
    bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES);

    imageFiles.clear();
    currentImageIndex = 0;

    while (cont) {
        imageFiles.push_back(folderPath + wxFileName::GetPathSeparator() + filename);
        cont = dir.GetNext(&filename);
    }

    if (!imageFiles.empty()) {
        Notify(imageFiles[currentImageIndex]); //  Prima immagine
    } else {
        Notify(wxEmptyString); //Nessuna immagine trovata
    }
}

wxString ImageLoader::GetNextImage() {
    if (imageFiles.empty()) {
        return wxEmptyString;
    }

    if (currentImageIndex + 1 < imageFiles.size()) {
        currentImageIndex++;
    } else if (loopImages) {
        currentImageIndex = 0;
    } else {
        return wxEmptyString;
    }
    Notify(imageFiles[currentImageIndex]); // Notifica la nuova immagine
    return imageFiles[currentImageIndex];
}

bool ImageLoader::HasImages() const {
    return !imageFiles.empty();
}

void ImageLoader::SetLoopImages(bool enable) {
    loopImages = enable;
}

void ImageLoader::Notify(const wxString& imagePath) {
    notificationCount++; //  Incrementa il contatore ogni volta che Notify() viene chiamata
    Subject::Notify(imagePath); //  Se `Subject` ha un metodo Notify(), chiama quello originale
}

int ImageLoader::GetNotificationCount() const {
    return notificationCount; //  Restituisce il numero di notifiche
}

void ImageLoader::ResetNotificationCount() {
    notificationCount = 0; //  Resetta il contatore per i test
}
