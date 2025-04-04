#pragma once

struct Vector {
	double x, y;

	// Operator overloading for +=
	Vector& operator+=(const Vector& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	// Operator overloading for -=
	Vector& operator-=(const Vector& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}
};



