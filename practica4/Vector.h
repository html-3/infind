#pragma once
#include <cmath>

struct Vector {
    double x, y;

    // Operadores membro
    Vector& operator+=(const Vector& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector& operator-=(const Vector& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector operator-() const {
        return { -x, -y };
    }

    Vector operator+(const Vector& other) const {
        return { x + other.x, y + other.y };
    }

    Vector operator-(const Vector& other) const {
        return { x - other.x, y - other.y };
    }

    Vector operator*(const Vector& other) const {
        return { x * other.x, y * other.y };
    }

    Vector operator*(double scalar) const {
        return { x * scalar, y * scalar };
    }

    double arg() const {
        return std::atan2(y, x);
    }

    inline double module() const {
        return sqrt(x * x + y * y);
    }

    inline Vector unit() const {
        auto mod = module();
        if (mod > 0.00001) return { x / mod, y / mod };
        return { x,y };
    }

    inline Vector operator*(double scalar) {
        return { x * scalar, y * scalar };
    }
};

inline Vector operator*(double scalar, const Vector& v) {
    return { v.x * scalar, v.y * scalar };
}