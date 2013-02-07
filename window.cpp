#include <iostream>
#include "window.h"
#include "object.h"


Window::Window()
{
}

Window::~Window()
{
}

void Window::resize(GLsizei w, GLsizei h)
{
		GLfloat aspectRatio;
		if (h == 0) h = 1;
		glViewport(0, 0, w, h);
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		aspectRatio = (GLfloat)w / (GLfloat)h;
		
		if (w <= h)
		{
				glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
		}
		else
		{
				glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0f, -1.0);
		}

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
}

void test()
{
		std::cout << "test" << std::endl;
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0f, 1.0f, 1.0f);
		glRectf(10.0f, 10.f, 10.0f, 10.f);
		glFlush();
}

void Window::run()
{
		sf::Window window(sf::VideoMode(800, 600), "Renderer", sf::Style::Default,
						  sf::ContextSettings(32, 0, 0, 3, 2));
		window.setVerticalSyncEnabled(true);
		sf::ContextSettings settings = window.getSettings();

		// init states, load resources
		resize(800, 600);


		// main loop
		bool running = true;

		while (running)
		{
				sf::Event event;
				while (window.pollEvent(event))
				{
						if (event.type == sf::Event::Closed)
						{
								running = false;
						}
						else if (event.type == sf::Event::Resized)
						{
								// window size changed
								resize(event.size.width, event.size.height);
						}
				}
				// clear buffers
				glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		   
				// draw
				Object test;
				test.setup_scene();
				test.render_scene();
			   						
				// swap buffers
				window.display();
		}
}
