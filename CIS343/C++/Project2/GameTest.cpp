
#include "Game.hpp"
#include "Location.hpp"
#include "NPC.hpp"
#include "Item.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <functional>
#include <iostream>
#include <map>
#include <iterator>

// tests

// constructor testing

// tests create_world
void test_create_world_locations_list(Game game)
{
    // print all location names
    std::vector<Location> locations = game.get_locations();
    for (int i = 0; i < locations.size(); i++)
    {
        std::cout << locations[i].get_name() << std::endl;
    }
}

// tests setup commands

// tests random_location
void test_random_location(Game game)
{
    // print current location
    std::cout << "---------------\n"
              << std::endl;
    // state test name
    std::cout << "test_random_location" << std::endl;
    std::cout << std::endl;
    std::cout << "curr: " << game.get_current_location().get_name() << std::endl;
    std::cout << "------------\n"
              << std::endl;
}

// tests play

// tests show help
void test_show_help(Game game)
{
    // print help
    std::cout << "---------------\n"
              << std::endl;
    // state test name
    std::cout << "test_show_help" << std::endl;
    std::cout << std::endl;
    game.show_help();
    std::cout << "---------\n"
              << std::endl;
}

// tests talk

// tests meet

// tests take

// tests give

// tests go
void test_go(Game game)
{
    // print current
}

// tests show items
void test_show_items(Game game)
{
    // print items
    std::cout << "---------------\n"
              << std::endl;
    // state test name
    std::cout << "test_show_items" << std::endl;
    std::cout << std::endl;
    game.show_items({"show", "items"});
    std::cout << "---------\n"
              << std::endl;
}

/// tests look
void test_look(Game game)
{
    // state test name
    std::cout << "test_look" << std::endl;
    // print
    // print line buffer to see test better
    std::cout << "---------------\n"
              << std::endl;

    game.look({"look", "at", "me"});

    // print end of test
    std::cout << "---------------\n"
              << std::endl;
}

// tests quit

// tests ____

// test ____

// main for all tests
int main(void)
{
    // constructor tests
    Game game;
    test_create_world_locations_list(game);
    test_random_location(game);
    test_show_help(game);
    // test_go(game);
    test_show_items(game);
    test_look(game);
    // test_constructor();
    // test_constructor_exception_name();
    // test_constructor_exception_description();
    //
    // // getter tests
    // te
}