cmake_minimum_required(VERSION 3.10)
project(MyWxApp)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(MyWxApp main.cpp MyFrame.cpp)
target_link_libraries(MyWxApp ${wxWidgets_LIBRARIES})
