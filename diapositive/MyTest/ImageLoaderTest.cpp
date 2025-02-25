#include <gtest/gtest.h>
#include "ImageLoader.h"
#include <iostream>
#include <filesystem>

TEST(ImageLoaderTest, LoadImagesAndNavigate) {
    ImageLoader loader;
    wxString testFolderPath = "../test_images";

    loader.LoadImagesFromFolder(testFolderPath);

    ASSERT_TRUE(loader.HasImages());

    wxString firstImage = loader.GetNextImage();
    ASSERT_FALSE(firstImage.IsEmpty());

    // Prendiamo la seconda immagine
    wxString secondImage = loader.GetNextImage();
    ASSERT_FALSE(secondImage.IsEmpty());
    ASSERT_NE(firstImage, secondImage); // Le immagini devono essere diverse se ce ne sono almeno due

    // Torniamo all'inizio dopo aver scansionato tutte
    for (int i = 0; i < 10; ++i) {
        loader.GetNextImage();
    }
    wxString loopedImage = loader.GetNextImage();
    ASSERT_EQ(loopedImage, firstImage); // Deve tornare alla prima immagine ciclicamente
}

