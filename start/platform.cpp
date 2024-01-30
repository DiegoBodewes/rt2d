// platform.cpp

#include "platform.h"

Platform::Platform(): Entity()
{
	this->addSprite("assets/square.tga");
    this->sprite()->color = CYAN;
}

Platform::~Platform()
{
	
}

void Platform::update(float deltaTime)
{

}
