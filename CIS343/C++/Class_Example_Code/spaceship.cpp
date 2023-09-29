#include "spaceship.h"
#include <string>

Spaceship::Spaceship() {
    name = "Firefly";
    hp = 1000;
    shield = 100.0f;
}

Spaceship::Spaceship(std::string name, int hp, float shield) {
    //Spaceship::name = name;
    this->name = name;
    this->hp = hp;
    this->shield = shield;
}