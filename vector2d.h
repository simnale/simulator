#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <fstream>

class Vector2d
{
public:
		float x, y;
		
		Vector2d(float a = 0, float b = 0);
		~Vector2d();

		void print();
		void addVec(Vector2d vec);
		void multiply(float mag);
		float length();
		Vector2d makeUnitVec();
		Vector2d combineVecs(Vector2d a, Vector2d b);
};

#endif
