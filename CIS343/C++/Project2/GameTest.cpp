
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
void test_create_world_locations_list(Game& game)
{
    // print all location names
    std::vector<std::reference_wrapper<Location> > locations = game.get_locations();
    for (int i = 0; i < locations.size(); i++)
    {
        std::cout << locations[i].get().get_name() << std::endl;
    }
}

// tests setup commands

// tests random_location
void test_random_location(Game& game)
{
    // print current location
    std::cout << "---------------\n"
              << std::endl;
    // state test name
    std::cout << "test_random_location" << std::endl;
    std::cout << std::endl;
    std::cout << "curr: " << game.get_current_location().get().get_name() << std::endl;
    std::cout << "------------\n"
              << std::endl;
}

// tests play
void test_play(Game& game)
{
    game.play();
}

// tests show help
void test_show_help(Game& game)
{
    // print help
    std::cout << "---------------\n"
              << std::endl;
    // state test name
    std::cout << "test_show_help" << std::endl;
    std::cout << std::endl;
    game.show_help({"help"});
    std::cout << "---------\n"
              << std::endl;
}

// tests talk
void test_talk(Game& game)
{
    // check current location for an npc
    // if they dont have one, 
    // print test not applicable
    // otherwise, call the talk function
    // with the first npc's name as 
    // the argument
    std::cout << "---------------\n"
              << std::endl;
    // state test name
    std::cout << "test_talk" << std::endl;
    std::cout << std::endl;
    // check if npc exists
    std::vector<NPC> npcs = game.get_current_location().get().get_npcs();
    if (npcs.size() == 0)
    {
        std::cout << "No NPCs in this location" << std::endl;
    }
    else
    {
        // call talk function
        game.talk({npcs[0].get_name()});
        game.talk({npcs[0].get_name()});
        game.talk({npcs[0].get_name()});
        game.talk({npcs[0].get_name()});
        game.talk({npcs[0].get_name()});
        game.talk({npcs[0].get_name()});
    }
}
// tests meets
void test_meet(Game& game) 
{
    // check current location for an npc
    // if they dont have one, 
    // print test not applicable
    // otherwise, call the meet function
    // with the first npc's name as 
    // the argument
    std::cout << "---------------\n"
              << std::endl;
    // state test name
    std::cout << "test_meet" << std::endl;
    std::cout << std::endl;
    // check if npc exists
    std::vector<NPC> npcs = game.get_current_location().get().get_npcs();
    if (npcs.size() == 0)
    {
        std::cout << "No NPCs in this location" << std::endl;
    }
    else
    {
        // call meet function
        game.meet({npcs[0].get_name()});
    }   
}
// tests take
void test_take(Game& game)
{
    // check current location for an item
    // if they dont have one, 
    // print test not applicable
    // otherwise, call the take function
    // with the first item's name as 
    // the argument
    std::cout << "---------------\n"
              << std::endl;
    // state test name
    std::cout << "test_take" << std::endl;
    std::cout << std::endl;
    // check if item exists
    std::vector<Item> items = game.get_current_location().get().get_items();
    if (items.size() == 0)
    {
        std::cout << "No items in this location" << std::endl;
    }
    else
    {
        // call take function
        game.take({items[0].get_name()});
    }
    
}
// tests give

// tests go
void test_go(Game& game)
{
    // print current
}

// tests show items
void test_show_items(Game& game)
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
void test_look(Game& game)
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
    //test_play(game);
    test_talk(game);
    test_meet(game);
    test_take(game);
    test_show_items(game);
    //test_give(game);
    //test_go(game);
    //test_quit(game);
}