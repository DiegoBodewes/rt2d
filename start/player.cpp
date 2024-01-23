// player.cpp

#include "player.h"

Player::Player(): Entity()
{
	this->addSprite("assets/square.tga");
    this->sprite()->color = RED;
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
    this->velocity += this->acceleration * deltaTime;
    this->position += this->velocity * deltaTime;
    this->acceleration *= 0;
}
