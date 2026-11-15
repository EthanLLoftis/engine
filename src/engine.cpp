#include "engine.h"

#include <iostream>
#include <SFML/Window.hpp>

sf::Window Engine::init() {
    std::cout << "Initializing..." << "\n";
    sf::Window window(sf::VideoMode({800, 600}), "Game Engine", sf::Style::Default, sf::State::Windowed);

    // window.setVerticalSyncEnabled(true);
    // run at 60 fps
    window.setFramerateLimit(60);

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

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                std::cout << "Moving left." << "\n";
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                std::cout << "Moving right." << "\n";
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                std::cout << "Moving up." << "\n";
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                std::cout << "Moving down." << "\n";
            }
        }
    }
}