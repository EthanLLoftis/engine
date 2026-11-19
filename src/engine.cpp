#include "engine.h"
#include "character.h"

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

sf::RenderWindow Engine::init() {
    std::cout << "Initializing..." << "\n";
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Game Engine", sf::Style::Default, sf::State::Windowed);

    // window.setVerticalSyncEnabled(true);
    // run at 60 fps
    window.setFramerateLimit(60);

    return window;
}

bool Engine::projInBounds(Projectile proj, sf::RenderWindow * window){
    sf::FloatRect bounds = proj.shape.getGlobalBounds();
    sf::Vector2u winSize = window->getSize();

    return bounds.position.x < 0.f ||
           bounds.position.x + bounds.size.x > static_cast<float>(winSize.x) ||
           bounds.position.y < 0.f ||
           bounds.position.y + bounds.size.y > static_cast<float>(winSize.y);

}

void Engine::handleUserInput(sf::Transformable * player) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        player->move({-1.0*10,0});
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        player->move({1.0*10,0});
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        player->move({0,-1.0*10});
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        player->move({0,1.0*10});
    }
}

void Engine::loop(sf::RenderWindow window) {
    std::cout << "Starting game engine." << "\n";

    Character player(false, "Ethan", sf::RectangleShape({20.0f, 60.0f}));

    std::vector<Projectile> projectiles; 

    sf::Clock clock;

    while(window.isOpen()) {
        sf::Time time = clock.getElapsedTime();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            Engine::handleUserInput(&player.sprite);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            {
                std::cout << "spawning projectile" << "\n";
                Projectile proj;
                proj.shape.setRadius(20.0f);
                proj.shape.setFillColor(sf::Color::Yellow);
                proj.shape.setPosition(player.sprite.getPosition());
                proj.vel = {0.0f, -1.0f};
                
                projectiles.push_back(proj);
            }

        }

        window.clear();

        for (auto it = projectiles.begin(); it != projectiles.end(); ++it){
            // if (!Engine::projInBounds(*it, &window)) {
            //     it = projectiles.erase(it);
            // }
            std::cout << "Drawing projectiles" << "\n";
            it->shape.move(it->vel * time.asSeconds());
            window.draw(it->shape);
        }

        window.draw(player.sprite);

        window.display();
    }
}