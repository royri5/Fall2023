#include "Item.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

// tests

// constructor testing
// tests default constructor
void test_default_constructor()
{
}
// tests regular constructor
void test_constructor()
{
    Item item = Item("Rusty Nail", "A rusty nail (I hope you've had a tetanus shot)", 0, .5);
    if (item.getName() == "Rusty Nail" && item.getDescription() == "A rusty nail (I hope you've had a tetanus shot)" && item.getCalories() == 0 && item.getWeight() == .5)
    {
        printf("test_constructor Passed\n");
    }
    else
    {
        printf("test_constructor Failed\nexpected: Rusty Nail\nA rusty nail (I hope you've had a tetanus shot)\n0\n.5\nbut was: %s\n%s\n%d\n%f",
               item.getName(),
               item.getDescription(),
               item.getCalories(),
               item.getWeight());
    }
}
// tests regular constructor with blank name
void test_constructor_exception_name()
{
    // catch exception generated when name is blank
    try
    {
        Item item = Item("", "A rusty nail (I hope you've had a tetanus shot)", 0, .5);
    }
    catch (std::invalid_argument &e)
    {
        printf("test_constructor_exception_name Passed\n");
    }
    printf("test_constructor_exception_name done\n");
}
// tests regular constructor with invalid calorie variables
void test_constructor_exception_calories1()
{
    // catch exception generated when calorie variable is less than 0
    try
    {
        Item item = Item("Rusty Nail", "A rusty nail (I hope you've had a tetanus shot)", -1, .5);
    }
    catch (std::invalid_argument &e)
    {
        printf("test_constructor_exception_calories1 Passed\n");
    }
    printf("test_constructor_exception_calories1 done\n");
}
// tests regular constructor with invalid calorie variables
void test_constructor_exception_calories2()
{
    try
    {
        Item item = Item("Rusty Nail", "A rusty nail (I hope you've had a tetanus shot)", 1001, .5);
    }
    catch (std::invalid_argument &e)
    {
        printf("test_constructor_exception_calories2 Passed\n");
    }
    printf("test_constructor_exception_calories2 done\n");
}
// tests regular constructor with invalid description
// might need a word cap
void test_constructor_exception_description()
{
    // catch exception generated when description is blank
    try
    {
        Item item = Item("Rusty Nail", "", 0, .5);
    }
    catch (std::invalid_argument &e)
    {
        printf("test_constructor_exception_description Passed\n");
    }
    printf("test_constructor_exception_description done\n");
}
// tests regular constructor with invalid weight
void test_constructor_exception_weight1()
{
    // catch exception generated when weight is less than 0
    try
    {
        Item item = Item("Rusty Nail", "A rusty nail (I hope you've had a tetanus shot)", 0, -1);
    }
    catch (std::invalid_argument &e)
    {
        printf("test_constructor_exception_weight1 Passed\n");
    }
    printf("test_constructor_exception_weight1 done\n");
}
// tests regular constructor with invalid weight
void test_constructor_exception_weight2()
{
    // catch exception generated when weight is greater than 500
    try
    {
        Item item = Item("Rusty Nail", "A rusty nail (I hope you've had a tetanus shot)", 0, 501);
    }
    catch (std::invalid_argument &e)
    {
        printf("test_constructor_exception_weight2 Passed\n");
    }
    printf("test_constructor_exception_weight2 done\n");
}

// getter tests
// tests getName
void test_getName(Item item)
{
    if (item.getName() == "Rusty Nail")
    {
        printf("test_getName Passed\n");
    }
    else
    {
        printf("test_getName Failed\nexpected: Rusty Nail\nbut was: %s", item.getName());
    }
}
// tests getDescription
void test_getDescription(Item item)
{
    if (item.getDescription() == "A rusty nail (I hope you've had a tetanus shot)")
    {
        printf("test_getDescription Passed\n");
    }
    else
    {
        printf("test_getDescription Failed\nexpected: A rusty nail (I hope you've had a tetanus shot)\nbut was: %s", item.getDescription());
    }
}
// tests getCalories
void test_getCalories(Item item)
{
    if (item.getCalories() == 0)
    {
        printf("test_getCalories Passed\n");
    }
    else
    {
        printf("test_getCalories Failed\nexpected: 0\nbut was: %d", item.getCalories());
    }
}
// tests getWeight
void test_getWeight(Item item)
{
    if (item.getWeight() == .5)
    {
        printf("test_getWeight Passed\n");
    }
    else
    {
        printf("test_getWeight Failed\nexpected: .5\nbut was: %f", item.getWeight());
    }
}

// setter tests
// tests setName
void test_setName(Item item)
{
    item.setName("newname");
    if (item.getName() == "newname")
    {
        printf("test_setName Passed\n");
    }
    else
    {
        printf("test_setName Failed\nexpected: newname\nbut was: %s", item.getName());
    }
}
// tests setDescription
void test_setDescription(Item item)
{
    item.setDescription("newdescription");
    if (item.getDescription() == "newdescription")
    {
        printf("test_setDescription Passed\n");
    }
    else
    {
        printf("test_setDescription Failed\nexpected: newdescription\nbut was: %s", item.getDescription());
    }
}
// tests setCalories
void test_setCalories(Item item)
{
    item.setCalories(1);
    if (item.getCalories() == 1)
    {
        printf("test_setCalories Passed\n");
    }
    else
    {
        printf("test_setCalories Failed\nexpected: 1\nbut was: %d", item.getCalories());
    }
}
// tests setWeight
void test_setWeight(Item item)
{
    item.setWeight(1.5);
    if (item.getWeight() == 1.5)
    {
        printf("test_setWeight Passed\n");
    }
    else
    {
        printf("test_setWeight Failed\nexpected: 1.5\nbut was: %f", item.getWeight());
    }
}

// main for all tests
//int main(void)
// {
//     std::vector<Item> items;
//     // constructor tests
//     test_default_constructor();
//     test_constructor();
//     test_constructor_exception_name();
//     test_constructor_exception_calories1();
//     test_constructor_exception_calories2();
//     test_constructor_exception_description();
//     test_constructor_exception_weight1();
//     test_constructor_exception_weight2();

//     Item testItem("Rusty Nail", "A rusty nail (I hope you've had a tetanus shot)", 0, .5);
//     items.push_back(testItem);

//     // overloaded stream operator test
//     std::cout << (items.at(0));

//     // getter tests
//     test_getName(items.at(0));
//     test_getDescription(items.at(0));
//     test_getCalories(items.at(0));
//     test_getWeight(items.at(0));

//     // setter tests
//     test_setName(items.at(0));
//     test_setDescription(items.at(0));
//     test_setCalories(items.at(0));
//     test_setWeight(items.at(0));
// }