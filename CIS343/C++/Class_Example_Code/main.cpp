#include "spaceship.hpp"
#include <string>

int main(int argc, char** argv) {
    std::vector<Spaceship> ships;
    Spaceship a;
    ships.push(a);

    //obj creation on stack
    Spaceship a("Enterprise", 1000, 100.0f);
    //obj creation on heap
    Spaceship* b = new Spaceship("Firefly", 1000, 75.9f);

    //c++ free equivalent
    delete b;
}