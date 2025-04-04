#pragma once
#include "World.h"
#include "freeglut.h"
#include <iostream>

void World::init()  {
    double gravity = 0.001;
    double x1 = -0.5, y1 = 0.3, x2 = 0.5, y2 = -0.3;

    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.7, 0.7, -0.7, 0.7);
    glMatrixMode(GL_MODELVIEW);

    box.setDimensions({ x1, y1 }, { x2, y2 });
    box.setColor({ 255, 255, 255 });

    double playerWidth = 0.05, playerHeight = 0.1;
    player.setDimensions(playerHeight, playerWidth);
    player.setColor({ 200, 50, 50 });
    player.setState({ 0, y2 + playerHeight / 2 }, { 0, 0 }, { 0, 0 });

    ball.setRadius(0.02);
    ball.setColor({ 50, 50, 100 });
    ball.setState({ 0.2, 0.2 }, { 0.02, 0.01 }, { 0, -gravity });

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    box.render();
    player.render();
    ball.render();
    glutSwapBuffers();
}

void World::draw() const{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
   
    box.render();
    player.render();
    ball.render();
    glutSwapBuffers();
}

void World::updateState(){
    box.updateColision();
    player.updateState();
    ball.updateState();
}

void World::playerMovement(unsigned char key) {
    //if (key == 'w') player.movement(0.0, 0.01);
    if (key == 'a') player.movement({ -0.1, 0.0 });
    //if (key == 's') player.movement(0.0, -0.01);
    if (key == 'd') player.movement({ 0.1, 0.0 });

    if (key == 'r') player.setColor({ 255, 0, 0 });
    if (key == 'g') player.setColor({ 0, 255, 0 });
    if (key == 'b') player.setColor({ 0, 0, 255 });
}