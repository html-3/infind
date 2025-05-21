#pragma once
#include "World.h"
#include "Interaction.h"
#include "freeglut.h"
#include <iostream>
#include <vector>

using namespace std;

void World::init() {
    double gravity = 0.001;
    double x1 = -0.5, y1 = 0.3, x2 = 0.5, y2 = -0.3;

    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.7, 0.7, -0.7, 0.7);
    glMatrixMode(GL_MODELVIEW);

    box.setDimensions({ x1, y1 }, { x2, y2 });
    box.setColor({ 255, 255, 255 });

    wall.setDimensions({ -0.3, 0.055 }, { 0.3, 0.045 });
    wall.setColor({ 50, 50, 100 });

    double playerWidth = 0.05, playerHeight = 0.1;
    player.setDimensions(playerHeight, playerWidth);
    player.setColor({ 200, 50, 50 });
    player.setState({ 0, y2 + playerHeight / 2 }, { 0, 0 }, { 0, 0 });

    vector<Vector> ball_spawns = { { 0.2, 0.2 }, { 0.1, 0.2 }, { 0.0, 0.2 }, { -0.1, 0.2 }, { -0.2, 0.2 } };
    vector<Vector> ball_vels = {{ 0.02, 0.01 }, { -0.02, 0.01 }};
    int ball_quant = 5;
    for (int i = 0; i < ball_quant; i++) {
        Ball ball;
        ball.setRadius(0.02);
        ball.setColor({ 50, 50, 100 });
        ball.setState(ball_spawns[i % ball_spawns.size()], ball_vels[i % ball_vels.size()], {0, -gravity});
        balls.push_back(ball);
    }

    shot.setColor({ 252, 177, 3 });
    shot.setDimensions(0.01);

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    box.render();
    wall.render();
    player.render();
    for (const Ball& ball : balls) ball.render();
    shot.render();
    glutSwapBuffers();
}

void World::draw() const{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
   
    box.render();
    wall.render();
    player.render();
    for (const Ball& ball : balls) ball.render();
    shot.render();
    glutSwapBuffers();
}

void World::updateState(){
    box.updateColision();
    player.updateState();
    for (Ball& ball : balls) ball.updateState();
    shot.updateState();

    Interaction::colision(player, box);
    for (Ball& ball : balls) Interaction::colision(ball, box);
    for (Ball& ball : balls) Interaction::colision(ball, wall);
    Interaction::colision(shot, box);
    for (size_t i = 0; i < balls.size(); ++i) {
        for (size_t j = i + 1; j < balls.size(); ++j) {
            Interaction::colision(balls[i], balls[j]);
        }
    }
    for (size_t i = 0; i < balls.size(); ++i) {
        Interaction::colision(balls[i], shot, balls);
    }
}

void World::playerMovement(unsigned char key) {
    //if (key == 'w') player.movement(0.0, 0.01);
    if (key == 'a') player.movement({ -0.03, 0.0 });
    //if (key == 's') player.movement(0.0, -0.01);
    if (key == 'd') player.movement({ 0.03, 0.0 });
    if (key == ' ') shot.setState({ player.pos.x, player.pos.y - player.height / 2 });

    if (key == 'r') player.setColor({ 255, 0, 0 });
    if (key == 'g') player.setColor({ 0, 255, 0 });
    if (key == 'b') player.setColor({ 0, 0, 255 });
    
}