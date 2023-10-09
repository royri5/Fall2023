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

// The game takes place in a world of connected Locations. The purpose of the game is to collect edible
// items and then bring them to the elf in the woods behind campus. The elf needs 500 calories of edible food
// before it will save GVSU. Each item can have 0 or more calories. If a player gives the elf something inedible
// (something with 0 calories), the elf will be displeased and will teleport the player to a random location in the
// world. The player can only carry 30 pounds at a time, so multiple trips to the elf may be needed. Once the
// elf has enough calories, it will save campus and the game will end.
// The Game class holds all the logic for a game instance. This class will hold several pieces of data. Make
// sure it has:
//
// * A map<string, Command> of commands. Note that Command here is simply an alias for a function that returns nothing and takes a std::vector<std::string>
// * A std::vector<Item> of Items the player currently has in their inventory.
// * An int that holds the current weight the player is carrying.
// * a std::vector<Location> of Locations that exist in the world
// * A variable to hold the player's current location.
// * An int to hold the number of calories the elf needs before it will save the campus
// * a bool to store whether the game is still in progress
//
// Game will adhere to the Command Pattern, instead of having a loop body with a large number of if statements, for instance (this is pseudocode, not valid C++):
//
//       command = input("What is your command?")
//       if(command == 'help'){
//          help()
//       }
//       else if(command == 'talk'){
//          talk()
//       }
//       else if(command == 'go'){
//          move()
//       }
//       ... On and on ...
//       else if(command == 'quit'){
//          quit()
//       }
//
// We can instead create a data structure that maps commands to functions. C++ makes this simple with
// dictionaries. We could for instance do something like this:
//
//      void show_help(std::vector<std::string>){
//          ... printout stuff ...
//      }
//
//      std::map<string, function<void(*) (std::vector<string>)> commands;
//      commands["show help"] = show_help;
//      commands["help"] = show_help;   //an alias for the original command
//      ... Add more commands ...
//
// In this example, the values of the map (i.e. show_help) are the names of functions. Note that we are not
// calling the functions by putting the parentheses after the name (we didn't type quit() for example); we
// are merely giving the name of the method. Now, our input loop can look something like:
//
//      command_input = input("What is your command?")
//      ... tokenize strings such that command is a string ...
//      ... the rest of the typed command will be a vector of strings ...
//      ... i.e. "take the rusty_sword" command = "take", and the ...
//      ... vector of strings will hold "the", "rusty_sword" ...
//      commands[command](tokens)
//
// Notice here that we did use the parentheses to call the function. We can do this because C++ has first-
// class functions (well, pointer references to them at least!). This simply means that a funciton can be used
// just like any other piece of data. For instance, we can store a function in a vector or map (as we did here), or
// we could pass a function as a parameter to another function.
//
// The Command Pattern allows us to abstract away all of the if statements. We merely call the function
// that corresponds with the typed command (if one exists). Note that we can check if the command is a key
// of our map with the in keyword:
//
//      if(input in commands):
//          ... do something ...
//
// The Game class will require the most code to be written. It needs:
// * A constructor that takes no parameters. The constructor will set the commands map equal to the
//   return call from our setup_commands function. It will call the create_world method. It will then
//   set default values for all other variables. Set the current location to a random location selected from
//   the random_location method.
// * a void create_world() method that creates all the Locations , Items , and NPCs in the
//   game. This function can get messy, as it will have a lot of text for names and descriptions of
//   objects. Lines of code should not be more than 72 characters long. If a line goes beyond that, you
//   should separate it into more than one line. You can do this by splitting the string:
//
//      kirkhoff_upstairs = Location("kirkhoff upstairs", "The student union.
//          There are restaurants, a store, and
//          places to congregate.")
//
// This implicitly concatenates the two strings together, so formatting this way poses no issues.
//
// In this function you will need to add all Item s and NPCs to the rooms in which they belong, as
// well as add each Location to the neighbors to which it needs to connect. Because there will be
// so much setup code, you may wish to break the function into commented regions, wherein each
// region focuses on the creation and setup of a single Location. Your game needs at least 8
// Locations. There is no requirement for how many Items and NPCs must be in each
// Location, but your game does need at least 10 Items and 5 NPCs.
// * a std::map<std::string, void(*)(std::vector<string>)> setup_commands() method.
//   This method will create a new map. The keys will be a string such as talk , give , go , etc. The
//   values of the map will be the names of the functions that should be called for each of those
//   commands. Note that we can have more than one command per function; for instance, we could
//   have both "?" and "help" correspond to a show_help method. Be sure this function returns the
//   map.
// * a Location random_location() method that selects a random Location from the locations
//   vector and returns that Location.
// * a void play() method. This is the core game loop. It should first print a message describing the
//   game, then call the method to vector all commands. Then, while the game is still in progress, it will
//   loop. In the loop, we will prompt the user for a command. The user may enter multiple words in a
//   prompt. We will split the user's input into a vector of words. We can split on spaces with code
//   tokens = user_response.split() . Once we have the tokens vector, create a variable called
//   command and set it equal to the first element in the vector. Then, remove the first element with the
//   del(tokens[0]) command. Then, use the code target = ' '.join(tokens) code to put the
//   remaining tokens together. Thus, if the user enters:
//
//      talk ball of light
//
// Then command will be equal to talk , and target will be ball of light split into a std::vector on the
// spaces.
//
// We will then call the function from the commands map by using this key. Pass target as a parameter to
// the called function. If the command does not exist in the map print a message to the user telling them so
//
// Once the loop ends (i.e. the in-progress variable is false), check if the elf got enough calories. If it did, print
// a success message and quit. Otherwise, print a failure message and quit.
// * a void show_help() method that prints out a help message and all the commands from the
//   command map's keys. This method must also post the current time. You will need to read the
//   datetime documentation to do this - https://docs.python.org/3/library/datetime.html. Print the
//   time in a nicely formatted string, but you can decide if you wish to use 12 or 24-hour time.
// * a void talk(target) method. This method will check if the provided NPC is in the current room.
//   If it is, it will call the NPC's get_message method and print the resulting message.
// * a void meet(std::vector<std::string> target) method. It will check if the NPC is in the
//   room, and if it is will ask the NPC for its description and print it.
// * a void take(std::vector<std::string> target) method. If thestd::vectorstd::string target
//   item is in the room it will remove it from the room's inventory, add it to the user's inventory, and add
//   the weight of the item to the user's carried weight.
// * a void give(std::vector<std::string> target) method. Removes thestd::vectorstd::string
//   target item (if it exists) from the user's inventory, adds it to the current location's inventory and
//   decreases the user's carried weight. The function will then check if the current location is the
//   woods. If it is, it will check if the item given was edible. If the item is edible, reduce the number of
//   calories the item has from the total the elf needs. If the item was not edible, transport the player to
//   a new location by setting the current location equal to the return from random_location.
// * a void go(std::vector<std::string> target) method. Sets the current location's visited
//   status to True. Checks if the player has over 30 weight; prints a message and returns if so.
//   Otherwise, it checks if provided direction exists in the current location's neighbor map. If so, sets
//   the current location equal to the value from the map.
// * a void show_items(std::vector<std::string> target) method. This method doesn't need
//   any parameters but has a parameter so it can be called with the same syntax as the other
//   commands. It should print all items the player is carrying, and the current amount of weight carried.
// * a look(std::vector<std::string> target) method. This method doesn't need parameters
//   either but has a parameter for the same reason as given above. This method will print the current
//   location, a vector of Item s in the location or a message indicating there are none, a vector of
//   NPC s in the room or the message "You are alone.", and a vector of directions in which the player
//   can go. If a location has been visited previously, print the direction and the location. Otherwise,
//   simply print the direction.
// * a quit(std::vector<std::string> target) method that prints a failure message and exits the
//   game.
// * two additional command functions that you design and create. You could add teleportation, magic,
//   etc

// defines game class
class Game
{
public:
    // default constructor
    Game();

    // create world
    void create_world();

    // setup commands
    std::map<std::string, void (Game::*)()> setup_commands();

    // random location
    Location& random_location();

    // play
    void play();

    // show help
    void show_help();

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
    // sell
    void sell(std::vector<std::string> target);

    // buy
    void buy(std::vector<std::string> target);

    // getters
    // get commands
    std::map<std::string, void (*)(std::vector<std::string>)> get_commands() const;

    // get inventory
    std::vector<Item> get_inventory() const;

    // get current weight
    int get_current_weight() const;

    // get locations
    //made by create world
    //split create world into 
    //create world
    //create items (per location)
    //create npcs (per location)
    //create neighbors (per location)

    //create world makes locations
    //then calls create items and create npcs
    //then calls create neighbors
    //for all locations

    std::vector<Location> get_locs() const;
    //used by everything else
    std::vector<std::reference_wrapper<Location>> get_locations();

    // get current location
    Location& get_current_location() const;

    // get calories needed
    int get_calories_needed() const;

    // get game in progress
    bool get_game_in_progress() const;

private:
    // class variables
    // commands
    // std::map<std::string, void (*)(std::vector<std::string>)> commands;
    std::map<std::string, void (Game::*)()> commands;
    // inventory
    std::vector<Item> inventory;
    // current weight
    int current_weight;
    // vector of locations
    std::vector<Location> locs;
    std::vector<std::reference_wrapper<Location>> locations;
    // current location
    Location curr;
    Location& current_location = curr;
    // calories needed
    int calories_needed;
    // game in progress
    bool game_in_progress;
};

#endif