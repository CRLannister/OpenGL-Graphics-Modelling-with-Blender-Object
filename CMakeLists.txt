cmake_minimum_required(VERSION 3.12)
project(ICTC)

INCLUDE_DIRECTORIES(/usr/include/)
LINK_DIRECTORIES(/usr/lib)
set(CMAKE_CXX_STANDARD 14)

add_executable(ICTC glad.c src/main.cpp)
TARGET_LINK_LIBRARIES(ICTC dl GL GLU glfw X11 Xxf86vm Xrandr pthread Xi Xinerama Xcursor )
