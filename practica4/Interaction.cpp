#pragma once
#include "Interaction.h"
#include "Player.h"
#include "Ball.h"
#include "Box.h"
#include "Shot.h"
#include <iostream>

using namespace std;

void Interaction::colision(Player& player, Box& box) {
	if (player.pos.x - player.width / 2 < box.limit1.x) {
		player.setState({ box.limit1.x + player.width / 2 , player.pos.y }, { 0, 0 }, { 0, 0 });
	} else if (player.pos.x + player.width / 2 > box.limit2.x) {
		player.setState({ box.limit2.x - player.width / 2 , player.pos.y }, { 0, 0 }, { 0, 0 });
	}
}

void Interaction::colision(Ball& ball, Box& box) {
	// Left colision
	if (ball.pos.x - ball.radius < box.limit1.x) {
		ball.setState({ box.limit1.x + ball.radius , ball.pos.y }, { -ball.vel.x, ball.vel.y }, ball.acc);
	}
	// Right colision
	else if (ball.pos.x + ball.radius > box.limit2.x) {
		ball.setState({ box.limit2.x - ball.radius , ball.pos.y }, { -ball.vel.x, ball.vel.y }, ball.acc);
	}
	// Top colision
	if (ball.pos.y + ball.radius > box.limit1.y) {
		ball.setState({ ball.pos.x, box.limit1.y - ball.radius }, { ball.vel.x, -ball.vel.y }, ball.acc);
	}
	// Bottom colision
	else if (ball.pos.y - ball.radius < box.limit2.y) {
		ball.setState({ ball.pos.x, box.limit2.y + ball.radius }, { ball.vel.x, -ball.vel.y }, ball.acc);
	}
}

void Interaction::colision(Ball& ball, Wall& wall) {
	// Left collision (ball hits the left side of the wall)
	if (abs(ball.pos.x - wall.limit1.x) < ball.radius &&
		ball.pos.y <= wall.limit1.y && ball.pos.y >= wall.limit2.y && ball.vel.x > 0) {

		//cout << "left collision" << endl;
		ball.setState({ wall.limit1.x - ball.radius, ball.pos.y }, { -ball.vel.x, ball.vel.y }, ball.acc);
	}
	// Right collision (ball hits the right side of the wall)
	else if (abs(ball.pos.x - wall.limit2.x) < ball.radius &&
		ball.pos.y <= wall.limit1.y && ball.pos.y >= wall.limit2.y && ball.vel.x < 0) {

		//cout << "right collision" << endl;
		ball.setState({ wall.limit2.x + ball.radius, ball.pos.y }, { -ball.vel.x, ball.vel.y }, ball.acc);
	}
	// Top collision (ball hits the top side of the wall)
	else if (abs(ball.pos.y - wall.limit1.y) < ball.radius &&
		ball.pos.x >= wall.limit1.x && ball.pos.x <= wall.limit2.x && ball.vel.y < 0) {

		//cout << "top collision" << endl;
		ball.setState({ ball.pos.x, wall.limit1.y + ball.radius }, { ball.vel.x, -ball.vel.y }, ball.acc);
	}
	// Bottom collision (ball hits the bottom side of the wall)
	else if (abs(ball.pos.y - wall.limit2.y) < ball.radius &&
		ball.pos.x >= wall.limit1.x && ball.pos.x <= wall.limit2.x && ball.vel.y > 0) {

		//cout << "bottom collision" << endl;
		ball.setState({ ball.pos.x, wall.limit2.y - ball.radius }, { ball.vel.x, -ball.vel.y }, ball.acc);
	}
}


void Interaction::colision(Shot& shot, Box& box) {
	if (shot.end.y > box.limit1.y) {
		shot.setGrow(false);
		shot.setEndState({ shot.end.x, box.limit1.y });
	}
}

void Interaction::colision(Shot& shot, Ball& ball) {
	if (shot.origin.x - ball.pos.x < ball.radius) {
		ball.split();
	}
}

void Interaction::colision(Ball& a, Ball& b) {
	Vector delta = b.pos - a.pos;
	double dist = sqrt(delta.x * delta.x + delta.y * delta.y);
	double minDist = a.radius + b.radius;

	// Verifica se há colisão
	if (dist < minDist && dist > 0.0) {
		// Normalização do vetor de colisão
		Vector normal = delta * (1.0 / dist);

		// Separar as bolas para que não fiquem sobrepostas
		double overlap = 0.5 * (minDist - dist);
		a.pos -= normal * overlap;
		b.pos += normal * overlap;

		// Calcula a velocidade relativa ao longo da normal
		Vector relVel = b.vel - a.vel;
		double velAlongNormal = relVel.x * normal.x + relVel.y * normal.y;

		// Só atualiza se as bolas estão se aproximando
		if (velAlongNormal < 0) {
			// Reflete a velocidade ao longo da normal (colisão elástica)
			Vector impulse = normal * velAlongNormal;

			a.vel += impulse;
			b.vel -= impulse;
		}
	}
}


void Interaction::colision(Ball& ball, Shot& shot, vector<Ball>& balls) {
	Vector shotPos = shot.getEnd();
	double dx = abs(ball.pos.x - shotPos.x);
	double combinedRadius = ball.radius + shot.getWidth();

	// Detectar colision
	if (dx < combinedRadius && ball.pos.y <= shotPos.y  && shot.getExists()) {
		// Divide bolas grandes	
		if (ball.radius > 0.01) {
			double newRadius = ball.radius / 2;
			Vector offset = { newRadius, 0 };

			Vector newAcc = ball.acc;
			Vector vel1 = { 0.02, 0.02 };  // Exemplo de velocidade inicial para uma bola
			Vector vel2 = { -0.02, 0.02 };

			// Crea bolas menores
			Ball b1, b2;
			b1.setRadius(newRadius);
			b1.setColor(ball.color); // herda a cor
			b1.setState(ball.pos - offset, vel1, newAcc);

			b2.setRadius(newRadius);
			b2.setColor(ball.color);
			b2.setState(ball.pos + offset, vel2, newAcc);

			// Substituye la bola original
			auto it = find_if(balls.begin(), balls.end(), [&](const Ball& b) {
				return &b == &ball;
				});
			if (it != balls.end()) balls.erase(it);

			balls.push_back(b1);
			balls.push_back(b2);
		}
		else {
			// Si es muy chica, la remueve
			auto it = find_if(balls.begin(), balls.end(), [&](const Ball& b) {
				return &b == &ball;
				});
			if (it != balls.end()) balls.erase(it);
		}

		// Resetar o tiro
		shot.setEndState(shot.origin); // Tira o tiro da tela (por exemplo)
	}
}
