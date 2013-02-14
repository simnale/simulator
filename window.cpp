#include <iostream>
#include <cmath>
#include <cstdlib>
#include "model.h"
#include "window.h"
#include "vector2d.h"


float stepx = 2.0f;
float stepy = 2.0f;
float x;
float y;
Model test;

GLfloat nRange = 100.0f;

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
				glOrtho(-nRange, nRange, -nRange/aspectRatio, nRange/aspectRatio, -nRange, nRange);
		}
		else
		{
				glOrtho(-nRange*aspectRatio, nRange*aspectRatio, -nRange, nRange, -nRange, nRange);
		}

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
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

void final_setup()
{
		Body earth;
		Body moon;
		Body a, b, c;
		earth.mass = 5.97e24; // kg
		moon.mass = 7.35e22; // kg
		moon.position.x = 3.8e8; // m
		a.position.x = -3.8e8;
		moon.velocity.y = 1.023e3; // m/s
		a.velocity.y = -0.8e3;
		a.mass = moon.mass;
		b.position.y = 3e8;
		b.velocity.x = 0.5e3;
		b.mass = moon.mass/2.0;
		c.position.y = -2.7e8;
		c.velocity.x = 0.5e3;
		c.mass = moon.mass * 0.8;
		
	   
		
		test.world.push_back(earth);
		test.world.push_back(moon);
		test.world.push_back(a);
		test.world.push_back(b);
		//test.world.push_back(c);
}

void final()
{
		test.updatePos();
		test.render();
}

void randomPos()
{
		Body *collection = new Body[150];
		for (int i = 0; i < 150; i++)
		{
				collection[i].position.x = rand() % 200 - 99;
				collection[i].position.y = rand() % 200 - 99;
				collection[i].mass = 0.05;
				test.world.push_back(collection[i]);
		}
}

void Window::run()
{
		sf::Window window(sf::VideoMode(800, 600), "Renderer", sf::Style::Default,
						  sf::ContextSettings(32, 0, 0, 3, 2));
		window.setVerticalSyncEnabled(true);
		sf::ContextSettings settings = window.getSettings();

		// init states, load resources
		resize(800, 800);


		// main loop
		bool running = true;
		Vector2d one(-10.0, 10.0);
		Vector2d two(10.0, -10.0);
		float k = 0.0;

		//final_setup();
		randomPos();

		
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
				
			
				//final();
				test.updatePos();
				test.render();
					
				// swap buffers
				window.display();
		}
}
