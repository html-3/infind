#pragma once
#include "World.h"
#include "Player.h"
#include "Ball.h"
#include "Box.h"
#include "Shot.h"
#include <vector>

class Interaction {
	friend class World;

	static void colision(Player& player, Box& box);
	static void colision(Ball& ball, Box& box);
	static void colision(Ball& ball, Wall& wall);
	static void colision(Shot& shot, Box& box);
	static void colision(Shot& shot, Ball& ball);
	static void colision(Ball& a, Ball& b);
	static void colision(Ball& ball, Shot& shot, vector<Ball>& balls);
};

