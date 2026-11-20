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

bool Engine::projOutBounds(Projectile proj, sf::RenderWindow * window){
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

    const float PROJECTILE_SPEED = 600.f; 

    while(window.isOpen()) {
        float dt = clock.restart().asSeconds();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            Engine::handleUserInput(&player.sprite);

            if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                // Check which key was released using .code or .scancode
                if (keyReleased->code == sf::Keyboard::Key::Space) {
                    Projectile proj;
                    proj.shape.setRadius(20.0f);
                    proj.shape.setFillColor(sf::Color::Yellow);
                    proj.shape.setPosition(player.sprite.getPosition());
                    proj.vel = {0.0f, -1.0f};
                    
                    projectiles.push_back(proj);
                    std::cout << "projectile count: " << projectiles.size() << "\n";
                }
            }

        }

        window.clear();
        for (auto it = projectiles.begin(); it != projectiles.end() && !projectiles.empty(); ++it){
            if (Engine::projOutBounds(*it, &window)) {
                it = projectiles.erase(it);
                std::cout << "projectile count: " << projectiles.size() << "\n";
            }
            it->shape.move(it->vel * PROJECTILE_SPEED * dt);
            window.draw(it->shape);
        }

        window.draw(player.sprite);

        window.display();
    }
}