cmake_minimum_required(VERSION 3.10)
project(MyTest)

enable_testing()

find_package(GTest REQUIRED)
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(..)

add_executable(Google_Tests_run
        ImageLoaderTest.cpp
        ../ImageLoader.cpp
)

target_link_libraries(Google_Tests_run
        GTest::GTest
        GTest::Main
        ${wxWidgets_LIBRARIES}
)
