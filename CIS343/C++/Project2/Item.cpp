// Author: Richard Roy
// Date: 10/10/23

// includes
#include "Item.hpp"

// default constructor
Item::Item()
{
    this->name = "noname";
    this->description = "no description";
    this->calories = 0;
    this->weight = 0;
}

// constructor with parameters
Item::Item(std::string itemname,
           std::string itemdescription,
           int itemcalories,
           float itemweight)
{
    // exception checking
    // check if name is blank
    if (itemname == "")
    {
        throw std::invalid_argument("Name cannot be blank");
    }
    // check if calories are less than 0
    if (itemcalories < 0)
    {
        throw std::invalid_argument("Calories value\
 cannot be negative");
    }
    // check if calories are greater than 1000
    if (itemcalories > 1000)
    {
        throw std::invalid_argument("Calories value\
 cannot be greater than 1000");
    }
    // check if description is blank
    if (itemdescription == "")
    {
        throw std::invalid_argument("Description cannot be blank");
    }
    // check if weight is less than 0
    if (itemweight < 0)
    {
        throw std::invalid_argument("Weight cannot be negative");
    }
    // check if weight is greater than 500
    if (itemweight > 500)
    {
        throw std::invalid_argument("Weight cannot\
 be greater than 500");
    }

    // instantiate object variables
    this->name = itemname;
    this->description = itemdescription;
    this->calories = itemcalories;
    this->weight = itemweight;
}

// getters
// getName
std::string Item::get_name() const
{
    return this->name;
}
// getDescription
std::string Item::get_description() const
{
    return this->description;
}
// getCalories
int Item::get_calories() const
{
    return this->calories;
}
// getWeight
float Item::get_weight() const
{
    return this->weight;
}

// setters
// setName (make sure name is not set to blank)
void Item::set_name(std::string newname)
{
    if (newname == "")
    {
        throw std::invalid_argument("Name cannot be blank");
    }
    this->name = newname;
}
// setDescription (make sure description is not set to blank)
void Item::set_description(std::string newdescription)
{
    if (newdescription == "")
    {
        throw std::invalid_argument("Description cannot be blank");
    }
    this->description = newdescription;
}
// setCalories (make sure calories are not set to < 0 or > 1000)
void Item::set_calories(int newcalories)
{
    if (newcalories < 0)
    {
        throw std::invalid_argument("Calories value cannot\
 be negative");
    }
    if (newcalories > 1000)
    {
        throw std::invalid_argument("Calories value cannot\
 be greater than 1000");
    }
    this->calories = newcalories;
}
// setWeight (make sure weight is not set to < 0 or > 500)
void Item::set_weight(float newweight)
{
    if (newweight < 0)
    {
        throw std::invalid_argument("Weight cannot be negative");
    }
    if (newweight > 500)
    {
        throw std::invalid_argument("Weight cannot\
 be greater than 500");
    }
    this->weight = newweight;
}

// overloaded stream operator
// below is from Github Copilot
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