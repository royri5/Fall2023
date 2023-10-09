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

// Each Location represents a place on campus that may be visited. A location holds a name, a description,
// a bool that indicates if it has been yet visited, a map of neighbors, a vector of NPCs, and a vector of items.
// The neighbors map will have a key that is a direction (a string), that refers to a Location as its value. For
// instance, if we have a Location called zumberg and another Location called kirkhoff, zumberg
// would have a map entry "west" that holds kirkhoff . We then want kirkhoff to hold in its map a key-
// value pair of "east" that refers to zumberg. If we want to have two locations attached such that the player
// can enter but not exit the way they came, we can merely leave the entry off one of the objects. For instance,
// we could have a portal Location that has a "through" key pointing to zumberg but no corresponding
// key-value pair in the zumberg neighbor map.
//
// Location must implement:
// * A constructor that takes a name and a description.
// * A std::map<string, Location> get_locations() function that returns the neighbors map.
// * A void add_location(string direction, Location location) method. This function will
//  add the location into the map with the provided direction string. If the string is blank, raise an
//  exception. If the key already exists in the map, raise an exception.
// * A void add_npc(NPC npc) method for adding an NPC to the Location's vector, and a
//   std::vector<Item> get_items() method to return the Items.
// * A void set_visited() method that changes the visited variable to true. Once a location is
//   visited, it can no longer be false. Also, include a bool get_visited() function for checking if the location has been visited.
// * An overloaded stream operator that returns a string in the form of
//   Padnos Hall - Lots of science labs are in this building.
//
//   You see the following NPCs:
//      - Troll
//      - Talking pumpkin
//
//   You see the following Items:
//      - Cookie (10 calories) - .5 pounds - A delicious M&M cookie.
//      - Rusty Nail (0 calories) - 1 lb - A rusty nail (I hope you've had a tetanus shot).
//
//   You can go in the following Directions:
//      - East - Zumberge (Visited)
//      - North - Unknown

// defines location class
class Location
{
public:
    // default constructor
    Location(); //
    // constructor with parameters
    Location(std::string name, std::string description); //

    // neighboring locations
    std::map<std::string, Location> get_locations() const; //

    std::map<std::string, std::reference_wrapper<Location>> get_ref_locations() const;

    // add location
    // reference wrapped?
    void add_ref_location(std::string direction, Location &location); //

    void add_location(std::string direction, Location location);

    // add npc
    // reference wrapped
    void add_ref_npc(NPC &npc); //

    //void set_ref_npc(std::vector<NPC> npcs);
    void set_ref_npc(std::vector<std::reference_wrapper<NPC>> setnpcs);

    void add_npc(NPC npc);

    // add item
    // reference wrapped
    void add_ref_item(Item &item); //

    //void set_ref_item(std::vector<Item> items);
    void set_ref_item(std::vector<std::reference_wrapper<Item> > setitems);

    void add_item(Item item);

    void remove_item(Item item);

    void remove_ref_item(Item &item);

    // set visited
    void set_visited();

    // get name
    std::string get_name() const; //

    // get description
    std::string get_description() const; //

    // get visited
    bool get_visited() const; //

    // get npcs
    std::vector<NPC> get_npcs() const; //

    // get ref npcs
    std::vector<std::reference_wrapper<NPC>> get_ref_npcs() const; //

    // get items
    std::vector<Item> get_items() const; //

    // get ref items
    std::vector<std::reference_wrapper<Item>> get_ref_items() const; //

    // overloaded stream operator
    friend std::ostream &operator<<(std::ostream &output, const Location &location);
    // overloaded equality operator
    friend bool operator==(const Location &a, const Location &b);

private:
    // class variables
    std::string name;
    std::string description;
    bool visited;

    // map of neighboring locations
    // change to be a reference wrapper
    std::map<std::string, Location> neighbors;

    // ref neighbors
    std::map<std::string, std::reference_wrapper<Location>> ref_neighbors;

    // vector of NPCs
    // change to be a reference wrapper
    std::vector<NPC> npcs;

    // ref npcs
    std::vector<std::reference_wrapper<NPC>> ref_npcs;

    // vector of items
    // change to be a reference wrapper
    std::vector<Item> items;

    // ref items
    std::vector<std::reference_wrapper<Item>> ref_items;
};

#endif