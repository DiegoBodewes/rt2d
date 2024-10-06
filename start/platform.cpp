// platform.cpp

#include "platform.h"

//std::vector<Platform*> Platform::allPlatforms;

Platform::Platform(): Entity()
{
	this->addSprite("assets/platform.tga");
    this->sprite()->color = RED;
    //allPlatforms.push_back(this);
}

Platform::~Platform()
{
	
}

void Platform::update(float deltaTime)
{

}
