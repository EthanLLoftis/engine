#include "character.h"

#include <SFML/Graphics.hpp>

Character::Character(bool npc, std::string name, sf::RectangleShape sprite) : npc(npc), name(name), sprite(sprite) {};

void Character::attack() {
    std::cout << "Attacking..." << "\n";
};

void Character::block() {
    std::cout << "Blocking..." << "\n";
};

void Character::setName(std::string name) {
    this->name = name;
};

std::string Character::getName() {
    return this->name;
};