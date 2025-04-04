#include "freeglut.h"
#include "World.h"


void World::setSize(float h, float w) {
	height = h;
	width = w;
};

void World::setGravity(float g) {
	gravity = g;
};

void World::setColor(unsigned char r, unsigned char v, unsigned char a) {
	red = r;
	blue = v;
	green = a;
}

void World::render() const {
	glColor3f(red, green, blue);
	glBegin(GL_QUADS);
	glVertex2f(-width / 2, -height / 2);
	glVertex2f(width / 2, -height / 2);
	glVertex2f(width / 2, height / 2);
	glVertex2f(-width / 2, height / 2);
	glEnd();
}
