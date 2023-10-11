// Author: Richard Roy
// Date: 10/10/23

// include guard
#ifndef _ITEM_
#define _ITEM_

// includes
#include <string>
#include <iostream>

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
    std::string get_name() const;
    std::string get_description() const;
    int get_calories() const;
    float get_weight() const;

    // setters
    void set_name(std::string name);
    void set_description(std::string description);
    void set_calories(int calories);
    void set_weight(float weight);

    // overloaded stream operator
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