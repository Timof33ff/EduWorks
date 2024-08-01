#include "include/constants.h"
#include "src/game.cpp"
#include "include/Random.h"
#include "include/Vector2.hpp"
#include <SFML/System.hpp>


int main() {

  // создаем окно
  sf::RenderWindow window(sf::VideoMode(constants::screenWidth, constants::screenHeight), "Verlet");
  window.setVerticalSyncEnabled(1);

  // создаем 'движок'
  eng::Game game(&window);

  // та самая область, которую нельзя покидать
  sf::CircleShape area;
  area.setOrigin(constants::areaRadius, constants::areaRadius);
  area.setPosition(constants::areaX, constants::areaY);
  area.setRadius(constants::areaRadius);
  area.setFillColor(sf::Color::White);
  area.setPointCount(200);

  // координаты x | y
  sf::Vector2i position;

  // для получения Delta t
  sf::Clock deltaClock;
  sf::Time dt;
  while (window.isOpen()) {

    // закрываем окно, если мы его закрываем (обычно, нажимая на крестик в углу)
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // будем генерировать объекты по нажатию ПКМ в месте, где находится курсор
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
      position = sf::Mouse::getPosition(window);

      // добавляем тело
      game.addObject(position.x, position.y, eng::getRandomInt(5, 30),
                     sf::Color(eng::getRandomInt(0, 255),
                               eng::getRandomInt(0, 255),
                               eng::getRandomInt(0, 255)));
    }


    window.clear();
    // сначала рисуем область, потом уже объекты, иначе мы их не увидим
    window.draw(area);
    game.update(dt.asSeconds());
    // отображаем что получилось
    window.display();

    // записываем время итерации
    dt = deltaClock.restart();
  }
  return 0;
}
