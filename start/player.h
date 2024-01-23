// player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>

class Player: public Entity {
public:
	Player();
	virtual ~Player();
	virtual void update(float deltaTime);

	Vector2 velocity;
	Vector2 acceleration;
	bool isGrounded;

	// void movement(float deltaTime);
	
private:
	/* add your private declarations */
};

#endif /* PLAYER_H */
