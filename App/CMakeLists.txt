cmake_minimum_required(VERSION 3.7)
project(ICTC)

INCLUDE_DIRECTORIES(/usr/include/)
LINK_DIRECTORIES(/usr/lib)
set(CMAKE_CXX_STANDARD 14)

file(GLOB CPP_SRC_FILES
    "CPP_files/*.cpp"
)
add_executable(ICTC main.cpp ${CPP_SRC_FILES})
TARGET_LINK_LIBRARIES(ICTC GL GLU glut X11 dl Xxf86vm Xrandr pthread Xi Xinerama Xcursor xcb)
