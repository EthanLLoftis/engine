#include "engine.h"

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

sf::RenderWindow Engine::init() {
    std::cout << "Initializing..." << "\n";
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Game Engine", sf::Style::Default, sf::State::Windowed);

    // window.setVerticalSyncEnabled(true);
    // run at 60 fps
    window.setFramerateLimit(60);

    return window;
}

void Engine::loop(sf::RenderWindow window) {
    std::cout << "Starting game engine." << "\n";

    sf::RectangleShape player({20.0f, 60.0f});

    while(window.isOpen()) {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                player.move({-1.0*10,0});
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                player.move({1.0*10,0});
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                player.move({0,-1.0*10});
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                player.move({0,1.0*10});
            }
        }

        window.clear();

        window.draw(player);

        window.display();
    }
}