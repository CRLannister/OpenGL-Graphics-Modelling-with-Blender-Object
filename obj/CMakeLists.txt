cmake_minimum_required(VERSION 3.10)
project(ICTC)

INCLUDE_DIRECTORIES(/usr/include/ Native_files/include)
LINK_DIRECTORIES(/usr/lib Native_files/lib)
set(CMAKE_CXX_STANDARD 14)

file(GLOB CPP_SRC_FILES
    "CPP_files/*.cc"
)
add_executable(ICTC main.cc ${CPP_SRC_FILES})
TARGET_LINK_LIBRARIES(ICTC GL GLU glut X11 dl Xxf86vm Xrandr pthread Xi Xinerama Xcursor xcb)
