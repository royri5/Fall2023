// Author: Richard Roy
// Date: 10/10/23

#include "Location.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <functional>
#include <map>
#include <iostream>

// default constructor
Location::Location()
{
    this->name = "noname";
    this->description = "no description";
    this->visited = false;
    
    this->neighbors = std::map<std::string, 
    std::reference_wrapper<Location> >();

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
    this->neighbors = std::map<std::string, 
    std::reference_wrapper<Location> >();
    this->npcs = std::vector<NPC>();
    this->items = std::vector<Item>();
}

// getters
std::string Location::get_name() const
{
    return this->name;
}
std::string Location::get_description() const
{
    return this->description;
}
bool Location::get_visited() const
{
    return this->visited;
}
std::map<std::string, std::reference_wrapper<Location> 
> Location::get_locations() const
{
    return this->neighbors;
}
std::vector<std::reference_wrapper<NPC> > Location::get_npcs_ref()
{
    // wrap npcs in reference wrappers
    // set npcs_ref to result
    this->npcs_ref = std::vector<std::reference_wrapper<NPC> 
    >(this->npcs.begin(), this->npcs.end());
    return this->npcs_ref;
    
   
}
std::vector<NPC> Location::get_npcs() const
{
    return this->npcs;
}
std::vector<std::reference_wrapper<Item> > Location::get_items_ref()
{
    this->items_ref = std::vector<std::reference_wrapper<Item> 
    >(this->items.begin(), this->items.end());
    return this->items_ref;
}
std::vector<Item> Location::get_items() const
{
    return this->items;
}

// adders
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
    this->neighbors.insert(
        std::pair<std::string,
         std::reference_wrapper<Location> >(direction, location));
}
void Location::add_npc(NPC npc)
{
    // add npc to vector
    this->npcs.push_back(npc);
}
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

// overloaded stream operator
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
    // add: if there are no npcs, items, or neighbors, say so,
    // instead of just leaving the section blank
    output << location.name << " - " << location.description << "\n";
    if (location.get_npcs().size() > 0)
    {
        output << "\nYou see the following NPCs:\n";
        // loop through npcs
        while (npcIterator != location.npcs.end())
        {
            output << "     - " << (*npcIterator) << "\n";
            npcIterator++;
        }
    }
    else
    {
        output << "\nThere are no NPCs here.\n";
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
        output << "\nThere are no items here.\n";
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
                output 
                << "     - " 
                << (*neighborIterator).first 
                << " - " 
                << (*neighborIterator).second.get().get_name() 
                << " (Visited)\n";
            }
            else
            {
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