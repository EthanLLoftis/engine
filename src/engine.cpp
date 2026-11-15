#include "engine.h"

#include <iostream>
#include <SFML/Window.hpp>

sf::Window Engine::init() {
    std::cout << "Initializing..." << "\n";
    sf::Window window(sf::VideoMode({800, 600}), "Game Engine", sf::Style::Default, sf::State::Windowed);

    return window;
}

void Engine::loop(sf::Window window) {
    std::cout << "Starting game engine." << "\n";

    while(window.isOpen()) {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                std::cout << "Stopping game engine." << "\n";
                window.close();
            }
        }
    }
}