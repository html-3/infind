#pragma once
#include "Vector.h"
#include "Color.h"

class Wall {
public:
	Vector limit1, limit2;
	Color color;

	void render() const;
	void setDimensions(const Vector& l1, const Vector& l2);
	void setColor(const Color& c);
	void updateColision();
};

