#pragma once

#include <SFML/Graphics.hpp>

class Engine {
  public:
    sf::CircleShape player;
    sf::RenderWindow init();
    
    void loop(sf::RenderWindow window);
};