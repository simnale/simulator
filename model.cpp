#include <iostream>
#include <cmath>
#include "constants.h"
#include "model.h"
#include "window.h"
#include "vector2d.h"

extern GLfloat nRange;


Vector2d computeGrav(Vector2d distance, float mass)
{
		Vector2d result;
		float length = distance.length();
		Vector2d unitVec = distance.makeUnitVec();
		float mag = gravitational_const * mass / pow(length, 2);
		result.x = unitVec.x * mag;
		result.y = unitVec.y * mag;
		return result;
}

void Model::updatePos()
{
		// if there are no bodies
		if (world.empty())
				return;
		
	
		float dt = 86400.0/10;
		Vector2d new_v, new_p;
		
		for (std::vector<Body>::size_type i = 0; i != world.size(); i++)
		{
				// s = v * t
				new_p = world[i].velocity;
				new_p.multiply(dt);
				world[i].position.addVec(new_p);

				//std::cout << "position of: " << i <<  std::endl;
				//world[i].position.print();


				Vector2d iV = world[i].position;
				for (std::vector<Body>::size_type j = 0; j != world.size(); j++)
				{
						if (j != i)
						{
								Vector2d jV = world[j].position;
								jV.substractVec(iV);
								Vector2d distance = jV;
								world[i].acceleration.addVec(
										computeGrav(distance, world[j].mass));
								
						}
				}
				
				std::cout << "acceleration of: " << i << std::endl;
				world[i].acceleration.print();
				
				// v = a * t
				new_v = world[i].acceleration;
				new_v.multiply(dt);
				world[i].velocity.addVec(new_v);						
			
				//std::cout << "velocity of: " << i << std::endl;
				//world[i].velocity.print();

				world[i].acceleration.x = 0;
				world[i].acceleration.y = 0;
		}
}	

void Model::render()
{
		float radius = 400e6; // m
		float coeff = 1; // 100 / radius
		glPointSize(4.0);
		glBegin(GL_POINTS);
		for (std::vector<Body>::size_type i = 0; i != world.size(); i++)
		{
				//std::cout << world[i].position.x / coeff << world[i].position.y / coeff << std::endl;
				glVertex2f(world[i].position.x/coeff, world[i].position.y/coeff);
		}
		glEnd();
}
