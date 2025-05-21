#pragma once
#include "Color.h"
#include "Vector.h"

class Ball {
public:
	double radius;
	Vector pos, vel, acc;
	Color color;

	void setRadius(double r);
	void setColor(const Color &c);
	void setState(const Vector& p, const Vector& v, const Vector& a);
	void updateState();
	void render() const;
	void split();
};