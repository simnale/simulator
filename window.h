#ifndef WINDOW_H
#define WINDOW_H

//#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

class Window
{
public:
		Window();
		~Window();

		void run();
		void resize(GLsizei w, GLsizei h);
		
};

#endif
