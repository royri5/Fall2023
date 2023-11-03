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

/**
 * @class Game
 * @brief Manages the game state, player actions, and interactions with NPCs and items.
 * @author Richard Roy - richard.alex.roy@gmail.com
 * @date 10/11/23
 * 
 * The Game class is responsible for managing the overall state of the game, including the player's location, inventory, and actions.
 * It also handles interactions with NPCs (Non-Player Characters) and items in the game world. The class provides a set of member functions
 * to perform actions like moving, talking, taking items, and more.
 *
 */
class Game
{
public:
    // default constructor
    Game();

    /* World initializer methods */
    // Initializes the game world
    void create_world();
    // Sets up the command map
    std::map<std::string, std::function<void(std::vector<std::string>)> > setup_commands();
    // Returns a random location from the game world
    std::reference_wrapper<Location> random_location();

    // Main game loop
    void play();

    /* Utility methods*/
    // Converts a vector of strings to a single string
    std::string strvector_to_str(std::vector<std::string> target);

    /* Command functions */
    // Displays help menu
    void show_help(std::vector<std::string> target);
    // Talk to NPC
    void talk(std::vector<std::string> target);
    // Meet NPC
    void meet(std::vector<std::string> target);
    // Take item
    void take(std::vector<std::string> target);
    // Give item
    void give(std::vector<std::string> target);
    // Go to location
    void go(std::vector<std::string> target);
    // Show inventory
    void show_items(std::vector<std::string> target);
    // Look at current location
    void look(std::vector<std::string> target);
    // Quit game
    void quit(std::vector<std::string> target);
    // personal command functions
    // Group up with NPC
    void party(std::vector<std::string> target);
    // Kick NPC from party
    void leavePartyMember(std::vector<std::string> target);

    /* Getter methods*/
    // Command map
    std::map<std::string, void (*)(std::vector<std::string>)> get_commands() const;
    // get inventory
    std::vector<Item> get_inventory() const;
    // get current weight
    float get_current_weight() const;
    // get locations (storage)
    std::vector<Location> get_locs() const;
    // get locations (reference)
    std::vector<std::reference_wrapper<Location> > get_locations();
    // get current location
    std::reference_wrapper<Location> get_current_location() const;
    // get calories needed
    int get_calories_needed() const;
    // get value that determines if game is in progress
    bool get_game_in_progress() const;

    /* Setter methods*/
    //for testing
    void set_current_location(Location& loc);

private:
    // private variables

    // commands map
    std::map<std::string, std::function<void(std::vector<std::string>)> > commands;
    std::vector<Item> inventory; // player inventory
    float current_weight; // player current inventory weight
    std::vector<Location> locs; // vector of locations (storage)
    std::vector<std::reference_wrapper<Location>> locations; // vector of locations (reference)
    Location curr; // current location (storage)
    std::reference_wrapper<Location> current_location = curr; // current location (reference)
    int calories_needed; // amount of calories needed to win/feed the elf
    bool game_in_progress; // value that determines if game is in progress
};

#endif