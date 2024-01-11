#include <fstream>
#include <sstream>

#include "myscene.h"
#include "player.h"
#include "platform.h"

MyScene::MyScene() : Scene()
{
	// create a single instance of player in the middle of the screen.
	// the Sprite is added in Constructor of player.
	player = new Player();
	player->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	// player->scale = Point(0.5f, 0.5f); probleem met colliders en scaling.

	// platforms
	platform = new Platform();
	platform->position = Point2(640, 700);
	/*platform->scale = Point(1.0f, 1.0f);*/
	// create the scene 'tree'

	velocity = walk;
	
	// add player to this Scene as a child.
	this->addChild(player);
	this->addChild(platform);
}

MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(player);
	this->removeChild(platform);

	// delete player from the heap (there was a 'new' in the constructor)
	delete player;
	delete platform;
}

// method voor de collision x,y as.
bool MyScene::rectangle2rectangle()
{
	return (player->position.x < platform->position.x + platform->sprite()->size.x * platform->scale.x &&
			player->position.x + player->sprite()->size.x * player->scale.x > platform->position.x);
}

void MyScene::update(float deltaTime)
{
	// controls

	// links
	if (input()->getKey(KeyCode::A))
	{
		player->position += Vector2(-velocity, 0) * deltaTime;
	}

	// rechts
	if (input()->getKey(KeyCode::D))
	{
		player->position += Vector2(velocity, 0) * deltaTime;
	}

	// springen
	if (input()->getKey(KeyCode::Space))
	{
		player->position += Vector2(0, -jump);
	}

	// exit
	if (input()->getKeyUp(KeyCode::Escape))
	{
		this->stop();
	}

	// gravity
	// player->position += Vector2(0, gravity) * deltaTime;

	// collision
	if (rectangle2rectangle())
	{
		player->position.y = platform->position.y - platform->sprite()->size.y;
		std::cout << player->scale << std::endl;
	}
}
