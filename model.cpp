#include <iostream>
#include <cmath>
#include "constants.h"
#include "model.h"
#include "window.h"
#include "vector2d.h"

extern GLfloat nRange;

void Model::updatePos()
{
		// if there are no bodies
		if (world.empty())
				return;
		
		for (std::vector<Body>::size_type i = 0; i != world.size(); i++)
		{
				for (std::vector<Body>::size_type j = 0; j != world.size(); j++)
				{
						if (j != i)
						{

						}
				}
		}
}

Vector2d computeGrav(Vector2d distance, float mass)
{
		Vector2d result;
		float length = distance.length();
		Vector2d unitVec = distance.makeUnitVec();
		float mag = -gravitational_const * mass / pow(length, 2);
		result.x = unitVec.x * mag;
		result.y = unitVec.y * mag;
		return result;
}	

void Model::render()
{
		glRectf(-10.0, 10.0, 10.0, -10.0);
}
