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
	player->position = Point2(SWIDTH / 2, 100);
	//player->scale = Point(0.5f, 0.5f); // probleem met colliders en scaling.
	velocityH = walk;

	// platforms
	platform = new Platform();
	platform->position = Point2(640, 700);
	/*platform->scale = Point(1.0f, 1.0f);*/

	// create the scene 'tree'

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

// collision x, y.
bool MyScene::rectangle2rectangle()
{
	return (player->position.x < platform->position.x + platform->sprite()->size.x * platform->scale.x &&
			player->position.x + player->sprite()->size.x * player->scale.x > platform->position.x &&
			player->position.y < platform->position.y + platform->sprite()->size.y * platform->scale.y &&
			player->position.y + player->sprite()->size.y * player->scale.y > platform->position.y);
}

void MyScene::update(float deltaTime)
{
	// exit
	if (input()->getKeyUp(KeyCode::Escape))
	{
		this->stop();
	}

	// links
	if (input()->getKey(KeyCode::A))
	{
		player->position += Vector2(-velocityH, 0) * deltaTime;
	}

	// rechts
	if (input()->getKey(KeyCode::D))
	{
		player->position += Vector2(velocityH, 0) * deltaTime;
	}

	// springen
	if (input()->getKey(KeyCode::Space) && player->isGrounded)
	{
		player->acceleration += Vector2(0, -jump);
		player->isGrounded = false;
	}
	
	// gravity
	player->acceleration += Vector2(0, gravity) * deltaTime;
	if (player->acceleration.y < 0)
	{
		player->isGrounded = false;
	}

	// collision
	if (rectangle2rectangle())
	{
		float overlapY = player->position.y + player->sprite()->size.y * player->scale.y - platform->position.y;
		player->position.y -= overlapY;
		player->velocity *= 0;
		player->isGrounded = true;
	}
}
