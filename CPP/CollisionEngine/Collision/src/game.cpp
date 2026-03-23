#pragma once
#include "constants.h"
#include "Vector2.hpp"
#include "VerletObject.hpp"
#include <SFML/Window.hpp>
#include <vector>
#include <random>

namespace eng{
    class Game {

        private:
        //в массиве храним объекты движка
        std::vector<VerletObject *> objects;

        // указатель на окно, в котором мы будем показывать тела
        sf::RenderWindow *window;

        // так обновляем позицию им всем
        void updatePositions(float dt) {

            for (auto *object : objects) {
            object->updatePosition(dt);
            solveCollisions();
            }
        }

        // так не даем объекту покидать разрешенную область
        void applyConstraint() {

            const Vec2 centerPosition{constants::areaX, constants::areaY};

            // для каждого объекта
            for (auto *object : objects) {
                // считаем радиус-вектор от центра допустимой области к объекту
                // ищем его модуль
                const Vec2 vecToObj = object->positionCurrent - centerPosition;
                const float distToObj = vecToObj.length();

                // если объект выходит за границы области
                if (distToObj > constants::areaRadius - object->radius) {

                    // берем единичный вектор (направление от ц. области к ц. объекта)
                    const Vec2<float> normalized = vecToObj / distToObj;
                    // обновляем позицию так, чтобы наш объект был внутри области
                    // по-сути, мы двигаем его ближе к центру области по прямой, проходящей
                    // через центр объекта и центр области
                    object->positionCurrent =
                        centerPosition +
                        normalized * (constants::areaRadius - object->radius);
                }
            }
        }

        void solveCollisions() {
        // перебираем все пары объектов
            for (int i = 0; i < objects.size(); ++i) {
                for (int j = 0; j < objects.size(); ++j) {
                    // самому с собой столкнуться невозможно
                    if (j == i)
                        continue;

                    // вектор от центра первой окр. к центру второй
                    Vec2<float> collisionAxis =
                        objects[i]->positionCurrent - objects[j]->positionCurrent;

                    // если расстояние между ними больше, чем сумма радиусов
                    // то они не контактируют
                    const float dist = collisionAxis.length();
                    if (dist > objects[i]->radius + objects[j]->radius)
                        continue;

                    // единичная версия нашего вектора от ц. первой окр. к ц. второй окр
                    Vec2<float> normalized = collisionAxis / dist;
                    // расстояние, на которое нам нужно отодвинуть друг от друга окружности
                    // чтобы одна не была в другой
                    const float delta = objects[i]->radius + objects[j]->radius - dist;

                    // рассталкиваем их вдоль прямой, проходящей через их центры
                    // соблюдая некое подобие закона сохранения импульса
                    float weightDiff =
                        objects[j]->radius / (objects[i]->radius + objects[j]->radius);
                    objects[i]->positionCurrent += normalized * delta * weightDiff;
                    objects[j]->positionCurrent -= normalized * delta * (1 - weightDiff);
                }
            }
        }

        public:
          Game(sf::RenderWindow *_window) : window{_window} {};

            void addObject(float xPos, float yPos, float radius,
                            sf::Color color = sf::Color(sf::Color::Blue)) {
                VerletObject *obj = new VerletObject(xPos, yPos, radius, color);
                    objects.push_back(obj);
            }

            void update(float dt) {
                applyConstraint();
                updatePositions(dt);

                for (auto *object : objects) {
                    window->draw(object->sfShape);
                }
            }
    };

    inline int getRandomInt(int l, int r) {
        std::random_device rd;
        std::uniform_int_distribution<int> gen(l, r);
        return gen(rd);
    }
}
