
#include "Game.hpp"
#include "Location.hpp"
#include "NPC.hpp"
#include "Item.hpp"
#include <string>
#include <vector>
#include <stdexcept>
#include <functional>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <iterator>
#include <random>

// constructor
Game::Game()
{
    // set commands map
    this->setup_commands();
    // create world
    this->create_world();

    
    //this->ref_locations = std::vector<std::reference_wrapper<Location> >(this->locations.begin(), this->locations.end()); 
    //leaving off here, some data in the ref locations, ref npcs was
    //clearly corrupt from accessing freed memory
    //need to find exactly where this is occuring
    // above loop/iterator are not finished



    //this->ref_locations = std::vector<std::reference_wrapper<Location> >(this->locations.begin(), this->locations.end());
    // iterator for ref_locations
    // sets ref_items and ref_npcs
    // for each location
    //std::vector<std::reference_wrapper<Location> 
    //>::iterator ref_locations_iterator = this->ref_locations.begin();
    // while (ref_locations_iterator != this->ref_locations.end()) {
    //     (*ref_locations_iterator).get().set_ref_item((*ref_locations_iterator).get().get_items());
    //     (*ref_locations_iterator).get().set_ref_npc((*ref_locations_iterator).get().get_npcs());
    //     ref_locations_iterator++;
    // }
    // while(ref_locations_iterator != this->ref_locations.end()) {
    //     (ref_locations_iterator)->get().set_ref_npc(std::vector<std::reference_wrapper<NPC> 
    //         >( (*ref_locations_iterator).get().get_npcs().begin(), (*ref_locations_iterator).get().get_npcs().end()));
    //     (ref_locations_iterator)->get().set_ref_item(std::vector<std::reference_wrapper<Item> 
    //         >( (*ref_locations_iterator).get().get_items().begin(), (*ref_locations_iterator).get().get_items().end()));
    //     ref_locations_iterator++;
    // }

    // set default values
    this->current_location = this->random_location();
    //this->curr = this->random_location();
    this->current_weight = 0;
    this->calories_needed = 500;
    this->game_in_progress = true;
}

// create world function
// creates all locations, items, and npcs
// adds items and npcs to rooms/locations
// adds locations to neighbors connected to them
void Game::create_world()
{
    // create locations
    
    // Mary Idema Pew Library
    // 5 floors (1 basement, 4 above ground)
    // base library(1st floor)
    // Location maryIdemaPewLibrary("Mary Idema Pew Library",
    //                              "The campus library. There are books, computers, and places to study.");
    // this->locs.push_back(maryIdemaPewLibrary);
    // int maryIdemaPewLibraryIndex = this->locs.size() - 1;

    // // Mackinac Hall (labyrinth)
    // // 4 wings, varying floors
    // Location mackinacHall("Mackinac Hall",
    //                       "The home of the CIS department...and others, the bane of freshman.");
    // this->locs.push_back(mackinacHall);
    // int mackinacHallIndex = this->locs.size() - 1;

    // Laker Village (houses are boarded up (1 location))
    Location lakerVillage("Laker Village",
                          "A compound of on-campus town houses, currently abandoned.\
    You notice boards on all the windows and doors.");
    this->locs.push_back(lakerVillage);
    int lakerVillageIndex = this->locs.size() - 1;

    // Blue Connection
    // 2 floors
    Location blueConnection("Blue Connection",
                            "A common area with a small food-court and a convenience store.");
    this->locs.push_back(blueConnection);
    int blueConnectionIndex = this->locs.size() - 1;

    // Kirkhof Center Parking Lot
    Location kirkhofCenterParkingLot("Kirkhof Center Parking Lot",
                                     "A once bustling center of campus transport, now seemingly empty.");
    this->locs.push_back(kirkhofCenterParkingLot);
    int kirkhofCenterParkingLotIndex = this->locs.size() - 1;

    // // Clock Tower
    // Location clockTower("Clock Tower",
    //                     "A large clock tower, the center of campus.");
    // this->locs.push_back(clockTower);
    // int clockTowerIndex = this->locs.size() - 1;

    // // Kirkhof Center
    // // 2 floors?
    // Location kirkhofCenter("Kirkhof Center",
    //                        "This building was once the pinnacle of the campus commons,\
    // now decrepit.");
    // this->locs.push_back(kirkhofCenter);
    // int kirkhofCenterIndex = this->locs.size() - 1;

    // // Fresh
    // // 2 floors
    // Location fresh("Fresh",
    //                "A buffet-style cafeteria.");
    // this->locs.push_back(fresh);
    // int freshIndex = this->locs.size() - 1;

    // // Marketplace
    // // 1 floor (2 rooms)
    // Location marketplace("Marketplace",
    //                      "Along the main road of campus, this building contains\
    // a small food court and the campus store.");
    // this->locs.push_back(marketplace);
    // int marketplaceIndex = this->locs.size() - 1;

    // // Henry Hall
    // // 2 floors?
    // Location henryHall("Henry Hall",
    //                    "This building contains several computer labs.");
    // this->locs.push_back(henryHall);
    // int henryHallIndex = this->locs.size() - 1;

    // // Woods
    // Location woods("Woods",
    //                "A small patch of woods behind campus. The elf lives here.");
    // this->locs.push_back(woods);
    // int woodsIndex = this->locs.size() - 1;

//end of create world function
this->locations = std::vector<std::reference_wrapper<Location> >(this->locs.begin(), this->locs.end());

//NOTE:
// need to make all Items and NPCs
// referenced wrapped before adding to locations




// create items
    // create items
    // food items (need at least 2-3 in marketplace,
    // fresh, and blue connection)
    // total calories needed to win = 500
    // does not require all food items, but most
    // nonfood items (need at least 1-3 per location)
    // some items are unique, some are not

    // food items

    // connection
    Item connectionSandwich = Item("Stingin' Honey Chicken Sandwich",
                                   "Spicy and crispy chicken sandwich, the pinnacle of campus food",
                                   55, 1);
    this->locations[blueConnectionIndex].get().add_item(connectionSandwich);
    // int blueSandwichIndex = this->locations[blueConnectionIndex].get().get_items_storage().size() - 1;
    // this->locations[blueConnectionIndex].get().add_item(this->locations[blueConnectionIndex].get().get_items_storage()[blueSandwichIndex]);
    Item lakerBowl = Item("Laker Bowl",
                          "The legendary Laker Bowl, popcorn chicken, mashed potatoes, corn\
    , and gravy",
                          50, 1.5);
    this->locations[blueConnectionIndex].get().add_item(lakerBowl);
    // int blueBowlIndex = this->locations[blueConnectionIndex].get().get_items_storage().size() - 1;
    // this->locations[blueConnectionIndex].get().add_item(this->locations[blueConnectionIndex].get().get_items_storage()[blueBowlIndex]);
    Item italianSub = Item("Italian Sub",
                           "A classic Italian sub, with ham, salami, pepperoni,\
    and provolone.",
                           45, 1);
    this->locations[blueConnectionIndex].get().add_item(italianSub);
    // int blueSubIndex = this->locations[blueConnectionIndex].get().get_items_storage().size() - 1;
    // this->locations[blueConnectionIndex].get().add_item(this->locations[blueConnectionIndex].get().get_items_storage()[blueSubIndex]);
    Item energyBarConnection = Item("Energy Bar",
                                    "A protein bar.", 10, .5);
    this->locations[blueConnectionIndex].get().add_item(energyBarConnection);
    // int blueEnergyBarIndex = this->locations[blueConnectionIndex].get().get_items_storage().size() - 1;
    // this->locations[blueConnectionIndex].get().add_item(this->locations[blueConnectionIndex].get().get_items_storage()[blueEnergyBarIndex]);
    Item bagOfChipsConnection = Item("Barbecue Chips",
                                     "A bag of delicious barbecue chips.", 10, .5);
    this->locations[blueConnectionIndex].get().add_item(bagOfChipsConnection);
    // int blueChipsIndex = this->locations[blueConnectionIndex].get().get_items_storage().size() - 1;
    // this->locations[blueConnectionIndex].get().add_item(this->locations[blueConnectionIndex].get().get_items_storage()[blueChipsIndex]);
    Item coffeeConnection = Item("Coffee",
                                 "The lifeblood of college students.", 10, .5);
    this->locations[blueConnectionIndex].get().add_item(coffeeConnection);
    // int blueCoffeeIndex = this->locations[blueConnectionIndex].get().get_items_storage().size() - 1;
    // this->locations[blueConnectionIndex].get().add_item(this->locations[blueConnectionIndex].get().get_items_storage()[blueCoffeeIndex]);


    // // fresh
    // Item freshPizza = Item("Pizza",
    //                        "A slice of cheese pizza.", 50, 1);
    // this->locations[freshIndex].add_item(freshPizza);
    // Item freshBurger = Item("Burger",
    //                         "A cold cheeseburger.", 40, 1);
    // this->locations[freshIndex].add_item(freshBurger);
    // Item freshSalad = Item("Salad",
    //                        "A caesar salad.", 25, 1);
    // this->locations[freshIndex].add_item(freshSalad);
    // Item coffeeFresh = Item("Coffee",
    //                         "The lifeblood of college students.", 10, .5);
    // this->locations[freshIndex].add_item(coffeeFresh);

    // // marketplace
    // Item marketplaceRamen = Item("Ramen",
    //                              "A cup of ramen.", 45, .5);
    // this->locations[marketplaceIndex].add_item(marketplaceRamen);
    // Item marketplaceSushi = Item("Sushi",
    //                              "A tray of old sushi. It's probably still good...", 20, 1);
    // this->locations[marketplaceIndex].add_item(marketplaceSushi);
    // Item coffeeMarketplace = Item("Coffee",
    //                               "The lifeblood of college students.", 10, .5);
    // this->locations[marketplaceIndex].add_item(coffeeMarketplace);

    // // mackinacHall
    // Item energyBarMac = Item("Energy Bar",
    //                          "A protein bar.", 10, .5);
    // this->locations[mackinacHallIndex].add_item(energyBarMac);
    // Item bagOfChipsMac = Item("Barbecue Chips",
    //                           "A bag of delicious barbecue chips.", 10, .5);
    // this->locations[mackinacHallIndex].add_item(bagOfChipsMac);
    // Item coffeeMac = Item("Coffee",
    //                       "The lifeblood of college students.", 10, .5);
    // this->locations[mackinacHallIndex].add_item(coffeeMac);

    // // kirhofCenter
    // Item trailMixKirkhof = Item("Trail Mix",
    //                             "A bag of trail mix. Contains peanuts.", 10, .5);
    // this->locations[kirkhofCenterIndex].add_item(trailMixKirkhof);
    // Item coffeeKirkhof = Item("Coffee",
    //                           "The lifeblood of college students.", 10, .5);
    // this->locations[kirkhofCenterIndex].add_item(coffeeKirkhof);

    // // clockTower
    // Item trailMixClockTower = Item("Trail Mix",
    //                                "A bag of trail mix. Contains peanuts.", 10, .5);
    // this->locations[clockTowerIndex].add_item(trailMixClockTower);

    // // henryHall
    // Item bagOfChipsHenry = Item("Barbecue Chips",
    //                             "A bag of delicious barbecue chips.", 10, .5);
    // this->locations[henryHallIndex].add_item(bagOfChipsHenry);
    // Item trailMixHenry = Item("Trail Mix",
    //                           "A bag of trail mix. Contains peanuts.", 10, .5);
    // this->locations[henryHallIndex].add_item(trailMixHenry);
    // Item coffeeHenry = Item("Coffee",
    //                         "The lifeblood of college students.", 10, .5);
    // this->locations[henryHallIndex].add_item(coffeeHenry);

    // lakerVillage
    Item energyBarVillage = Item("Energy Bar",
                                 "A protein bar.", 10, .5);
    this->locations[lakerVillageIndex].get().add_item(energyBarVillage);
    // int lakerEnergyBarIndex = this->locations[lakerVillageIndex].get().get_items_storage().size() - 1;
    // this->locations[lakerVillageIndex].get().add_item(this->locations[lakerVillageIndex].get().get_items_storage()[lakerEnergyBarIndex]);
    Item bagOfChipsVillage = Item("Barbecue Chips",
                                  "A bag of delicious barbecue chips.", 10, .5);
    this->locations[lakerVillageIndex].get().add_item(bagOfChipsVillage);
    // int lakerChipsIndex = this->locations[lakerVillageIndex].get().get_items_storage().size() - 1;
    // this->locations[lakerVillageIndex].get().add_item(this->locations[lakerVillageIndex].get().get_items_storage()[lakerChipsIndex]);

    // kirkhofCenterParkingLot
    Item bagOfChipsParking = Item("Barbecue Chips",
                                  "A bag of delicious barbecue chips.", 10, .5);
    this->locations[kirkhofCenterParkingLotIndex].get().add_item(bagOfChipsParking);
    // int parkingChipsIndex = this->locations[kirkhofCenterParkingLotIndex].get().get_items_storage().size() - 1;
    // this->locations[kirkhofCenterParkingLotIndex].get().add_item(this->locations[kirkhofCenterParkingLotIndex].get().get_items_storage()[parkingChipsIndex]);
    Item trailMixParking = Item("Trail Mix",
                                "A bag of trail mix. Contains peanuts.", 10, .5);
    this->locations[kirkhofCenterParkingLotIndex].get().add_item(trailMixParking);
    // int parkingTrailMixIndex = this->locations[kirkhofCenterParkingLotIndex].get().get_items_storage().size() - 1;
    // this->locations[kirkhofCenterParkingLotIndex].get().add_item(this->locations[kirkhofCenterParkingLotIndex].get().get_items_storage()[parkingTrailMixIndex]);

    // // Mary Idema Pew Library
    // Item bagOfChipsLibrary = Item("Barbecue Chips",
    //                               "A bag of delicious barbecue chips.", 10, .5);
    // this->locations[maryIdemaPewLibraryIndex].add_item(bagOfChipsLibrary);
    // Item trailMixLibrary = Item("Trail Mix",
    //                             "A bag of trail mix. Contains peanuts.", 10, .5);
    // this->locations[maryIdemaPewLibraryIndex].add_item(trailMixLibrary);
    // Item coffeeLibrary = Item("Coffee",
    //                           "The lifeblood of college students.", 10, .5);
    // this->locations[maryIdemaPewLibraryIndex].add_item(coffeeLibrary);

    // // nonfood items

    // connection
    // will be able to trade for food items with frantic student
    Item missingStudentID = Item("Missing Student ID",
                                 "A student ID, the owner is nowhere to be found.", 0, .5);
    this->locations[blueConnectionIndex].get().add_item(missingStudentID);
    // int blueIDIndex = this->locations[blueConnectionIndex].get().get_items_storage().size() - 1;
    // this->locations[blueConnectionIndex].get().add_item(this->locations[blueConnectionIndex].get().get_items_storage()[blueIDIndex]);
    Item penConnection = Item("Pen",
                              "A ballpoint pen, writes surprisingly well. Blue ink", 0, .5);
    this->locations[blueConnectionIndex].get().add_item(penConnection);
    // int bluePenIndex = this->locations[blueConnectionIndex].get().get_items_storage().size() - 1;
    // this->locations[blueConnectionIndex].get().add_item(this->locations[blueConnectionIndex].get().get_items_storage()[bluePenIndex]);

    // // fresh
    // Item droppedFork = Item("Dirty fork",
    //                         "A dirty fork, dropped by a careless student.", 0, .5);
    // this->locations[freshIndex].add_item(droppedFork);
    // Item penFresh = Item("Pen",
    //                      "A ballpoint pen, writes surprisingly well. Blue ink", 0, .5);
    // this->locations[freshIndex].add_item(penFresh);

    // // marketplace
    // Item claTextbook = Item("CLA 250 Textbook",
    //                         "Greek and Roman Art and Architecture", 0, 2);
    // this->locations[marketplaceIndex].add_item(claTextbook);

    // // mackinacHall
    // Item pencilMac = Item("Pencil",
    //                       "A #2 pencil, tool of choice for scantrons.", 0, .5);
    // this->locations[mackinacHallIndex].add_item(pencilMac);
    // Item penMac = Item("Pen",
    //                    "A ballpoint pen, writes surprisingly well. Blue ink", 0, .5);
    // this->locations[mackinacHallIndex].add_item(penMac);

    // // kirhofCenter
    // Item pencilKirkhof = Item("Pencil",
    //                           "A #2 pencil, tool of choice for scantrons.", 0, .5);
    // this->locations[kirkhofCenterIndex].add_item(pencilKirkhof);

    // // henryHall
    // Item pencilHenry = Item("Pencil",
    //                         "A #2 pencil, tool of choice for scantrons.", 0, .5);
    // this->locations[henryHallIndex].add_item(pencilHenry);

    // kirkhofCenterParkingLot
    Item penParking = Item("Pen",
                           "A ballpoint pen, writes surprisingly well. Blue ink", 0, .5);
    this->locations[kirkhofCenterParkingLotIndex].get().add_item(penParking);
    // int parkingPenIndex = this->locations[kirkhofCenterParkingLotIndex].get().get_items_storage().size() - 1;
    // this->locations[kirkhofCenterParkingLotIndex].get().add_item(this->locations[kirkhofCenterParkingLotIndex].get().get_items_storage()[parkingPenIndex]);

    // // Mary Idema Pew Library
    // Item pencilLibrary = Item("Pencil",
    //                           "A #2 pencil, tool of choice for scantrons.", 0, .5);
    // this->locations[maryIdemaPewLibraryIndex].add_item(pencilLibrary);
    // Item penLibrary = Item("Pen",
    //                        "A ballpoint pen, writes surprisingly well. Blue ink", 0, .5);
    // this->locations[maryIdemaPewLibraryIndex].add_item(penLibrary);
    // Item missingNotebook = Item("Notebook",
    //                             "A misplaced notebook,\
    //  the owner must be looking for this...",
    //                             0, 1);
    // this->locations[maryIdemaPewLibraryIndex].add_item(missingNotebook);



//then create npcs
// create npcs
    // Mackinac Hall
    // NPC studentNoTextbook = NPC("Frantic Student",
    //                             "A stressed student, they seem to be looking for something...");
    // this->locations[mackinacHallIndex].add_npc(studentNoTextbook);

    // // Library
    // NPC libraryDeskWorker = NPC("Library Desk Worker",
    //                             "A student employee, sitting idly at the main desk.");
    // this->locations[maryIdemaPewLibraryIndex].add_npc(libraryDeskWorker);

    // // Fresh
    // NPC freshEmployee = NPC("Fresh Employee",
    //                         "A student employee, checking student IDs at the door.");
    // this->locations[freshIndex].add_npc(freshEmployee);
    // NPC studentNoID = NPC("Stressed Student",
    //                       "A student trying to get into Fresh, they seem\
    //  to have misplaced their student ID.");
    // this->locations[freshIndex].add_npc(studentNoID);

    // Blue Connection
    NPC connectionEmployee = NPC("Connection Employee",
                                 "A student employee, taking orders at the counter.");
    this->locations[blueConnectionIndex].get().add_npc(connectionEmployee);
    //this->locations[blueConnectionIndex].get().add_npc(this->locations[blueConnectionIndex].get().get_npcs_storage()[blueEmployeeIndex]);

    // // Marketplace
    // NPC marketplaceEmployee = NPC("Marketplace Employee",
    //                               "A student employee, stocking shelves.");
    // this->locations[marketplaceIndex].add_npc(marketplaceEmployee);

    // // Kirkhof Center
    // NPC studiousStudent = NPC("Studious Student",
    //                           "A student, studying at a table.");
    // this->locations[kirkhofCenterIndex].add_npc(studiousStudent);

    // // Clock Tower

    // // Henry Hall
    // NPC vendingMachineStocker = NPC("Vending Machine Stocker",
    //                                 "A student employee, stocking vending machines.");
    // this->locations[henryHallIndex].add_npc(vendingMachineStocker);
    // // Laker Village

    // // Kirkhof Center Parking Lot

    // // Woods
    // NPC elf = NPC("Elf",
    //               "The elf that lives in the woods. It is very hungry.");
    // this->locations[woodsIndex].add_npc(elf);

//set all locations npcs and items to their storage values
   
    // // locations iterator
    // std::vector<std::reference_wrapper<Location> >::iterator locations_iterator = this->locations.begin();
    // while (locations_iterator != this->locations.end())
    // {
    //     // set items
    //     (*locations_iterator).get().set_items((*locations_iterator).get().get_items_storage());
    //     // set npcs
    //     (*locations_iterator).get().set_npcs((*locations_iterator).get().get_npcs_storage());
    //     // increment iterator
    //     locations_iterator++;
    // }




//add locs -> locations
// make neighbors

    

    // add locations to neighbors
    // neighbors
    // make temporary vectors for each location's neighbors

    // Laker Village:
    // East: Blue Connection
    // Northeast: Kirkhof Center Parking Lot
    locations[lakerVillageIndex].get().add_location("East", locations[blueConnectionIndex]);
    locations[lakerVillageIndex].get().add_location("Northeast", locations[kirkhofCenterParkingLotIndex]);

    // Blue Connection:
    // West: Laker Village
    // North: Kirkhof Center Parking Lot
    locations[blueConnectionIndex].get().add_location("West", locations[lakerVillageIndex]);
    locations[blueConnectionIndex].get().add_location("North", locations[kirkhofCenterParkingLotIndex]);

    // Kirkhof Center Parking Lot:
    // South: Blue Connection
    // Southwest: Laker Village
    // North: Mary Idema Pew Library
    // Northeast: Kirkhof Center
    locations[kirkhofCenterParkingLotIndex].get().add_location("South", locations[blueConnectionIndex]);
    locations[kirkhofCenterParkingLotIndex].get().add_location("Southwest", locations[lakerVillageIndex]);
    // locations[kirkhofCenterParkingLotIndex].get().add_location("North", locations[maryIdemaPewLibraryIndex]);
    // locations[kirkhofCenterParkingLotIndex].get().add_location("Northeast", locations[kirkhofCenterIndex]);

    // // Mary Idema Pew Library:
    // // South: Kirkhof Center Parking Lot
    // // East: Kirkhof Center
    // // Northeast: Clock Tower
    // locations[maryIdemaPewLibraryIndex].get().add_location("South", locations[kirkhofCenterParkingLotIndex]);
    // locations[maryIdemaPewLibraryIndex].get().add_location("East", locations[kirkhofCenterIndex]);
    // locations[maryIdemaPewLibraryIndex].get().add_location("Northeast", locations[clockTowerIndex]);

    // // Kirkhof Center:
    // // Southwest: Kirkhof Center Parking Lot
    // // West: Mary Idema Pew Library
    // // North: Clock Tower
    // locations[kirkhofCenterIndex].get().add_location("Southwest", locations[kirkhofCenterParkingLotIndex]);
    // locations[kirkhofCenterIndex].get().add_location("West", locations[maryIdemaPewLibraryIndex]);
    // locations[kirkhofCenterIndex].get().add_location("North", locations[clockTowerIndex]);

    // // Clock Tower:
    // // Southwest: Mary Idema Pew Library
    // // South: Kirkhof Center
    // // North: Henry Hall
    // locations[clockTowerIndex].get().add_location("Southwest", locations[maryIdemaPewLibraryIndex]);
    // locations[clockTowerIndex].get().add_location("South", locations[kirkhofCenterIndex]);
    // locations[clockTowerIndex].get().add_location("North", locations[henryHallIndex]);

    // // Henry Hall:
    // // South: Clock Tower
    // // Northwest: Marketplace
    // // Northeast: Fresh
    // locations[henryHallIndex].get().add_location("South", locations[clockTowerIndex]);
    // locations[henryHallIndex].get().add_location("Northwest", locations[marketplaceIndex]);
    // locations[henryHallIndex].get().add_location("Northeast", locations[freshIndex]);

    // // Marketplace:
    // // Southest: Henry Hall
    // locations[marketplaceIndex].get().add_location("Southeast", locations[henryHallIndex]);

    // // Fresh:
    // // Southwest: Henry Hall
    // // North: Mackinac Hall
    // // East: Woods
    // locations[freshIndex].get().add_location("Southwest", locations[henryHallIndex]);
    // locations[freshIndex].get().add_location("North", locations[mackinacHallIndex]);
    // locations[freshIndex].get().add_location("East", locations[woodsIndex]);

    // // Mackinac Hall:
    // // South: Fresh
    // // Southeast: Woods
    // locations[mackinacHallIndex].get().add_location("South", locations[freshIndex]);
    // locations[mackinacHallIndex].get().add_location("Southeast", locations[woodsIndex]);

    // // Woods:
    // // West: Fresh
    // // Northwest: Mackinac Hall
    // locations[woodsIndex].get().add_location("West", locations[freshIndex]);
    // locations[woodsIndex].get().add_location("Northwest", locations[mackinacHallIndex]);



    

    // iterator for locations
    // loop through locations
    // add them to ref_locations
    // std::vector<Location>::iterator locations_iterator = this->locations.begin();
    // while (locations_iterator != this->locations.end())
    // {
    //     // add location to ref_locations
    //     this->ref_locations.push_back(*locations_iterator);
    //     // increment iterator
    //     locations_iterator++;
    // }
    //this->ref_locations = std::vector<std::reference_wrapper<Location> >(this->locations.begin(), this->locations.end());


}

// setup commands function
// creates a map of commands
// keys are strings of commands
// values are names of functions

// std::map<std::string, void(*)(std::vector<std::string>)> Game::setup_commands() {
std::map<std::string, void (Game::*)()> Game::setup_commands()
{
    // std::map<std::string,  > Game::setup_commands() {
    // std::map<std::string, void(Game::*)(std::vector<std::string>)> Game::setup_commands() {
    // create map
    // std::map<std::string, void(*)(std::vector<std::string>)> commands;
    // std::map<std::string, void(Game::*)(std::vector<std::string>)> commands;
    // std::map<std::string, (Game::*)(std::vector<std::string>)> commands;
    // std::map<std::string, void(*)(std::vector<std::string>)> commands;
    // std::map<std::string, std::function<void(std::vector<std::string>)>> commands;
    std::map<std::string, void (Game::*)()> commands;
    // add commands

    // make sure func call matches commands format
    commands["help"] = (&Game::show_help);
    // commands["help"] = show_help;
    // commands["help"] = [this](std::vector<std::string> args) {this->show_help();};

    // commands["help"] = (&Game::show_help)[{}];
    // commands["help"] = &(Game::show_help);
    //  commands["?"] = (void(*)(std::vector<std::string>))&Game::show_help;
    //  commands["talk"] = (void(*)(std::vector<std::string>))&Game::talk;
    //  commands["hello"] = (void(*)(std::vector<std::string>))&Game::talk;
    //  commands["meet"] = (void(*)(std::vector<std::string>))&Game::meet;
    //  commands["introduce"] = (void(*)(std::vector<std::string>))&Game::meet;
    //  commands["take"] = (void(*)(std::vector<std::string>))&Game::take;
    //  commands["grab"] = (void(*)(std::vector<std::string>))&Game::take;
    //  commands["give"] = (void(*)(std::vector<std::string>))&Game::give;
    //  commands["deliver"] = (void(*)(std::vector<std::string>))&Game::give;
    //  commands["drop"] = (void(*)(std::vector<std::string>))&Game::give;
    //  commands["go"] = (void(*)(std::vector<std::string>))&Game::go;
    //  commands["move"] = (void(*)(std::vector<std::string>))&Game::go;
    //  commands["look"] = (void(*)(std::vector<std::string>))&Game::look;
    //  commands["search"] = (void(*)(std::vector<std::string>))&Game::look;
    //  commands["find"] = (void(*)(std::vector<std::string>))&Game::look;
    //  commands["items"] = (void(*)(std::vector<std::string>))&Game::show_items;
    //  commands["inventory"] = (void(*)(std::vector<std::string>))&Game::show_items;
    //  commands["quit"] = (void(*)(std::vector<std::string>))&Game::quit;
    //  commands["exit"] = (void(*)(std::vector<std::string>))&Game::quit;
    return commands;
}

// random location function
// selects a random location from locations vector
Location& Game::random_location()
{
    // copilot code
    // random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, this->locations.size() - 1);
    // get random index
    int random_index = dis(gen);
    // return location at random index
    return this->locations[random_index];
    //return this->locations[random_index];
}

// play function
void Game::play()
{
    // print game message
    std::cout << "Welcome to the GVSU Survival Game!" << std::endl;
    std::cout << "The campus is in danger! The elf in the woods behind campus\
    has threatened to destroy the campus unless it gets 500 calories of food!"
              << std::endl;
    std::cout << "You must collect food items and bring them to the elf in the woods." << std::endl;
    std::cout << "The elf will not accept inedible items, and will teleport you to a random location if you give it one." << std::endl;
    std::cout << "You can only carry 30 pounds at a time, so you may need to make multiple trips." << std::endl;
    std::cout << "Once the elf has enough calories, it will save campus and the game will end." << std::endl;
    std::cout << "Type 'help' or '?' for a list of commands." << std::endl;
    // call setup commands
    // this->setup_commands();
    // while game is in progress
    while (this->game_in_progress)
    {
        // prompt user for command
        std::cout << "What is your command?" << std::endl;
        // get user input
        // std::string user_input;
        std::vector<std::string> tokens;
        // std::getline(std::cin, user_input);
        std::string token;
        while (std::getline(std::cin, token, ' '))
        {
            tokens.push_back(token);
        }

        // tokenize input

        // get command
        std::string command = tokens[0];
        // remove command from tokens
        tokens.erase(tokens.begin());
        // get target
        // tokens iterator
        // std::vector<std::string>::iterator tokens_iterator = tokens.begin();
        // loop over tokens to make target
        std::vector<std::string> target = tokens;

        // call command function
        // check if command exists
        if (this->commands.find(command) != this->commands.end())
        {
            // call command function
            this->commands.find(command)->second;
        }
        else
        {
            // print message
            std::cout << "Command not found." << std::endl;
        }
    }
    // check if elf got enough calories
    if (this->calories_needed <= 0)
    {
        // print success message
        std::cout << "The elf has saved campus! You win!" << std::endl;
    }
    else
    {
        // print failure message
        std::cout << "The elf has destroyed campus! You lose!" << std::endl;
    }
}

// show help function
void Game::show_help()
{
    // print help message
    std::cout << "Commands:" << std::endl;
    std::cout << "help or ? - show this message" << std::endl;
    std::cout << "talk or hello - talk to an NPC" << std::endl;
    std::cout << "meet or introduce - get a description of an NPC" << std::endl;
    std::cout << "take or grab - take an item from the current location" << std::endl;
    std::cout << "give or deliver - give an item to the current location" << std::endl;
    std::cout << "go or move - go to a neighboring location" << std::endl;
    std::cout << "look or search or find - look around the current location" << std::endl;
    std::cout << "items or inventory - show the items you are carrying" << std::endl;
    std::cout << "quit or exit - quit the game" << std::endl;
    // print time
    // get current time
    time_t current_time = time(0);

    // convert to string
    std::string current_time_string = ctime(&current_time);
    // print time
    std::cout << "The current time is: " << current_time_string << std::endl;
}

// convert vector of strings to string
std::string Game::strvector_to_str(std::vector<std::string> target)
{
    // target iterator
    std::vector<std::string>::iterator target_iterator = target.begin();
    std::string target_string = "";
    while (target_iterator != target.end())
    {
        target_string += *target_iterator;
        if (target_iterator != target.end() - 1)
        {
            target_string += " ";
        }
        target_iterator++;
    }
    return target_string;
}

// talk function
// add print if not in room
void Game::talk(std::vector<std::string> target)
{
    // convert target to string
    std::string target_npc = strvector_to_str(target);

    // check if target is in room
    //std::vector<std::reference_wrapper<NPC> > npcs = this->current_location.get_npcs();
    std::vector<NPC> npcs = this->current_location.get_npcs();
    // npc iterator
    //std::vector<std::reference_wrapper<NPC> >::iterator npc_iterator = npcs.begin();
    std::vector<NPC>::iterator npc_iterator = npcs.begin();
    // loop over npcs
    while (npc_iterator != npcs.end())
    {
        // check if npc name matches target
        if (npc_iterator->get_name() == target_npc)
        {
            // get message from npc
            std::string message = npc_iterator->get_currentMessage();
            // print message
            std::cout << message << std::endl;
            // break from loop
            break;
        }
        // increment iterator
        npc_iterator++;
    }

    // get_message from npc
    // print message
}

// meet function
// add print if not in room
void Game::meet(std::vector<std::string> target)
{
    // convert target to string
    std::string target_npc = strvector_to_str(target);

    // check if target is in room
    //std::vector<std::reference_wrapper<NPC> > npcs = this->current_location.get_npcs();
    std::vector<NPC> npcs = this->current_location.get_npcs();
    // npc iterator
    //std::vector<std::reference_wrapper<NPC> >::iterator npc_iterator = npcs.begin();
    std::vector<NPC>::iterator npc_iterator = npcs.begin();
    // loop over npcs
    while (npc_iterator != npcs.end())
    {
        // check if npc name matches target
        if (npc_iterator->get_name() == target_npc)
        {
            // get description from npc
            std::string description = npc_iterator->get_description();
            // print description
            std::cout << description << std::endl;
            // break from loop
            break;
        }
        // increment iterator
        npc_iterator++;
    }
}

// take function
// add print if not in room
void Game::take(std::vector<std::string> target)
{
    // convert target to string
    std::string target_npc = strvector_to_str(target);

    // check if target item is in room
    //std::vector<std::reference_wrapper<Item> > items = this->current_location.get_items();
    std::vector<Item> items = this->current_location.get_items();
    // item iterator
    //std::vector<std::reference_wrapper<Item> >::iterator item_iterator = items.begin();
    std::vector<Item>::iterator item_iterator = items.begin();
    // loop over npcs
    while (item_iterator != items.end())
    {
        // check if item name matches target
        if (item_iterator->get_name() == target_npc)
        {
            // add to user inventory
            this->inventory.push_back(*item_iterator);
            // remove item from room
            this->current_location.remove_item(*item_iterator);
            // add weight to user's carry weight
            this->current_weight += item_iterator->get_weight();
        }
    }
}

// give function
void Game::give(std::vector<std::string> target)
{
    // convert target to string
    std::string target_item = strvector_to_str(target);

    // check if target item is in inventory
    // item iterator
    std::vector<Item>::iterator item_iterator = this->inventory.begin();
    // loop over npcs
    while (item_iterator != inventory.end())
    {
        // check if item name matches target
        if (item_iterator->get_name() == target_item)
        {
            // add to location inventory
            this->current_location.add_item(*item_iterator);
            // remove item from inventory
            // adapted from copilot code

            // may need to move this if it interferes with ability to access item
            this->inventory.erase(std::remove(inventory.begin(), inventory.end(), *item_iterator), inventory.end());
            // remove weight from user's carry weight
            this->current_weight -= item_iterator->get_weight();
            // check if current location is woods
            if (this->current_location.get_name() == "Woods")
            {
                // check if item is edible
                if (item_iterator->get_calories() > 0)
                {
                    // subtract calories from calories needed
                    this->calories_needed -= item_iterator->get_calories();
                    // remove item from current location
                    this->current_location.remove_item(*item_iterator);
                }
                else
                {
                    // teleport user to random location
                    this->current_location = this->random_location();
                }
            }
        }
    }
}

// go function
void Game::go(std::vector<std::string> target)
{
    // convert target to string
    std::string target_direction = strvector_to_str(target);
    // set current location to visited
    this->current_location.set_visited();
    // check if user is carrying too much weight
    if (this->current_weight > 30)
    {
        // print message
        std::cout << "You are carrying too much weight to move!" << std::endl;
        // return
        return;
    }
    else
    {
        // check if target direction is in neighbors
        std::map<std::string, std::reference_wrapper<Location>> neighbors = this->current_location.get_locations();
        // neighbor iterator
        std::map<std::string, std::reference_wrapper<Location>>::iterator neighbor_iterator = neighbors.begin();
        // loop over neighbors
        while (neighbor_iterator != neighbors.end())
        {
            // check if target direction is in neighbors map
            if (neighbor_iterator->first == target_direction)
            {
                // set current location to value
                // may need to change this
                this->current_location = neighbor_iterator->second.get();
                return;
            }
        }
    }
}

// show items
void Game::show_items(std::vector<std::string> target)
{
    // print items in inventory
    // item iterator
    std::vector<Item>::iterator item_iterator = this->inventory.begin();
    // loop over inventor
    while (item_iterator != this->inventory.end())
    {
        // print items
        std::cout << *item_iterator << std::endl;
    }
    // print current weight
    std::cout << "You are carrying " << this->current_weight << " pounds." << std::endl;
}

// look function
void Game::look(std::vector<std::string> target)
{
    // print current location/neighbors/items/npcs
    std::cout << this->get_current_location() << std::endl;
}

// quit function
void Game::quit(std::vector<std::string> target)
{
    // set game in progress to false
    this->game_in_progress = false;
    // print message
    std::cout << "You have quit the game." << std::endl;
}

// get current location
Location& Game::get_current_location() const
{
    return this->current_location;
}

// get inventory
std::vector<Item> Game::get_inventory() const
{
    return this->inventory;
}

// get current weight
int Game::get_current_weight() const
{
    return this->current_weight;
}

// get calories needed
int Game::get_calories_needed() const
{
    return this->calories_needed;
}

// get game in progress
bool Game::get_game_in_progress() const
{
    return this->game_in_progress;
}

// get locations
std::vector<Location> Game::get_locs() const
{
    return this->locs;
}
std::vector<std::reference_wrapper<Location>> Game::get_locations()
{
    return this->locations;
}
