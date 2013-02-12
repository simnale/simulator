#include <iostream>
#include <cmath>
#include <fstream>

#include "vector2d.h"

Vector2d::Vector2d(float a, float b) : x(a), y(b)
{
  
}

Vector2d::~Vector2d()
{

}

void Vector2d::print()
{
		std::cout << x << " " << y << std::endl;
}

void Vector2d::addVec(Vector2d vec)
{
		this->x = this->x + vec.x;
		this->y = this->y + vec.y;
}

void Vector2d::multiply(float mag)
{
		this->x = this->x * mag;
		this->y = this->y * mag;
}

float Vector2d::length()
{
		return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

Vector2d Vector2d::makeUnitVec()
{
		Vector2d result;
		float length = this->length();
		result.x = this->x / length;
		result.y = this->y / length;
		return result;
}

Vector2d Vector2d::combineVecs(Vector2d a, Vector2d b)
{
		Vector2d result;
		result.x = a.x + b.x;
		result.y = a.y + b.y;
		return result;
}
