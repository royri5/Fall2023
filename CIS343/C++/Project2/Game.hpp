// Author: Richard Roy
// Date: 10/10/23

// include guard
#ifndef _GAME_
#define _GAME_

// includes
#include <string>
#include <vector>
#include <map>
#include "Item.hpp"
#include "NPC.hpp"
#include "Location.hpp"
#include <ctime>
#include <iostream>
#include <functional>

// defines game class
class Game
{
public:
    // default constructor
    Game();

    // create world
    void create_world();

    // setup commands
    std::map<std::string, 
    std::function<void(std::vector<std::string>)> > setup_commands();

    // random location
    std::reference_wrapper<Location> random_location();

    // play
    void play();

    // show help
    void show_help(std::vector<std::string> target);

    // convert vector of strings to string
    std::string strvector_to_str(std::vector<std::string> target);

    // talk
    // pass by reference to change current message
    void talk(std::vector<std::string> target);

    // meet
    void meet(std::vector<std::string> target);

    // take
    void take(std::vector<std::string> target);

    // give
    void give(std::vector<std::string> target);

    // go
    void go(std::vector<std::string> target);

    // show items
    void show_items(std::vector<std::string> target);

    // look
    void look(std::vector<std::string> target);

    // quit
    void quit(std::vector<std::string> target);

    // personal command functions
    // group up
    void party(std::vector<std::string> target);

    // leave party member
    void leavePartyMember(std::vector<std::string> target);

    // getters
    // get commands
    std::map<std::string, 
    void (*)(std::vector<std::string>)> get_commands() const;

    // get inventory
    std::vector<Item> get_inventory() const;

    // get current weight
    float get_current_weight() const;

    std::vector<Location> get_locs() const;
    //used by everything else
    std::vector<std::reference_wrapper<Location> 
    > get_locations();
    // for adding items/npcs to existing locations

    // get current location
    std::reference_wrapper<
    Location> get_current_location() const;

    //for testing
    void set_current_location(Location& loc);

    // get calories needed
    int get_calories_needed() const;

    // get game in progress
    bool get_game_in_progress() const;

private:
    // class variables
    // commands
    std::map<std::string, std::function<void(
        std::vector<std::string>)> > commands;

    // inventory
    std::vector<Item> inventory;
    // current weight
    float current_weight;
    // vector of locations
    std::vector<Location> locs;
    std::vector<std::reference_wrapper<Location>> locations;
    // current location
    Location curr;
    std::reference_wrapper<Location> current_location = curr;
    // calories needed
    int calories_needed;
    // game in progress
    bool game_in_progress;
};

#endif