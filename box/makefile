INCLUDE = -I/usr/X11R6/include/
LIBDIR  = -L/usr/X11R6/lib


CC = g++                                  # change to gcc if using C
CFLAGS = $(FLAGS) $(INCLUDE)
LIBS =	-lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor 

TARGET =	box
All:	$(TARGET)                   # change your_app.

$(TARGET): src/box.cpp
	$(CC) glad.c -o $@ $(LIBDIR) $< $(LIBS) # The initial white space is a tab