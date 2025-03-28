#pragma once

class Vector2 {
    public:
        double x;
        double y;
        
        Vector2();
        Vector2(double x, double y);
        ~Vector2();

        float magnitude() const;
        float distanceTo(const Vector2& other) const;
        float angle() const;

        bool operator >(const Vector2& other) const;
        bool operator ==(const Vector2& other) const;
        Vector2 operator +(const Vector2& other) const;
        Vector2 operator -(const Vector2& other) const;
        
    private:

};