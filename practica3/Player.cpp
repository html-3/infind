#include "freeglut.h"
#include "Player.h"
#include <iostream>
#include "Color.h"
#include "Vector.h"

void Player::setDimensions(double h, double w) {
    height = h;
    width = w;
}

void Player::setColor(const Color &c) {
    color.red = c.red;
    color.green = c.green;
    color.blue = c.blue;
}

void Player::setState(const Vector& p, const Vector& v, const Vector& a) {
    pos = p;
    vel = v;
    acc = a; // Gravity in y
}

void Player::render() const {
    glColor3ub(color.red, color.green, color.blue);
    glBegin(GL_QUADS);
    glVertex2f(-width / 2 + pos.x, -height / 2 + pos.y);
    glVertex2f(width / 2 + pos.x, -height / 2 + pos.y);
    glVertex2f(width / 2 + pos.x, height / 2 + pos.y);
    glVertex2f(-width / 2 + pos.x, height / 2 + pos.y);
    glEnd();
}

void Player::updateState() {
    vel += acc;
    pos += vel;
}

// Player movement
void Player::movement(const Vector& v) {
    pos += v;
}
