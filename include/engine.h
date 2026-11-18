#pragma once

#include <SFML/Graphics.hpp>

class Engine {
  public:
    sf::RenderWindow init();
    
    void loop(sf::RenderWindow window);

    void handleUserInput(sf::Transformable * player);
};