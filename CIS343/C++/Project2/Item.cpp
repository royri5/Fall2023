#include "Item.hpp"

/**
 * @class Item
 * @brief Represents an item with a name, description, calories, and weight.
 * @author Richard Roy - richard.alex.roy@gmail.com
 * @date 10/5/23
 * 
 * This class defines attributes and methods for managing items in a game world.
 */

/* Constructors */

/**
 * @brief Default constructor for the Item class.
 * 
 * Initializes an Item object with default values for its attributes.
 */
Item::Item()
{
    this->name = "noname";
    this->description = "no description";
    this->calories = 0;
    this->weight = 0;
}

/**
 * @brief Parameterized constructor for the Item class with exception handling.
 * 
 * Initializes an Item object with the provided name, description, calories, and weight,
 * and performs exception handling to ensure valid values for each attribute.
 * 
 * @param itemname The name of the item.
 * @param itemdescription The description of the item.
 * @param itemcalories The calories value of the item.
 * @param itemweight The weight of the item.
 * 
 * @throws std::invalid_argument If any of the input values are invalid.
 */
Item::Item(std::string itemname,
           std::string itemdescription,
           int itemcalories,
           float itemweight)
{
    // Exception handling for invalid Name
    if (itemname == "")
    {
        throw std::invalid_argument(
            "Name cannot be blank");
    }
    // Exception handling for invalid Calories
    if (itemcalories < 0)
    {
        throw std::invalid_argument(
            "Calories value cannot be negative");
    }
    // Exception handling for invalid Calories
    if (itemcalories > 1000)
    {
        throw std::invalid_argument(
            "Calories value cannot be greater than 1000");
    }
    // Exception handling for invalid Description
    if (itemdescription == "")
    {
        throw std::invalid_argument(
            "Description cannot be blank");
    }
    // Exception handling for invalid Weight
    if (itemweight < 0)
    {
        throw std::invalid_argument(
            "Weight cannot be negative");
    }
    // Exception handling for invalid Weight
    if (itemweight > 500)
    {
        throw std::invalid_argument(
            "Weight cannot be greater than 500");
    }

    // Initialize member variables
    this->name = itemname;
    this->description = itemdescription;
    this->calories = itemcalories;
    this->weight = itemweight;
}

/* Getter methods */

/**
 * @brief Get the name of the item.
 * 
 * @return The name of the item as a string.
 */
std::string Item::get_name() const
{
    return this->name;
}

/**
 * @brief Get the description of the item.
 * 
 * @return The description of the item as a string.
 */
std::string Item::get_description() const
{
    return this->description;
}

/**
 * @brief Get the calories value of the item.
 * 
 * @return The calories value of the item as an integer.
 */
int Item::get_calories() const
{
    return this->calories;
}

/**
 * @brief Get the weight of the item.
 * 
 * @return The weight of the item as a floating-point value.
 */
float Item::get_weight() const
{
    return this->weight;
}

/* Setter methods */

/**
 * @brief Set the name of the item.
 * 
 * @param newname The new name to set for the item.
 * 
 * @throws std::invalid_argument If the new name is blank.
 */
void Item::set_name(std::string newname)
{
    // Exception handling for blank name
    if (newname == "")
    {
        throw std::invalid_argument(
            "Name cannot be blank");
    }
    this->name = newname;
}

/**
 * @brief Set the description of the item.
 * 
 * @param newdescription The new description to set for the item.
 * 
 * @throws std::invalid_argument If the new description is blank.
 */
void Item::set_description(std::string newdescription)
{
    // Exception handling for blank description
    if (newdescription == "")
    {
        throw std::invalid_argument(
            "Description cannot be blank");
    }
    this->description = newdescription;
}

/**
 * @brief Set the calories value of the item.
 * 
 * @param newcalories The new calories value to set for the item.
 * 
 * @throws std::invalid_argument If the new calories value is negative or greater than 1000.
 */
void Item::set_calories(int newcalories)
{
    // Exception handling for invalid Calories
    if (newcalories < 0)
    {
        throw std::invalid_argument(
            "Calories value cannot be negative");
    }
    if (newcalories > 1000)
    {
        throw std::invalid_argument(
            "Calories value cannot be greater than 1000");
    }
    this->calories = newcalories;
}

/**
 * @brief Set the weight of the item.
 * 
 * @param newweight The new weight to set for the item.
 * 
 * @throws std::invalid_argument If the new weight is negative or greater than 500.
 */
void Item::set_weight(float newweight)
{
    // Exception handling for invalid Weight
    if (newweight < 0)
    {
        throw std::invalid_argument(
            "Weight cannot be negative");
    }
    if (newweight > 500)
    {
        throw std::invalid_argument(
            "Weight cannot be greater than 500");
    }
    this->weight = newweight;
}

/* Overloaded operators */

/** below is from Github Copilot **/

/**
 * @brief Overloaded stream operator for the Item class.
 * 
 * This operator allows an Item object to be streamed to an output stream.
 * 
 * @param output The output stream to which the item should be streamed.
 * @param item The Item object to be streamed.
 * @return The output stream after streaming the item.
 */
std::ostream &operator<<(std::ostream &output, const Item &item)
{
    output
        << item.name
        << " ("
        << item.calories
        << " calories) - "
        << item.weight
        << " lb - "
        << item.description
        << "\n";
    return output;
}

/**
 * @brief Overloaded equality operator for the Item class.
 * 
 * This operator checks if two Item objects are equal based on their attributes.
 * 
 * @param a The first Item object to compare.
 * @param b The second Item object to compare.
 * @return true if the items are equal, false otherwise.
 */
bool operator==(const Item &a, const Item &b)
{
    return a.name == b.name 
    && a.description == b.description 
    && a.calories == b.calories 
    && a.weight == b.weight;
}

/**
 * @brief Overloaded inequality operator for the Item class.
 * 
 * This operator checks if two Item objects are not equal based on their attributes.
 * 
 * @param a The first Item object to compare.
 * @param b The second Item object to compare.
 * @return true if the items are not equal, false otherwise.
 */
bool operator!=(const Item &a, const Item &b)
{
    return a.name != b.name 
    || a.description != b.description 
    || a.calories != b.calories 
    || a.weight != b.weight;
}