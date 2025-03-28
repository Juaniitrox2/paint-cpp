#include "vector2.hpp"
#include <cmath>

using namespace std;

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(double x, double y) {
    this->x = x;
    this->y = y;
}
Vector2::~Vector2() {}

float Vector2::magnitude() const {
    return std::sqrt(x * x + y * y);
}

float Vector2::distanceTo(const Vector2& other) const {
    return (*this - other).magnitude();
}

float Vector2::angle() const {
    return atan2(y, x);
}

bool Vector2::operator==(const Vector2& other) const {
    return x == other.x && y == other.y;
}

bool Vector2::operator>(const Vector2& other) const {
    return magnitude() > other.magnitude();
}

Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
}