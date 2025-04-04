#include "freeglut.h"
#include "Ball.h"
#include <iostream>

void Ball::setRadius(double r) {
    radius = r;
}

void Ball::setColor(unsigned char r, unsigned char g, unsigned char b) {
    red = r;
    green = g;
    blue = b;
}

void Ball::setInitialState(double p_x, double p_y, double v_x, double v_y) {
    pos_x = p_x;
    pos_y = p_y;
    vel_x = v_x;
    vel_y = v_y;
}

void Ball::render() const {
    glColor3ub(red, green, blue);
    glPushMatrix();
    glTranslated(pos_x, pos_y, 0);
    glutSolidSphere(radius, 20, 20);
    glPopMatrix();
}
void Ball::updateState() {
    // Apply acceleration (gravity)
    vel_x += acc_x;
    vel_y += acc_y;

    // Apply velocity to position
    pos_x += vel_x;
    pos_y += vel_y;
}

void Ball::worldCollision(double world_height, double world_width) {
    double floor = -world_height / 2 + radius;
    double ceiling = world_height / 2 - radius;
    double left_wall = -world_width / 2 + radius;
    double right_wall = world_width / 2 - radius;

    // Bottom collision
    if (pos_y <= floor) {
        pos_y = floor;  // Snap to floor
        vel_y *= -bounce;  // Energy lost and direction inversion
    }

    // Top collision 
    if (pos_y >= ceiling) {
        pos_y = ceiling;
        vel_y *= -bounce; // Energy lost and direction inversion
    }

    // Left collision
    if (pos_x <= left_wall) {
        pos_x = left_wall;
        vel_x *= -bounce;  // Energy lost and direction inversion
    }

    // Right collision
    if (pos_x >= right_wall) {
        pos_x = right_wall;
        vel_x *= -bounce;
    }
}

void Ball::worldGravity(double world_gravity) {
    acc_y = -world_gravity;
}