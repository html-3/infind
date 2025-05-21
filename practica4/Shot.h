#include "Vector.h"
#include "Color.h"
#pragma once

class Shot {
public:
	double width;
	double speed = 0.02;
	bool exists = false;
	bool grows = true;
	Vector origin, end;
	Color color;
	void setDimensions(double w);
	void setColor(const Color& c);
	void setState(Vector o);
	void setEndState(Vector e);
	void updateState();
	void render() const;
	void setExist(bool value);
	void setGrow(bool value);
	bool getExists();
	double getWidth();
	Vector getOrigin();
	Vector getEnd();
};

