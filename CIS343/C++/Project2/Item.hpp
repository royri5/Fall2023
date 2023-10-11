// Author: Richard Roy
// Date: 10/10/23

// Include guard to prevent multiple inclusions of this header file
#ifndef _ITEM_
#define _ITEM_

// Standard library includes
#include <string>
#include <iostream>

/**
 * @class Item
 * @brief Represents an item in locations and the player's inventory.
 * 
 * The Item class encapsulates the properties of an item, such as its name, description, calories, and weight.
 */
class Item
{
public:
    // Public Member Functions (API)

    // Constructors
    Item();  // Default constructor
    Item(std::string name, std::string description, int calories, float weight);  // Parameterized constructor

    // Getters (Accessor Methods)
    std::string get_name() const;
    std::string get_description() const;
    int get_calories() const;
    float get_weight() const;

    // Setters (Mutator Methods)
    void set_name(std::string name);
    void set_description(std::string description);
    void set_calories(int calories);
    void set_weight(float weight);

    // Overloaded Operators

    // Allows printing the Item object to the console
    friend std::ostream &operator<<(std::ostream &output, const Item &item);

    // Compares two Item objects for equality
    friend bool operator==(const Item &a, const Item &b);

    // Compares two Item objects for inequality
    friend bool operator!=(const Item &a, const Item &b);

private:
    // Private Member Variables (State)

    std::string name;        // Name of the item
    std::string description; // Description of the item
    int calories;            // Caloric content of the item
    float weight;            // Weight of the item in some unit (e.g., kg)
};

#endif  // End of include guard
