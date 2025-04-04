#pragma once
#include "Color.h"
#include "Vector.h"

class Player {
public:
	double width;
	double height;
	Vector pos, vel, acc;
	Color color;

	void setDimensions(double h, double w);
	void setColor(const Color &c);
	void setState(const Vector& p, const Vector& v, const Vector& a);
	void updateState();
	void render() const ;
	void movement(const Vector& v);
};