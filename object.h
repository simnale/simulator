#ifndef OBJECT_H
#define OBJECT_H

#include "vector2d.h"
#include <vector>

class Object
{
public:
		Vector2d position;
		Vector2d velocity;
		Vector2d acceleration;
		float mass;
		bool fixed; // does it move during the simulation?

		Object();
		~Object();
		void setup_scene();
		void render_scene(std::vector<Object> stack);
		void draw_objects(std::vector<Object> stack);
};

#endif
