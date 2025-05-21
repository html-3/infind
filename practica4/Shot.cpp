#include "freeglut.h"
#include "Shot.h"
#include <iostream>

void Shot::setDimensions(double w) {
    width = w;
}

void Shot::setColor(const Color& c) {
    color.red = c.red;
    color.green = c.green;
    color.blue = c.blue;
}

void Shot::setState(Vector o) {
    //std::cout << "bang" << std::endl;
    setExist(true);
    setGrow(true);
	origin = o;
	end = origin;
}

void Shot::setEndState(Vector e) {
    //std::cout << "bang" << std::endl;
    setGrow(false);
    end = e;
}

void Shot::updateState(){
    //std::cout << "load " << grows << std::endl;
	if(grows) end += {0, speed};
}

void Shot::render() const {
    if (exists) {
        //std::cout << "render" << std::endl;
        glColor3ub(color.red, color.green, color.blue);
        glBegin(GL_LINES);
        glLineWidth(width);
        glVertex2f(origin.x, origin.y);
        glVertex2f(end.x, end.y);
        glEnd();
    }
}

void Shot::setExist(bool value) {
    exists = value;
}

double Shot::getWidth() {
    return width;
}

bool Shot::getExists() {
    return exists;
}

Vector Shot::getOrigin() {
    return origin;
}

Vector Shot::getEnd() {
    return end;
}

void Shot::setGrow(bool value) {
    grows = value;
}
