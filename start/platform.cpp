// platform.cpp

#include "platform.h"

std::vector<Platform*> Platform::allPlatforms;

Platform::Platform(): Entity()
{
	this->addSprite("assets/square.tga");
    this->sprite()->color = CYAN;
    allPlatforms.push_back(this);
}

Platform::~Platform()
{
	
}

void Platform::update(float deltaTime)
{

}
