// Author: Richard Roy
// Date: 10/10/23

// include guard
#ifndef _LOCATION_
#define _LOCATION_

// includes
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <stdexcept>
#include <iostream>
#include "NPC.hpp"
#include "Item.hpp"

// defines location class
class Location
{
public:
    // default constructor
    Location();
    // constructor with parameters
    Location(std::string name, std::string description);

    // neighboring locations
    std::map<std::string, std::reference_wrapper<Location> >
     get_locations() const;
    // add location
    void add_location(std::string direction, Location& location);
    // add npc
    void add_npc(NPC npc);
    void add_item(Item item);
    void remove_item(Item& item);
    void remove_npc(NPC& npc);
    // set visited
    void set_visited();
    // get name
    std::string get_name() const; //
    // get description
    std::string get_description() const; //
    // get visited
    bool get_visited() const; //
    // get npcs
    std::vector<std::reference_wrapper<NPC> > get_npcs_ref();
    std::vector<NPC> get_npcs() const;
    // get items
    std::vector<std::reference_wrapper<Item> > get_items_ref();
    std::vector<Item> get_items() const;

    // overloaded stream operator
    friend std::ostream &operator<<(
        std::ostream &output, const Location &location);
    // overloaded equality operator
    friend bool operator==(const Location &a, const Location &b);
private:
    // class variables
    std::string name;
    std::string description;
    bool visited;
    // map of neighboring locations
    std::map<std::string, std::reference_wrapper<Location> > neighbors;
    // vector of NPCs
    std::vector<NPC> npcs;
    // reference wrapped vector of NPCs
    std::vector<std::reference_wrapper<NPC> > npcs_ref;
    // vector of items
    std::vector<Item> items;
    // reference wrapped vector of items
    std::vector<std::reference_wrapper<Item> > items_ref;
};

#endif