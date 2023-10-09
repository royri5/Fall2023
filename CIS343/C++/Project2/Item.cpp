// includes
#include "Item.hpp"

// An Item represents objects the player may encounter along the way, and is an object that has a name, a
// description, the number of calories it can provide (0 if it isn't edible), and a weight. It must provide:
//  * A constructor that can take a name, description, calories, and weight.
//       *You must ensure the following (raise exceptions for violations):
//           * The name variable cannot be blank.
//           * The calories variable cannot be less than 0 or more than 1000 and must be an int..
//           * The description cannot be blank.
//           * The weight must be a float and must be between 0 and 500
//  * An overloaded stream operator that returns a string representing the Item. The format should be:
//      NAME (X calories) - X lb - DESCRIPTION   i.e.:
//      Rusty Nail (0 calories) - 1 lb - A rusty nail (I hope you've had a tetanus shot)

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
        throw std::invalid_argument("Calories value cannot be negative");
    }
    // check if calories are greater than 1000
    if (itemcalories > 1000)
    {
        throw std::invalid_argument("Calories value cannot be greater than 1000");
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
        throw std::invalid_argument("Weight cannot be greater than 500");
    }

    // instantiate object variables
    this->name = itemname;
    this->description = itemdescription;
    this->calories = itemcalories;
    this->weight = itemweight;
}

// getters
// getName
std::string Item::getName() const
{
    return this->name;
}
// getDescription
std::string Item::getDescription() const
{
    return this->description;
}
// getCalories
int Item::getCalories() const
{
    return this->calories;
}
// getWeight
float Item::getWeight() const
{
    return this->weight;
}

// setters
// setName (make sure name is not set to blank)
void Item::setName(std::string newname)
{
    if (newname == "")
    {
        throw std::invalid_argument("Name cannot be blank");
    }
    this->name = newname;
}
// setDescription (make sure description is not set to blank)
void Item::setDescription(std::string newdescription)
{
    if (newdescription == "")
    {
        throw std::invalid_argument("Description cannot be blank");
    }
    this->description = newdescription;
}
// setCalories (make sure calories are not set to < 0 or > 1000)
void Item::setCalories(int newcalories)
{
    if (newcalories < 0)
    {
        throw std::invalid_argument("Calories value cannot be negative");
    }
    if (newcalories > 1000)
    {
        throw std::invalid_argument("Calories value cannot be greater than 1000");
    }
    this->calories = newcalories;
}
// setWeight (make sure weight is not set to < 0 or > 500)
void Item::setWeight(float newweight)
{
    if (newweight < 0)
    {
        throw std::invalid_argument("Weight cannot be negative");
    }
    if (newweight > 500)
    {
        throw std::invalid_argument("Weight cannot be greater than 500");
    }
    this->weight = newweight;
}

// overloaded stream operator
// think about if you need const here
// below is from Github Copilot
std::ostream &operator<<(std::ostream &output, const Item &item)
{
    output << item.name << " (" << item.calories << " calories) - " << item.weight << " lb - " << item.description << "\n";

    return output;
}

// overloaded equality operator
bool operator==(const Item &a, const Item &b)
{
    return a.getName() == b.getName() && a.getDescription() == b.getDescription() && a.getCalories() == b.getCalories() && a.getWeight() == b.getWeight();
}

// overloaded inequality operator
bool operator!=(const Item &a, const Item &b)
{
    return a.getName() != b.getName() || a.getDescription() != b.getDescription() || a.getCalories() != b.getCalories() || a.getWeight() != b.getWeight();
}