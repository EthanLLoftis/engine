#pragma once

#include <string>
#include <SFML/Window.hpp>

class Engine {
  public:
    sf::Window init();
    
    void loop(sf::Window window);
};