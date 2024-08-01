#pragma once
#include "constants.h"
#include "Vector2.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace eng {
struct VerletObject {
  // вектора из формулы
  Vec2<float> positionCurrent;
  Vec2<float> positionOld;
  Vec2<float> acceleration;

  // в качестве графической библиотеки будем использовать СФМЛ
  sf::CircleShape sfShape;
  float radius;

  // не забываем сделать центр окружности центром шейпа, по умолчанию
  // им является левый верхний угол
  VerletObject(float xPos, float yPos, float _radius, sf::Color color)
      : positionCurrent{xPos, yPos}, positionOld{xPos, yPos}, radius{_radius} {
    sfShape.setRadius(radius);
    sfShape.setOrigin(radius, radius);
    sfShape.setPosition(xPos, yPos);
    sfShape.setFillColor(color);
  }


  // все в соответствии с формулой
  void updatePosition(float dt) {

    Vec2<float> velocity = positionCurrent - positionOld;

    positionOld = positionCurrent;

    positionCurrent += velocity + constants::gravity * dt * dt;

    sfShape.setPosition(positionCurrent.x, positionCurrent.y);
  }

};
}
