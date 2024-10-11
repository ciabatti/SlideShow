cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(MyWxApp)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(MyWxApp main.cpp MyFrame.cpp)
target_link_libraries(MyWxApp ${wxWidgets_LIBRARIES})
