#include "freeglut.h"
#include "Ball.h"
#include <iostream>
#include "Color.h"
#include "Vector.h"

void Ball::setRadius(double r) {
    //if (r < 0.1) r = 0.1;    
    radius = r;
}

void Ball::setColor(const Color &c) {
    color.red = c.red;
    color.green = c.green;
    color.blue = c.blue;
}

void Ball::setState(const Vector& p, const Vector& v, const Vector& a) {
    pos = p;
    vel = v;
    acc = a; // Gravity in y
}

void Ball::render() const {
    glColor3ub(color.red, color.green, color.blue);
    glPushMatrix();
    glTranslated(pos.x, pos.y, 0);
    glutSolidSphere(radius, 20, 20);
    glPopMatrix();
}
void Ball::updateState() {
    vel += acc;
    pos += vel;
}
