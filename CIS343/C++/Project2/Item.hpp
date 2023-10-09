// include guard
#ifndef _ITEM_
#define _ITEM_

// includes
#include <string>
#include <iostream>

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

// defines item class
class Item
{
public:
    // default constructor
    Item();

    // constructor with parameters
    Item(
        std::string name,
        std::string description,
        int calories,
        float weight);

    // getters
    std::string getName() const;
    std::string getDescription() const;
    int getCalories() const;
    float getWeight() const;

    // setters
    // think about what return type these should be
    void setName(std::string name);
    void setDescription(std::string description);
    void setCalories(int calories);
    void setWeight(float weight);

    // overloaded stream operator
    // think about if you need const here
    // std::string operator>>(const Item item) const;
    // below is Github Copilot code
    friend std::ostream &operator<<(
        std::ostream &output,
        const Item &item);
    // overloaded equality operator
    friend bool operator==(
        const Item &a,
        const Item &b);
    // overloaded inequality operator
    friend bool operator!=(
        const Item &a,
        const Item &b);

private:
    // class variables
    std::string name;
    std::string description;
    int calories;
    float weight;
};

#endif