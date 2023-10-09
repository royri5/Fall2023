
#include "Location.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <functional>
#include "NPC.hpp"
#include "Item.hpp"

// tests

// constructor testing

// tests regular constructor with blank name
void test_constructor_exception_name()
{ 
    // catch exception generated when name is blank
    try
    {
        Location location = Location("", "A dark forest");
    }
    catch (std::invalid_argument &e)
    {
        printf("test_constructor_exception_name Passed\n");
    }
    printf("test_constructor_exception_name done\n");
}
// tests regular constructor with blank description
void test_constructor_exception_description()
{
    // catch exception generated when description is blank
    try
    {
        Location location = Location("Forest", "");
    }
    catch (std::invalid_argument &e)
    {
        printf("test_constructor_exception_description Passed\n");
    }
    printf("test_constructor_exception_description done\n");
}

// getter tests
// tests get_locations
void test_get_locations_add_locations(Location location)
{
    // check before
    if (location.get_locations() == std::map<std::string, Location>())
    {
        // add location
        Location location2 = Location("Plains", "A grassy plain");
        location.add_ref_location("North", location2);
        if (location.get_locations() == std::map<std::string, Location>({{"North", location2}}))
        {
            printf("test_get_locations_add_locationsNorth Passed\n");
        }
        else
        {
            printf("test_get_locations_add_locationsNorth Failed\nexpected: {North: Plains}\nbut was: %s", location.get_locations());
        }
        // add another location
        Location location3 = Location("Mountains", "A rocky mountain");
        location.add_ref_location("South", location3);
        if (location.get_locations() == std::map<std::string, Location>({{"North", location2}, {"South", location3}}))
        {
            printf("test_get_locations_add_locationsSouth Passed\n");
        }
        else
        {
            printf("test_get_locations_add_locationsSouth Failed\nexpected: {North: Plains, South: Mountains}\nbut was: %s", location.get_locations());
        }
        // add another location
        Location location4 = Location("Swamp", "A wet swamp");
        location.add_ref_location("East", location4);
        if (location.get_locations() == std::map<std::string, Location>({{"North", location2}, {"South", location3}, {"East", location4}}))
        {
            printf("test_get_locations_add_locationsEast Passed\n");
        }
        else
        {
            printf("test_get_locations_add_locationsEast Failed\nexpected: {North: Plains, South: Mountains, East: Swamp}\nbut was: %s", location.get_locations());
        }
        // add another location
        Location location5 = Location("Desert", "A dry desert");
        location.add_ref_location("West", location5);
        if (location.get_locations() == std::map<std::string, Location>({{"North", location2}, {"South", location3}, {"East", location4}, {"West", location5}}))
        {
            printf("test_get_locations_add_locationsWest Passed\n");
        }
        else
        {
            printf("test_get_locations_add_locationsWest Failed\nexpected: {North: Plains, South: Mountains, East: Swamp, West: Desert}\nbut was: %s", location.get_locations());
        }
    }
}

// tests add_item
void test_add_item_get_items(Location location)
{
    // check before
    if (location.get_items() == std::vector<Item>())
    {
        // add item
        Item item1 = Item("Sword", "A sharp sword", 0, 1.5);
        location.add_ref_item(item1);
        if (location.get_items() == std::vector<Item>({item1}))
        {
            printf("test_add_item Passed\n");
        }
        else
        {
            printf("test_add_item Failed\nexpected: {Sword: A sharp sword}\nbut was: %s", location.get_items());
        }
        // add another item
        Item item2 = Item("Shield", "A sturdy shield", 0, 2.5);
        location.add_ref_item(item2);
        if (location.get_items() == std::vector<Item>({item1, item2}))
        {
            printf("test_add_item Passed\n");
        }
        else
        {
            printf("test_add_item Failed\nexpected: {Sword: A sharp sword, Shield: A sturdy shield}\nbut was: %s", location.get_items());
        }
    }
}

// setter tests/adder tests
// tests add_npc
void test_add_npc_get_npcs(Location location)
{
    // check before
    if (location.get_npcs() == std::vector<NPC>())
    {
        // add npc
        NPC npc1 = NPC("Bob", "A goblin wizard");
        location.add_ref_npc(npc1);
        if (location.get_npcs() == std::vector<NPC>({npc1}))
        {
            printf("test_add_npc Passed\n");
        }
        else
        {
            printf("test_add_npc Failed\nexpected: {Bob: A goblin wizard}\nbut was: %s", location.get_npcs());
        }
        // add another npc
        NPC npc2 = NPC("Bill", "A goblin necromancer");
        location.add_ref_npc(npc2);
        if (location.get_npcs() == std::vector<NPC>({npc1, npc2}))
        {
            printf("test_add_npc Passed\n");
        }
        else
        {
            printf("test_add_npc Failed\nexpected: {Bob: A goblin wizard, Bill: A goblin necromancer}\nbut was: %s", location.get_npcs());
        }
    }
}
// tests get_name
void test_get_name(Location location)
{
    if (location.get_name() == "Forest")
    {
        printf("test_get_name Passed\n");
    }
    else
    {
        printf("test_get_name Failed\nexpected: Forest\nbut was: %s", location.get_name());
    }
}
// tests get_description
void test_get_description(Location location)
{
    if (location.get_description() == "A dark forest")
    {
        printf("test_get_description Passed\n");
    }
    else
    {
        printf("test_get_description Failed\nexpected: A dark forest\nbut was: %s", location.get_description());
    }
}

// tests setVisited
void test_set_visited_get_visited(Location location)
{
    // cannot unvisit location
    // check before
    if (location.get_visited() == false)
    {
        location.set_visited();
        // check after
        if (location.get_visited() == true)
        {
            printf("test_setVisited Passed\n");
        }
        else
        {
            printf("test_setVisited Failed\nexpected: true\nbut was: %d", location.get_visited());
        }
    }
    else
    {
        printf("test_setVisited Failed\nexpected: false\nbut was: %d", location.get_visited());
    }
}

// main for all tests
//int main(void)
// {
//     std::vector<Location> locations;
//     // constructor tests
//     test_constructor_exception_name();
//     test_constructor_exception_description();

//     Location testLocation("Forest", "A dark forest");
//     locations.push_back(testLocation);

//     // double dipping tests
//     test_get_locations_add_locations(testLocation);
//     test_add_npc_get_npcs(testLocation);
//     test_add_item_get_items(testLocation);
//     test_set_visited_get_visited(testLocation);

//     // getter tests
//     test_get_name(testLocation);
//     test_get_description(testLocation);

//     // add npcs
//     NPC npc1 = NPC("Bob", "A goblin wizard");
//     testLocation.add_ref_npc(npc1);
//     NPC npc2 = NPC("Bill", "A goblin necromancer");
//     testLocation.add_ref_npc(npc2);
//     // add items
//     Item item1 = Item("Sword", "A sharp sword", 0, 1.5);
//     testLocation.add_ref_item(item1);
//     Item item2 = Item("Shield", "A sturdy shield", 0, 2.5);
//     testLocation.add_ref_item(item2);
//     // add locations
//     Location location2 = Location("Plains", "A grassy plain");
//     testLocation.add_ref_location("North", location2);
//     Location location3 = Location("Mountains", "A rocky mountain");
//     testLocation.add_ref_location("South", location3);
//     Location location4 = Location("Swamp", "A wet swamp");
//     testLocation.add_ref_location("East", location4);
//     Location location5 = Location("Desert", "A dry desert");
//     testLocation.add_ref_location("West", location5);

//     std::cout << testLocation << std::endl;
// }