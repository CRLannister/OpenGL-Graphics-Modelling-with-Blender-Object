INCLUDE = -I/usr/X11R6/include/
LIBDIR  = -L/usr/X11R6/lib

export LD_LIBRARY_PATH=/usr/local/lib
CC = g++                                  # change to gcc if using C
CFLAGS = $(FLAGS) $(INCLUDE)
#LIBS =	-lGL -lassimp -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor 
LIBS =	-lGL libassimp.so -lGLU libglfw3.a -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor 

TARGET = box
All:	$(TARGET)                   # change your_app.

$(TARGET): src/box.cpp
	$(CC) glad.c -o $@ $(LIBDIR) $< $(LIBS) 
