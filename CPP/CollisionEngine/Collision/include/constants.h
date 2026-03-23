#pragma once

#include <Vector2.hpp>

namespace constants {
// ускорение свободного падения
const inline eng::Vec2 gravity = {0.0f, 1000.0f};

// размеры экрана
const inline int screenWidth = 1280;
const inline int screenHeight = 720;

// область, которую нельзя покидать нашим объектам
const inline float areaRadius = 300.f;
const inline float areaX = constants::screenWidth / 2.f;
const inline float areaY = constants::screenHeight / 2.f;
} // namespace constants
