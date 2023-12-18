// platform.cpp

#include "platform.h"

Platform::Platform(): Entity()
{
	this->addSprite("assets/square.tga");
    this->sprite()->color = WHITE;
}

Platform::~Platform()
{
	
}

void Platform::update(float deltaTime)
{

}
