#include <iostream>
#include "window.h"
#include "vector2d.h"
#include <cmath>

float stepx = 2.0f;
float stepy = 2.0f;
float x;
float y;

Window::Window()
{
}

Window::~Window()
{
}

void Window::resize(GLsizei w, GLsizei h)
{
		GLfloat nRange = 100.0f;
		GLfloat aspectRatio;
		if (h == 0) h = 1;
		glViewport(0, 0, w, h);
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		aspectRatio = (GLfloat)w / (GLfloat)h;
		
		if (w <= h)
		{
				glOrtho(-nRange, nRange, -nRange/aspectRatio, nRange/aspectRatio, -nRange, nRange);
		}
		else
		{
				glOrtho(-nRange*aspectRatio, nRange*aspectRatio, -nRange, nRange, -nRange, nRange);
		}

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
}

void test(Vector2d a, Vector2d b)
{
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0f, 0.5f, 1.0f);
		
		glRectf(a.x, a.y, b.x, b.y);
		//glRectf(-10.0f, 10.f, 10.0f, -10.f);
		//glFlush();
}

void point(float k)
{
		x = 50.0f * sin(k);
		y = 50.0f * cos(k);

		glBegin(GL_POINTS);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(x, y, 50.0f);
		glEnd();
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
		Vector2d one(-10.0, 10.0);
		Vector2d two(10.0, -10.0);
		float k = 0.0;

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
				
				point(k);

				if (k > 3.14 * 2)
						k = 0;

				k = k + 0.01;
			   						
				// swap buffers
				window.display();
		}
}
