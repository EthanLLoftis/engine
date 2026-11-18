#pragma once 

#include <iostream>
#include <SFML/Graphics.hpp>

class Character : public sf::RectangleShape  {
    public:
        bool npc;
        std::string name;

        void attack();
        void block();
};