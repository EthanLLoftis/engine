#pragma once 

#include <iostream>
#include <SFML/Graphics.hpp>

class Character  {
    private:
        bool npc{true};
        std::string name{""};

    public:
        sf::RectangleShape sprite;

        Character(bool npc, std::string name, sf::RectangleShape sprite);

        void attack();
        void block();
        std::string getName();
        void setName(std::string name);
};