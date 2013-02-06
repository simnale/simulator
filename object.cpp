#include "object.h"
#include "window.h"
#include <iostream>

void Object::setup_scene()
{
		Object earth;
		Object moon;
		moon.position.x = 100.0;
		std::vector<Object> objects;
		objects.push_back(earth);
		objects.push_back(moon);
		render_scene(objects);
}

void Object::render_scene(std::vector<Object> stack)
{
		draw_objects(stack);
}

void Object::draw_objects(std::vector<Object> stack)
{
		for (std::vector<Object>::size_type it = 0; it != stack.size(); it++)
		{
				glClearColor(1.0f, 0.4f, 0.4f, 0.4f);
				glRectf(10.0f, 10.0f, 10.0f, 10.0f);
				stack[it].position.print();	
		}
}

Object::Object()
{
}

Object::~Object()
{
}
