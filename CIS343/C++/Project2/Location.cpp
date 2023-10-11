// Author: Richard Roy
// Date: 10/10/23

// Includes
#include "Location.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <functional>
#include <map>
#include <iostream>

// Default constructor
Location::Location()
{
    // Initialize default values for object variables
    this->name = "noname";
    this->description = "no description";
    this->visited = false;
    this->neighbors = std::map<std::string,  std::reference_wrapper<Location> >();
    this->npcs = std::vector<NPC>();
    this->items = std::vector<Item>();
}

// Constructor with parameters
Location::Location(std::string locName, std::string locDescription)
{
    // Exception handling for invalid name and description
    if (locName == "")
    {
        throw std::invalid_argument("Name cannot be blank");
    }
    if (locDescription == "")
    {
        throw std::invalid_argument("Description cannot be blank");
    }

    // Initialize object variables
    this->name = locName;
    this->description = locDescription;
    this->visited = false;
    this->neighbors = std::map<std::string, 
    std::reference_wrapper<Location> >();
    this->npcs = std::vector<NPC>();
    this->items = std::vector<Item>();
}

/* Getter methods */
// name
std::string Location::get_name() const
{
    return this->name;
}
// description
std::string Location::get_description() const
{
    return this->description;
}
// visited status
bool Location::get_visited() const
{
    return this->visited;
}
// locations references
std::map<std::string, std::reference_wrapper<Location> > Location::get_locations() const
{
    return this->neighbors;
}
// npcs references
std::vector<std::reference_wrapper<NPC> > Location::get_npcs_ref()
{
    // wrap npcs in reference wrappers
    // set npcs_ref to result
    this->npcs_ref = std::vector<std::reference_wrapper<NPC> >(
        this->npcs.begin(), 
        this->npcs.end());
    return this->npcs_ref;
    
   
}
// npcs
std::vector<NPC> Location::get_npcs() const
{
    return this->npcs;
}
// items references
std::vector<std::reference_wrapper<Item> > Location::get_items_ref()
{
    // wrap items in reference wrappers
    // set items_ref to result
    this->items_ref = std::vector<std::reference_wrapper<Item> >(
        this->items.begin(), 
        this->items.end());
    return this->items_ref;
}
// items
std::vector<Item> Location::get_items() const
{
    return this->items;
}

/* Adder methods*/
// add location
void Location::add_location(std::string direction, Location& location)
{
    // Exception handling for blank direction
    if (direction == "")
    {
        throw std::invalid_argument("Direction cannot be blank");
    }
    // Exception handling for invalid location
    // below is copilot code
    if (this->neighbors.find(direction) != this->neighbors.end())
    {
        throw std::invalid_argument("Location already exists in map");
    }
    // below is copilot code
    // add location to map
    this->neighbors.insert(
        std::pair<std::string,
         std::reference_wrapper<Location> >(direction, location));
}
// add npc
void Location::add_npc(NPC npc)
{
    this->npcs.push_back(npc);
}
// add item
void Location::add_item(Item item)
{
    // add item to vector
    this->items.push_back(item);
}
// remove item
void Location::remove_item(Item& item)
{
    // remove item from vector
    // copilot code
    this->items.erase(std::find(
        this->items.begin(), this->items.end(), item));
}
// remove npc
void Location::remove_npc(NPC& npc)
{
    // remove npc from vector
    // copilot code
    this->npcs.erase(std::find(
        this->npcs.begin(), this->npcs.end(), npc));
}

// set_visited
void Location::set_visited()
{
    // set visited to true
    this->visited = true;
}

/* Utility methods */
// Overloaded stream operator
std::ostream &operator<<(
    std::ostream &output, const Location &location)
{
    // iterator for npcs
    std::vector<NPC
    >::const_iterator npcIterator = location.npcs.begin();
    // iterator for items
    std::vector<Item
    >::const_iterator itemIterator = location.items.begin();
    // iterator for neighbors
    // copilot code
    std::map<std::string, std::reference_wrapper<Location> 
    >::const_iterator neighborIterator = location.neighbors.begin();
    // loop through npcs, items, and neighbors and add to output
    // if there are no npcs, items, or neighbors, say so,

    // add name and description to output
    output << location.name << " - " << location.description << "\n";
    // check for npcs
    if (location.get_npcs().size() > 0)
    {
        // nps are present
        output << "\nYou see the following NPCs:\n";
        // loop through npcs
        while (npcIterator != location.npcs.end())
        {
            // add npc to output
            output << "     - " << (*npcIterator) << "\n";
            npcIterator++;
        }
    }
    else
    {
        // no npcs present
        output << "\nThere are no NPCs here.\n";
    }
    // check for items
    if (location.get_items().size() > 0)
    {
        // items are present
        output << "\nYou see the following Items:\n";
        // loop through items
        while (itemIterator != location.items.end())
        {
            // add item to output
            output << "     - " << (*itemIterator) << "\n";
            itemIterator++;
        }
    }
    else
    {
        // no items present
        output << "\nThere are no items here.\n";
    }
    // check for neighbors
    if (location.get_locations().size() > 0)
    {
        // neighbors are present
        output << "\nYou can go in the following Directions:\n";
        // loop through neighbors
        while (neighborIterator != location.neighbors.end())
        {
            // check if neighbor has been visited
            if ((*neighborIterator).second.get().visited == true)
            {
                // neighbor has been visited
                // add neighbor to output
                output 
                << "     - " 
                << (*neighborIterator).first 
                << " - " 
                << (*neighborIterator).second.get().get_name() 
                << " (Visited)\n";
            }
            else
            {
                // neighbor has not been visited
                // add neighbor to output
                output 
                << "     - " 
                << (*neighborIterator).first 
                << " - " 
                << (*neighborIterator).second.get().get_name() << "\n";
            }
            neighborIterator++;
        }
    }
    else
    {
        // no neighbors present
        output << "There are no locations here.\n";
    }
    return output;
}

// overloaded equality operator
bool operator==(const Location &a, const Location &b)
{
    return a.get_name() == b.get_name() 
    && a.get_description() == b.get_description() 
    && a.get_visited() == b.get_visited() 
    && a.get_locations() == b.get_locations() 
    && a.get_npcs() == b.get_npcs() 
    && a.get_items() == b.get_items();
}