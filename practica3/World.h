#pragma once
#include "Box.h"
#include "Player.h"
#include "Ball.h"

class World {
public:
	Box box;
	Player player;
	Ball ball;
	
	void init();
	void draw() const;
	void updateState();
	void playerMovement(unsigned char key);
};