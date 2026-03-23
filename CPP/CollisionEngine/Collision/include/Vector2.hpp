#pragma once

#include <cmath>

namespace eng {

    template <typename T> struct Vec2 {
        T x, y;

        Vec2() : x{0}, y{0} {}; // нач. координаты
        Vec2(T _x, T _y) : x{_x}, y{_y} {}; // вектор инициализированный с заданными координатами

        // Длина вектора
        T length() const { return std::sqrt(x * x + y * y); }

        // Оператор разыменования
        Vec2 &operator=( const Vec2 &other) {
            x = other.x;
            y = other.y;
            return *this;
        }

        // Арифметические операции над векторами
        Vec2 operator+( const Vec2 &other) const {
            return Vec2{ x + other.x, y + other.y};
        }
        Vec2 operator-( const Vec2 &other) const {
            return Vec2{ x - other.x, y - other.y};
        }

        void operator+=( const Vec2 &other) {
            x += other.x;
            y += other.y;
        }
        void operator-=( const Vec2 &other) {
            x -= other.x;
            y -= other.y;
        }

        Vec2 operator*( const T value) const { return Vec2{x * value, y * value}; }
        Vec2 operator/( const T value) const { return Vec2{x / value, y / value}; }
};
}
