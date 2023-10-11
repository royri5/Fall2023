#include "Location.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <functional>
#include <map>
#include <iostream>

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

/**
 * @brief Default constructor for the Location class.
 * 
 * Initializes a new Location object with default values for all its member variables.
 * 
 * @param None
 * @return None (Constructor)
 * 
 * Member Variables Initialized:
 * - `name`: Set to "noname" to indicate an unnamed location.
 * - `description`: Set to "no description" to indicate an undescribed location.
 * - `visited`: Set to false to indicate the location has not been visited.
 * - `neighbors`: Initialized as an empty std::map for storing neighboring locations.
 * - `npcs`: Initialized as an empty std::vector for storing NPCs in the location.
 * - `items`: Initialized as an empty std::vector for storing items in the location.
 */
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

/**
 * @brief Parameterized constructor for the Location class.
 * 
 * Initializes a new Location object with the given name and description. 
 * Validates the input parameters and throws exceptions for invalid values.
 * 
 * @param locName The name of the location. Cannot be an empty string.
 * @param locDescription The description of the location. Cannot be an empty string.
 * @return None (Constructor)
 * 
 * @throws std::invalid_argument If either `locName` or `locDescription` is an empty string.
 * 
 * Member Variables Initialized:
 * - `name`: Set to the value of `locName`.
 * - `description`: Set to the value of `locDescription`.
 * - `visited`: Set to false to indicate the location has not been visited.
 * - `neighbors`: Initialized as an empty std::map for storing neighboring locations.
 * - `npcs`: Initialized as an empty std::vector for storing NPCs in the location.
 * - `items`: Initialized as an empty std::vector for storing items in the location.
 */
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

/**
 * @brief Getter method for the `name` member variable.
 * 
 * Retrieves the name of the Location object.
 * 
 * @param None
 * @return std::string The name of the location.
 */
std::string Location::get_name() const
{
    return this->name;
}

/**
 * @brief Getter method for the `description` member variable.
 * 
 * Retrieves the description of the Location object.
 * 
 * @param None
 * @return std::string The description of the location.
 */
std::string Location::get_description() const
{
    return this->description;
}

/**
 * @brief Getter method for the `visited` member variable.
 * 
 * Retrieves the visited status of the Location object.
 * 
 * @param None
 * @return bool The visited status of the location. Returns `true` if visited, `false` otherwise.
 */
bool Location::get_visited() const
{
    return this->visited;
}

/**
 * @brief Getter method for the `neighbors` member variable.
 * 
 * Retrieves a map containing the neighboring locations of the current Location object.
 * The keys in the map are the directions (e.g., "north", "south", etc.), and the values are references to the neighboring Location objects.
 * 
 * @param None
 * @return std::map<std::string, std::reference_wrapper<Location>> A map containing the neighboring locations.
 */
std::map<std::string, std::reference_wrapper<Location> > Location::get_locations() const
{
    return this->neighbors;
}

/**
 * @brief Getter method for NPC references in the current Location.
 * 
 * Retrieves a vector containing reference wrappers to the NPC objects present in the current Location.
 * This allows for direct manipulation of the NPCs in the Location.
 * 
 * @param None
 * @return std::vector<std::reference_wrapper<NPC>> A vector containing reference wrappers to the NPCs.
 * 
 */
std::vector<std::reference_wrapper<NPC> > Location::get_npcs_ref()
{
    // wrap npcs in reference wrappers
    // set npcs_ref to result
    this->npcs_ref = std::vector<std::reference_wrapper<NPC> >(
        this->npcs.begin(), 
        this->npcs.end());
    return this->npcs_ref;
}

/**
 * @brief Getter method for NPCs in the current Location.
 * 
 * Retrieves a vector containing the NPC objects present in the current Location.
 * 
 * @param None
 * @return std::vector<NPC> A vector containing the NPCs.
 */
std::vector<NPC> Location::get_npcs() const
{
    return this->npcs;
}

/**
 * @brief Getter method for item references in the current Location.
 * 
 * Retrieves a vector containing reference wrappers to the Item objects present in the current Location.
 * This allows for direct manipulation of the items in the Location.
 * 
 * @param None
 * @return std::vector<std::reference_wrapper<Item>> A vector containing reference wrappers to the items.
 */
std::vector<std::reference_wrapper<Item> > Location::get_items_ref()
{
    // wrap items in reference wrappers
    // set items_ref to result
    this->items_ref = std::vector<std::reference_wrapper<Item> >(
        this->items.begin(), 
        this->items.end());
    return this->items_ref;
}

/**
 * @brief Getter method for items in the current Location.
 * 
 * Retrieves a vector containing copies of the Item objects present in the current Location.
 * This does not allow for direct manipulation of the items in the Location, unlike get_items_ref().
 * 
 * @param None
 * @return std::vector<Item> A vector containing copies of the items.
 */
std::vector<Item> Location::get_items() const
{
    return this->items;
}

/* Adder methods*/

/**
 * @brief Adds a neighboring Location to the current Location.
 * 
 * This method associates a given Location object with a specific direction string.
 * It checks for invalid inputs and throws exceptions accordingly.
 * 
 * @param direction A string representing the direction to the new Location (e.g., "north", "south").
 * @param location A reference to the Location object to be added as a neighbor.
 * @return void
 * 
 * @exception std::invalid_argument Thrown if the direction string is empty.
 * @exception std::invalid_argument Thrown if the direction already exists in the neighbors map.
 */
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

/**
 * @brief Adds an NPC (Non-Player Character) to the current Location.
 * 
 * This method appends a given NPC object to the vector of NPCs present in the Location.
 * 
 * @param npc An NPC object to be added to the Location.
 * @return void
 */
void Location::add_npc(NPC npc)
{
    this->npcs.push_back(npc);
}

/**
 * @brief Adds an Item to the current Location.
 * 
 * This method appends a given Item object to the vector of Items present in the Location.
 * 
 * @param item An Item object to be added to the Location.
 * @return void
 */
void Location::add_item(Item item)
{
    // add item to vector
    this->items.push_back(item);
}

/**
 * @brief Removes an Item from the current Location.
 * 
 * This method removes a specified Item object from the vector of Items present in the Location.
 * 
 * @param item A reference to the Item object to be removed from the Location.
 * @return void
 */
void Location::remove_item(Item& item)
{
    // remove item from vector
    // copilot code
    this->items.erase(std::find(
        this->items.begin(), this->items.end(), item));
}

/**
 * @brief Removes an NPC from the current Location.
 * 
 * This method removes a specified NPC object from the vector of NPCs present in the Location.
 * 
 * @param npc A reference to the NPC object to be removed from the Location.
 * @return void
 */
void Location::remove_npc(NPC& npc)
{
    // remove npc from vector
    // copilot code
    this->npcs.erase(std::find(
        this->npcs.begin(), this->npcs.end(), npc));
}

/**
 * @brief Sets the visited status of the Location to true.
 * 
 * This method marks the Location as visited by setting its visited status to true.
 * 
 * @return void
 */
void Location::set_visited()
{
    // set visited to true
    this->visited = true;
}

/* Utility methods */

/**
 * @brief Overloaded stream insertion operator for printing Location information.
 * 
 * This operator allows you to print the details of a Location, including its name,
 * description, NPCs, items, and neighboring locations.
 * 
 * @param output The output stream where the Location information will be printed.
 * @param location The Location object to be printed.
 * @return A reference to the output stream for chaining.
 */
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

/**
 * @brief Overloaded equality operator for comparing two Location objects.
 * 
 * This operator checks if two Location objects are equal by comparing their name,
 * description, visited status, neighboring locations, NPCs, and items.
 * 
 * @param a The first Location object to be compared.
 * @param b The second Location object to be compared.
 * @return true if the two Location objects are equal, false otherwise.
 */
bool operator==(const Location &a, const Location &b)
{
    return a.get_name() == b.get_name() 
    && a.get_description() == b.get_description() 
    && a.get_visited() == b.get_visited() 
    && a.get_locations() == b.get_locations() 
    && a.get_npcs() == b.get_npcs() 
    && a.get_items() == b.get_items();
}