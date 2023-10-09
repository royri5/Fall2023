#include "Location.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <functional>
#include <map>
#include <iostream>

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

// default constructor
Location::Location()
{
    this->name = "noname";
    this->description = "no description";
    this->visited = false;
    this->neighbors = std::map<std::string, std::reference_wrapper<Location> >();
    //this->npcs = std::vector<std::reference_wrapper<NPC> >();
    //this->items = std::vector<std::reference_wrapper<Item> >();
    this->npcs = std::vector<NPC>();
    this->items = std::vector<Item>();
}

// constructor with parameters
Location::Location(std::string locName, std::string locDescription)
{
    // exception checking

    // check if name is blank
    if (locName == "")
    {
        throw std::invalid_argument("Name cannot be blank");
    }
    // check if description is blank
    if (locDescription == "")
    {
        throw std::invalid_argument("Description cannot be blank");
    }

    // instantiate object variables
    this->name = locName;
    this->description = locDescription;
    this->visited = false;
    this->neighbors = std::map<std::string, std::reference_wrapper<Location> >();
    // this->npcs = std::vector<std::reference_wrapper<NPC> >();
    // this->items = std::vector<std::reference_wrapper<Item> >();
    this->npcs = std::vector<NPC>();
    this->items = std::vector<Item>();
}

// getters
// get_name
std::string Location::get_name() const
{
    return this->name;
}

// get_description
std::string Location::get_description() const
{
    return this->description;
}

// get_visited
bool Location::get_visited() const
{
    return this->visited;
}

// get_locations
std::map<std::string, std::reference_wrapper<Location> > Location::get_locations() const
{
    return this->neighbors;
}

// get_npcs
std::vector<NPC> Location::get_npcs() const
{
    return this->npcs;
}

// get_items
std::vector<Item> Location::get_items() const
{
    return this->items;
}

// adders
//void Location::add_location(std::string direction, std::reference_wrapper<Location> location)
void Location::add_location(std::string direction, Location& location)
{
    // exception checking

    // check if direction is blank
    if (direction == "")
    {
        throw std::invalid_argument("Direction cannot be blank");
    }
    // below is copilot code
    // check if location is already in map
    if (this->neighbors.find(direction) != this->neighbors.end())
    {
        throw std::invalid_argument("Location already exists in map");
    }

    // below is copilot code
    // add location to map
    this->neighbors.insert(std::pair<std::string, std::reference_wrapper<Location> >(direction, location));
}

// add_npc
//void Location::add_npc(std::reference_wrapper<NPC> npc)
void Location::add_npc(NPC npc)
{
    // add npc to vector
    this->npcs.push_back(npc);
    //this->npcs.push_back(std::reference_wrapper<NPC>(npc));
}
// void Location::add_npc_storage(NPC npc)
// {
//     // add npc to vector
//     //this->npcs.push_back(npc);
//     this->npcs_storage.push_back(npc);
// }
// std::vector<NPC> Location::get_npcs_storage()
// {
//     return this->npcs_storage;
// }

// add_item
//void Location::add_item(std::reference_wrapper<Item>  item)
void Location::add_item(Item item)
{
    // add item to vector
    //this->items.push_back(std::reference_wrapper<Item>(item));
    this->items.push_back(item);
}
// void Location::add_item_storage(Item item)
// {
//     // add item to vector
//     this->items_storage.push_back(item);
// }
// std::vector<Item> Location::get_items_storage()
// {
//     return this->items_storage;
// }

// remove item
//void Location::remove_item(std::reference_wrapper<Item> item)
void Location::remove_item(Item& item)
{
    // remove item from vector
    // copilot code

    //this should remove the last item from inv
    // not correct but busy right now
    //this->items.erase(std::remove(this->items.begin(), this->items.end(), item), this->items.end());
    
    //this may be correct

    //I lied
    this->items.erase(std::find(this->items.begin(), this->items.end(), item));


    //note: does not remove pointer to item, just removes item from vector
    // need to manage memory accordingly
}

// set_visited
void Location::set_visited()
{
    // set visited to true
    this->visited = true;
}

// overloaded stream operator
std::ostream &operator<<(std::ostream &output, const Location &location)
{
    // iterator for npcs
    //std::vector<std::reference_wrapper<NPC>>::const_iterator npcIterator = location.npcs.begin();
    std::vector<NPC>::const_iterator npcIterator = location.npcs.begin();
    // iterator for items
    //std::vector<std::reference_wrapper<Item>>::const_iterator itemIterator = location.items.begin();
    std::vector<Item>::const_iterator itemIterator = location.items.begin();
    // iterator for neighbors
    // copilot code
    std::map<std::string, std::reference_wrapper<Location>>::const_iterator neighborIterator = location.neighbors.begin();
    // loop through npcs, items, and neighbors and add to output
    // add: if there are no npcs, items, or neighbors, say so,
    // instead of just leaving the section blank
    output << location.name << " - " << location.description << "\n\n";
    if (location.get_npcs().size() > 0)
    {
        output << "You see the following NPCs:\n";
        // loop through npcs
        while (npcIterator != location.npcs.end())
        {
            //output << "     - " << *(&((*npcIterator).get())) << "\n";
            output << "     - " << (*npcIterator) << "\n";
            //output << 
            npcIterator++;
        }
    }
    else
    {
        output << "There are no NPCs here.\n";
    }
    if (location.get_items().size() > 0)
    {
        output << "\nYou see the following Items:\n";
        // loop through items
        while (itemIterator != location.items.end())
        {
            output << "     - " << (*itemIterator) << "\n";
            itemIterator++;
        }
    }
    else
    {
        output << "There are no items here.\n";
    }
    if (location.get_locations().size() > 0)
    {
        output << "\nYou can go in the following Directions:\n";
        // loop through neighbors
        while (neighborIterator != location.neighbors.end())
        {
            // check if neighbor has been visited
            if ((*neighborIterator).second.get().visited == true)
            {
                output << "     - " << (*neighborIterator).first << " - " << (*neighborIterator).second.get().get_name() << " (Visited)\n";
            }
            else
            {
                output << "     - " << (*neighborIterator).first << " - " << (*neighborIterator).second.get().get_name() << "\n";
            }
            neighborIterator++;
        }
    }
    else
    {
        output << "There are no locations here.\n";
    }
    return output;
}

// overloaded equality operator
bool operator==(const Location &a, const Location &b)
{
    return a.get_name() == b.get_name() && a.get_description() == b.get_description() && a.get_visited() == b.get_visited() && a.get_locations() == b.get_locations() && a.get_npcs() == b.get_npcs() && a.get_items() == b.get_items();
}