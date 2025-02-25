cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(SlideShow)

# Trova wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Eseguibile principale (solo l'app)
add_executable(SlideShow
        main.cpp
        MyFrame.cpp
        ImageLoader.cpp
        ImageLoader.h
)
target_link_libraries(SlideShow PRIVATE ${wxWidgets_LIBRARIES})