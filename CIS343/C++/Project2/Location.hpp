// Include guard to prevent multiple inclusions
#ifndef _LOCATION_
#define _LOCATION_

// Standard library includes
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <stdexcept>
#include <iostream>
#include "NPC.hpp"
#include "Item.hpp"

/**
 * @class Location
 * @brief Represents a location in a text-based adventure game.
 * @author Richard Roy - richard.alex.roy@gmail.com
 * @date 10/7/23
 * 
 * The Location class encapsulates information about a specific location
 * within the game world. It includes details such as the location's name,
 * description, visited status, neighboring locations, NPCs (Non-Playable Characters),
 * and items that can be found in that location.
 * 
 * This class provides methods to access and manipulate the attributes of a location,
 * making it a fundamental component of the game world's structure.
 */
class Location
{
public:
    // Default constructor
    Location();

    // Constructor with parameters
    Location(std::string name, std::string description);

    /* Getter methods */
    // locations
    std::map<std::string, std::reference_wrapper<Location> >get_locations() const;
    // get name
    std::string get_name() const;
    // get description
    std::string get_description() const;
    // get visited status
    bool get_visited() const;
    // get npcs reference
    std::vector<std::reference_wrapper<NPC> > get_npcs_ref();
    // get npcs
    std::vector<NPC> get_npcs() const;
    // get items reference
    std::vector<std::reference_wrapper<Item> > get_items_ref();
    // get items
    std::vector<Item> get_items() const;

    /* Adder methods */
    // add location
    void add_location(std::string direction, Location& location);
    // add npc
    void add_npc(NPC npc);
    // add item
    void add_item(Item item);

    /* Removal methods */
    // remove item
    void remove_item(Item& item);
    // remove npc
    void remove_npc(NPC& npc);

    /* Setter methods */
    // set visited
    void set_visited();
   
    /* Utility methods */
    // Overloaded stream operator
    friend std::ostream &operator<<(std::ostream &output, const Location &location);
    // Overloaded equality operator
    friend bool operator==(const Location &a, const Location &b);
private:
    // class variables
    std::string name; // name of location
    std::string description; // description of location
    bool visited; // whether or not the location has been visited
    // map of neighboring locations
    std::map<std::string, std::reference_wrapper<Location> > neighbors; 
    std::vector<NPC> npcs; // vector of NPCs
    // reference wrapped vector of NPCs
    std::vector<std::reference_wrapper<NPC> > npcs_ref; 
    std::vector<Item> items; // vector of items
    // reference wrapped vector of items
    std::vector<std::reference_wrapper<Item> > items_ref; 
};

#endif