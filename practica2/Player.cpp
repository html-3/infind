#include "freeglut.h"
#include "Player.h"
#include <iostream>

void Player::setRadius(double r) {
    radius = r;
}

void Player::setColor(unsigned char r, unsigned char g, unsigned char b) {
    red = r;
    green = g;
    blue = b;
}

void Player::render() const {
    glColor3ub(red, green, blue);
    glPushMatrix();
    glTranslated(pos_x, pos_y, 0);
    glutSolidSphere(radius, 20, 20);
    glPopMatrix();
}

void Player::updateState() {
    vel_x = acc_x + vel_x * 0.9;
    vel_y += acc_y;
    pos_x += vel_x;
    pos_y += vel_y;
}

// Player movement
void Player::movement(double v_x, double v_y) {
    pos_x += v_x;
    pos_y += v_y;
}

void Player::worldCollision(double world_height, double world_width) {
    if (pos_y - radius <= -world_height / 2) { // Bottom collision
        pos_y = -world_height / 2 + radius;
        vel_y *= -bounce; // Energy lost and direction inversion
        
        if (vel_y < 0.002) vel_y = 0.0; // Stop infinite bouncing
        
    }
    if (pos_y + radius >= world_height / 2) { // Top collision
        pos_y = world_height / 2 - radius;
        
    }
    if (pos_x - radius <= -world_width / 2) { // Left collision
        pos_x = -world_width / 2 + radius;
        acc_x = 0;
    }
    if (pos_x + radius >= world_width / 2) { // Right collision
        pos_x = world_width / 2 - radius;
        acc_x = 0;
    }
}

void Player::worldGravity(double world_gravity) {
    vel_y -= world_gravity;
}
