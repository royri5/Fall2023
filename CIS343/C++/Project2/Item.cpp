// Author: Richard Roy
// Date: 10/10/23

// Standard library includes
#include "Item.hpp"


// Constructors

// Default constructor
Item::Item()
{
    this->name = "noname";
    this->description = "no description";
    this->calories = 0;
    this->weight = 0;
}

// Parameterized constructor with exception handling
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
// name
std::string Item::get_name() const
{
    return this->name;
}
// description
std::string Item::get_description() const
{
    return this->description;
}
// calories
int Item::get_calories() const
{
    return this->calories;
}
// weight
float Item::get_weight() const
{
    return this->weight;
}


/* Setter methods */
// set name
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
// set description
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
// set calories
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
// set weight
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
// below is from Github Copilot

// overloaded stream operator
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

// overloaded equality operator
bool operator==(const Item &a, const Item &b)
{
    return a.name == b.name 
    && a.description == b.description 
    && a.calories == b.calories 
    && a.weight == b.weight;
}

// overloaded inequality operator
bool operator!=(const Item &a, const Item &b)
{
    return a.name != b.name 
    || a.description != b.description 
    || a.calories != b.calories 
    || a.weight != b.weight;
}