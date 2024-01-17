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
	// variables (Vectors van maken)
	float currentJumpHeight = 0;
	int velocity = 0;
	int gravity = 750;
	int walk = 500;
	int jump = 300;

	// pointers
    Player*player;
	Platform*platform; //platforms moeten in een list.
};

#endif /* SCENE00_H */
