#pragma once
#include "character.h"

#include <SFML/Graphics.hpp>

class Engine {
  public:
    sf::RenderWindow init();
    
    void loop(sf::RenderWindow window);

    void handleUserInput(sf::Transformable * player);

    bool projInBounds(Projectile proj, sf::RenderWindow * window);
};