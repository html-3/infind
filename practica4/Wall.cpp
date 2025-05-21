#include "freeglut.h"
#include "Wall.h"

void Wall::setDimensions(const Vector& l1, const Vector& l2) {
	limit1 = l1;
	limit2 = l2;
};

void Wall::setColor(const Color& c) {
	color.red = c.red;
	color.green = c.green;
	color.blue = c.blue;
}

void Wall::updateColision() {
	// Acretido que vai aqui o controle da colisao com os diferentes objetos do mundo
}

void Wall::render() const {
	glColor3ub(color.red, color.green, color.blue);
	glBegin(GL_QUADS);
	glVertex2f(limit1.x, limit1.y);
	glVertex2f(limit1.x, limit2.y);
	glVertex2f(limit2.x, limit2.y);
	glVertex2f(limit2.x, limit1.y);
	glEnd();
}
