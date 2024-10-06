#include <fstream>
#include <sstream>

#include "myscene.h"
#include "player.h"
#include "platform.h"

MyScene::MyScene() : Scene()
{
	// Create a single instance of player in the middle of the screen.
	// The Sprite is added in Constructor of player.
	// Player
	player = new Player();
	player->position = Point2(SWIDTH / 2, 500);
	player->scale = Point(1.0f, 1.0f);
	velocityH = walk;
	this->addChild(player);

	// Create platforms + Platform position
	for (int i = 0; i < 10; ++i)
	{
		Platform *platform = new Platform();

		switch (i)
		{
		case 0:
			platform->position = Point2(640, 700);
			break;
		case 1:
			platform->position = Point2(760, 700);
			break;
		case 2:
			platform->position = Point2(520, 700);
			break;
		case 3:
			platform->position = Point2(50, 550);
			break;
		case 4:
			platform->position = Point2(170, 550);
			break;
		case 5:
			platform->position = Point2(1230, 550);
			break;
		case 6:
			platform->position = Point2(1110, 550);
			break;
		case 7:
			platform->position = Point2(640, 300);
			break;
		case 8:
			platform->position = Point2(760, 300);
			break;
		case 9:
			platform->position = Point2(520, 300);
			break;
		}
		
		platforms.push_back(platform);
		this->addChild(platform);
	}

	// platform->scale = Point(1.0f, 1.0f);
}

MyScene::~MyScene()
{
	this->removeChild(player);
	delete player;

	for (auto &platform : platforms)
	{
		this->removeChild(platform);
		delete platform;
	}
}

bool MyScene::rectangle2rectangle()
{
	// Collision: Check overlap between player and platforms.
	for (auto &platform : platforms)
	{
		if (player->position.x < platform->position.x + platform->sprite()->size.x * platform->scale.x &&
			player->position.x + player->sprite()->size.x * player->scale.x > platform->position.x &&
			player->position.y < platform->position.y + platform->sprite()->size.y * platform->scale.y &&
			player->position.y + player->sprite()->size.y * player->scale.y > platform->position.y)
		{
			return true;
		}
	}
	return false;
}

void MyScene::update(float deltaTime)
{
	// Exit
	if (input()->getKeyUp(KeyCode::Escape))
	{
		this->stop();
	}

	// Left
	if (input()->getKey(KeyCode::A))
	{
		player->position += Vector2(-velocityH, 0) * deltaTime;
	}

	// Right
	if (input()->getKey(KeyCode::D))
	{
		player->position += Vector2(velocityH, 0) * deltaTime;
	}

	// Jump
	if (input()->getKey(KeyCode::Space) && player->isGrounded)
	{
		player->velocity += Vector2(0, -jump);
		player->isGrounded = false;
	}

	// Gravity
	player->velocity += Vector2(0, gravity);
	if (player->acceleration.y < 0)
	{
		player->isGrounded = false;
	}

	// Collision + Grounded
	if (rectangle2rectangle() && player->velocity.y > 0)
	{
		float minOverlapY = FLT_MAX;
		for (auto &platform : platforms)
		{
			float overlapY = player->position.y + player->sprite()->size.y * player->scale.y - platform->position.y;
			if (abs(overlapY) < abs(minOverlapY))
			{
				minOverlapY = overlapY;
			}

		}
		player->position.y -= minOverlapY;
		player->velocity *= 0;
		player->isGrounded = true;
	}

	// camera()->position = player->position;

}