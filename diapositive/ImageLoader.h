#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <vector>
#include <wx/string.h>
#include "Subject.h"

class ImageLoader : public Subject {
private:
    std::vector<wxString> imageFiles;
    int currentImageIndex;
    bool loopImages;
    int notificationCount; //  Contatore delle notifiche

public:
    ImageLoader();

    void LoadImagesFromFolder(const wxString& folderPath);
    wxString GetNextImage();
    bool HasImages() const;
    void SetLoopImages(bool enable);

    int GetNotificationCount() const; //  Metodo per ottenere il numero di notifiche
    void ResetNotificationCount();    //  Metodo per resettare il contatore

private:
    void Notify(const wxString& imagePath);
};

#endif
