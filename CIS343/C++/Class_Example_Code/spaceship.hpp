#ifndef __H_SPACESHIP__
#define __H_SPACESHIP__

#include <string>

class Spaceship {

    public:
        Spaceship();
        Spaceship(std::string name, int hp, float shield);
    private:
        std::string name;
        int hp;
        float shield;
};

#endif