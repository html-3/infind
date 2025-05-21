#pragma once
#include "Box.h"
#include "Wall.h"
#include "Player.h"
#include "Ball.h"
#include "Shot.h"
#include <vector>

using namespace std;

class World {
public:
	Box box;
	Wall wall;
	Player player;
	vector<Ball> balls;
	Shot shot;
	
	
	void init();
	void draw() const;
	void updateState();
	void playerMovement(unsigned char key);
};