cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(SlideShow)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(SlideShow main.cpp MyFrame.cpp
        ImageLoader.cpp
        ImageLoader.h
        MyTest/ImageLoaderTest.cpp)
target_link_libraries(SlideShow ${wxWidgets_LIBRARIES})
add_subdirectory(MyTest)
