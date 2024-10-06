/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include "player.h"
#include "platform.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	bool rectangle2rectangle();

private:
	// Variables
	int velocityH = 0;
	float gravity = 10;
	int walk = 500;
	int jump = 1000;
	
	// Pointers
	Player *player;
	std::vector<Platform *> platforms;
};

#endif /* SCENE00_H */
