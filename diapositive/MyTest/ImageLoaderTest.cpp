#include <gtest/gtest.h>
#include "ImageLoader.h"
#include <wx/string.h>

// Verifica che il caricamento delle immagini da una cartella valida funzioni correttamente
TEST(ImageLoaderTest, LoadImagesFromValidFolder) {
    ImageLoader loader;
    wxString testFolderPath = "../test_images";

    loader.LoadImagesFromFolder(testFolderPath);

    // Il caricamento dovrebbe rilevare almeno un'immagine
    ASSERT_TRUE(loader.HasImages());
}

// Verifica che GetNextImage() restituisca immagini diverse se disponibili
TEST(ImageLoaderTest, GetNextImage_ChangesImage) {
    ImageLoader loader;
    wxString testFolderPath = "../test_images";

    loader.LoadImagesFromFolder(testFolderPath);

    wxString firstImage = loader.GetNextImage();
    wxString secondImage = loader.GetNextImage();

    // Se ci sono almeno due immagini, devono essere diverse
    ASSERT_FALSE(firstImage.IsEmpty());
    ASSERT_FALSE(secondImage.IsEmpty());
    ASSERT_NE(firstImage, secondImage);
}


// Verifica che GetNextImage() restituisca una stringa vuota se il loop è disabilitato
TEST(ImageLoaderTest, GetNextImage_ReturnsEmptyIfNoLoop) {
    ImageLoader loader;
    wxString testFolderPath = "../test_images";

    loader.LoadImagesFromFolder(testFolderPath);
    loader.SetLoopImages(false); // Disabilita il loop

    wxString lastImage;

    while (!(lastImage = loader.GetNextImage()).IsEmpty()) {}

    wxString afterLastImage = loader.GetNextImage();
    ASSERT_TRUE(afterLastImage.IsEmpty()); // Deve restituire una stringa vuota
}

TEST(ImageLoaderTest, NotifyCalledUntilEndOfImages) {
    ImageLoader loader = ImageLoader();
    loader.SetLoopImages(false);
    wxString testFolderPath = "../test_images";  // Percorso della cartella di test

    loader.ResetNotificationCount();
    loader.LoadImagesFromFolder(testFolderPath);

    // Avanza attraverso tutte le immagini e conta quante volte GetNextImage() è stato invocato
    while (loader.GetNextImage() != wxEmptyString) {
        // Ogni chiamata a GetNextImage() incrementa il contatore delle notifiche
    }
    ASSERT_EQ(loader.GetNotificationCount(), 4);
}