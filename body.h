#ifndef BODY_H
#define BODY_H

#include "vector2d.h"

class Body
{
public:
		Vector2d postion;
		Vector2d velocity;
		Vector2d acceleration;
		bool fixed; // moving during simulation?
};

#endif
