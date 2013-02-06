CC=g++
CFLAGS=-Wall -lsfml-window -framework OpenGL

all:
	$(CC) $(CFLAGS) -o renderer main.cpp vector2d.cpp window.cpp object.cpp 
