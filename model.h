#ifndef MODEL_H
#define MODEL_H

#include "window.h"
#include "body.h"

class Model 
{
public:
		std::vector<Body> world;
		void render();
		void updatePos();
};

#endif
