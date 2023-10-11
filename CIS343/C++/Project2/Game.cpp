// Author: Richard Roy
// Date: 10/10/23

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
#include <sstream>

// constructor
Game::Game()
{
    // Initialize the game with default settings
    // create command map
    this->commands = this->setup_commands();
    // create world
    this->create_world();
    // set default values
    // move player to random location
    this->current_location = this->random_location();
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
    Location maryIdemaPewLibrary("Mary Idema Pew Library",
                                 "The campus library. There are books,\
 computers, and places to study.");
    this->locs.push_back(maryIdemaPewLibrary);
    long unsigned int maryIdemaPewLibraryIndex = this->locs.size() - 1;

    // Mackinac Hall (labyrinth)
    // 4 wings, varying floors
    Location mackinacHall("Mackinac Hall",
                          "The home of the CIS department...and others\
, the bane of freshman.");
    this->locs.push_back(mackinacHall);
    long unsigned int mackinacHallIndex = this->locs.size() - 1;

    // Laker Village (houses are boarded up (1 location))
    Location lakerVillage("Laker Village",
                          "A compound of on-campus town houses,\
 currently abandoned. You notice boards on all the windows and\
 doors.");
    this->locs.push_back(lakerVillage);
    long unsigned int lakerVillageIndex = this->locs.size() - 1;

    // Blue Connection
    // 2 floors
    Location blueConnection("Blue Connection",
                            "A common area with a small food-court\
 and a convenience store.");
    this->locs.push_back(blueConnection);
    long unsigned int blueConnectionIndex = this->locs.size() - 1;

    // Kirkhof Center Parking Lot
    Location kirkhofCenterParkingLot("Kirkhof Center Parking Lot",
                                     "A once bustling center of\
 campus transport, now seemingly empty.");
    this->locs.push_back(kirkhofCenterParkingLot);
    long unsigned int kirkhofCenterParkingLotIndex = this->locs.size() - 1;

    // Clock Tower
    Location clockTower("Clock Tower",
                        "A large clock tower, the center of campus.");
    this->locs.push_back(clockTower);
    long unsigned int clockTowerIndex = this->locs.size() - 1;

    // Kirkhof Center
    // 2 floors?
    Location kirkhofCenter("Kirkhof Center",
                           "This building was once the pinnacle of\
 the campus commons, now decrepit.");
    this->locs.push_back(kirkhofCenter);
    long unsigned int kirkhofCenterIndex = this->locs.size() - 1;

    // Fresh
    // 2 floors
    Location fresh("Fresh",
                   "A buffet-style cafeteria.");
    this->locs.push_back(fresh);
    long unsigned int freshIndex = this->locs.size() - 1;

    // Marketplace
    // 1 floor (2 rooms)
    Location marketplace("Marketplace",
                         "Along the main road of campus,\
 this building contains a small food court and the campus store.");
    this->locs.push_back(marketplace);
    long unsigned int marketplaceIndex = this->locs.size() - 1;

    // Henry Hall
    // 2 floors?
    Location henryHall("Henry Hall",
                       "This building contains several \
computer labs.");
    this->locs.push_back(henryHall);
    long unsigned int henryHallIndex = this->locs.size() - 1;

    // Woods
    Location woods("Woods",
                   "A small patch of woods behind campus. \
The elf lives here.");
    this->locs.push_back(woods);
    long unsigned int woodsIndex = this->locs.size() - 1;

    // end of base locations creation
    
    // create items
    // food items

    // connection
    Item connectionSandwich = Item("Chicken Sandwich",
                                   "Spicy and crispy chicken sandwich,\
 the pinnacle of campus food",
                                   55, 1);
    this->locs[blueConnectionIndex].add_item(connectionSandwich);
    Item lakerBowl = Item("Laker Bowl",
                          "The legendary Laker Bowl, popcorn chicken,\
 mashed potatoes, corn, and gravy",
                          50, 1.5);
    this->locs[blueConnectionIndex].add_item(lakerBowl);
    Item italianSub = Item("Italian Sub",
                           "A classic Italian sub, with ham, salami,\
 pepperoni, and provolone.",
                           45, 1);
    this->locs[blueConnectionIndex].add_item(italianSub);
    Item energyBarConnection = Item("Connection Energy Bar",
                                    "A protein bar.", 10, .5);
    this->locs[blueConnectionIndex].add_item(energyBarConnection);
    Item bagOfChipsConnection = Item("Connection Barbecue Chips",
                                     "A bag of delicious\
 barbecue chips.", 10, .5);
    this->locs[blueConnectionIndex].add_item(bagOfChipsConnection);
    Item coffeeConnection = Item("Connection Coffee",
                                 "The lifeblood of college\
 students.", 10, .5);
    this->locs[blueConnectionIndex].add_item(coffeeConnection);

    // fresh
    Item freshPizza = Item("Pizza",
                           "A slice of cheese pizza.", 50, 1);
    this->locs[freshIndex].add_item(freshPizza);
    Item freshBurger = Item("Burger",
                            "A cold cheeseburger.", 40, 1);
    this->locs[freshIndex].add_item(freshBurger);
    Item freshSalad = Item("Salad",
                           "A caesar salad.", 25, 1);
    this->locs[freshIndex].add_item(freshSalad);
    Item coffeeFresh = Item("Fresh Coffee",
                            "The lifeblood of college\
 students.", 10, .5);
    this->locs[freshIndex].add_item(coffeeFresh);

    // marketplace
    Item marketplaceRamen = Item("Ramen",
                                 "A cup of ramen.", 45, .5);
    this->locs[marketplaceIndex].add_item(marketplaceRamen);
    Item marketplaceSushi = Item("Sushi",
                                 "A tray of old sushi.\
 It's probably still good...", 20, 1);
    this->locs[marketplaceIndex].add_item(marketplaceSushi);
    Item coffeeMarketplace = Item("Marketplace Coffee",
                                  "The lifeblood of college\
 students.", 10, .5);
    this->locs[marketplaceIndex].add_item(coffeeMarketplace);

    // mackinacHall
    Item energyBarMac = Item("Mackinac Energy Bar",
                             "A protein bar.", 10, .5);
    this->locs[mackinacHallIndex].add_item(energyBarMac);
    Item bagOfChipsMac = Item("Mackinac Barbecue Chips",
                              "A bag of delicious\
 barbecue chips.", 10, .5);
    this->locs[mackinacHallIndex].add_item(bagOfChipsMac);
    Item coffeeMac = Item("Mackinac Coffee",
                          "The lifeblood of\
 college students.", 10, .5);
    this->locs[mackinacHallIndex].add_item(coffeeMac);

    // kirhofCenter
    Item trailMixKirkhof = Item("Kirkhof Trail Mix",
                                "A bag of trail mix.\
 Contains peanuts.", 10, .5);
    this->locs[kirkhofCenterIndex].add_item(trailMixKirkhof);
    Item coffeeKirkhof = Item("Kirkhof Coffee",
                              "The lifeblood of\
 college students.", 10, .5);
    this->locs[kirkhofCenterIndex].add_item(coffeeKirkhof);

    // clockTower
    Item trailMixClockTower = Item("Clock Tower Trail Mix",
                                   "A bag of trail mix.\
 Contains peanuts.", 10, .5);
    this->locs[clockTowerIndex].add_item(trailMixClockTower);

    // henryHall
    Item bagOfChipsHenry = Item("Henry Hall Barbecue Chips",
                                "A bag of delicious\
 barbecue chips.", 10, .5);
    this->locs[henryHallIndex].add_item(bagOfChipsHenry);
    Item trailMixHenry = Item("Henry Hall Trail Mix",
                              "A bag of trail mix.\
 Contains peanuts.", 10, .5);
    this->locs[henryHallIndex].add_item(trailMixHenry);
    Item coffeeHenry = Item("Henry Hall Coffee",
                            "The lifeblood of\
 college students.", 10, .5);
    this->locs[henryHallIndex].add_item(coffeeHenry);

    // lakerVillage
    Item energyBarVillage = Item("Village Energy Bar",
                                 "A protein bar.", 10, .5);
    this->locs[lakerVillageIndex].add_item(energyBarVillage);
    Item bagOfChipsVillage = Item("Village Barbecue Chips",
                                  "A bag of delicious\
 barbecue chips.", 10, .5);
    this->locs[lakerVillageIndex].add_item(bagOfChipsVillage);
    Item cheatFood1000 = Item("Test Food1000",
                          "All the calories you could ever\
 need.", 1000, 1);
    this->locs[lakerVillageIndex].add_item(cheatFood1000);
    Item cheatFood500 = Item("Test Food500",
                          "All the calories you could ever\
need.", 500, 1);
    this->locs[lakerVillageIndex].add_item(cheatFood500);
    Item dumbell = Item("Dumbell100",
"Good luck carrying this.", 0, 100);
    this->locs[lakerVillageIndex].add_item(dumbell);
    Item dumbell2 = Item("Dumbell30",
"Good luck carrying this.", 0, 30);
    this->locs[lakerVillageIndex].add_item(dumbell2);

    // kirkhofCenterParkingLot
    Item bagOfChipsParking = Item("Parking Barbecue Chips",
                                  "A bag of delicious\
 barbecue chips.", 10, .5);
    this->locs[kirkhofCenterParkingLotIndex].add_item(
        bagOfChipsParking);
    Item trailMixParking = Item("Parking Trail Mix",
                                "A bag of trail mix.\
 Contains peanuts.", 10, .5);
    this->locs[kirkhofCenterParkingLotIndex].add_item(trailMixParking);

    // Mary Idema Pew Library
    Item bagOfChipsLibrary = Item("Library Barbecue Chips",
                                  "A bag of delicious\
 barbecue chips.", 10, .5);
    this->locs[maryIdemaPewLibraryIndex].add_item(
        bagOfChipsLibrary);
    Item trailMixLibrary = Item("Library Trail Mix",
                                "A bag of trail mix.\
 Contains peanuts.", 10, .5);
    this->locs[maryIdemaPewLibraryIndex].add_item(trailMixLibrary);
    Item coffeeLibrary = Item("Library Coffee",
                              "The lifeblood of\
 college students.", 10, .5);
    this->locs[maryIdemaPewLibraryIndex].add_item(coffeeLibrary);

    // nonfood items

    // connection
    Item missingStudentID = Item("Missing Student ID",
                                 "A student ID, the owner\
 is nowhere to be found.", 0, .5);
    this->locs[blueConnectionIndex].add_item(missingStudentID);
    Item penConnection = Item("Connection Pen",
                              "A ballpoint pen, writes\
 surprisingly well. Blue ink", 0, .5);
    this->locs[blueConnectionIndex].add_item(penConnection);

    // fresh
    Item droppedFork = Item("Dirty fork",
                            "A dirty fork, dropped by\
 a careless student.", 0, .5);
    this->locs[freshIndex].add_item(droppedFork);
    Item penFresh = Item("Fresh Pen",
                         "A ballpoint pen, writes\
 surprisingly well. Blue ink", 0, .5);
    this->locs[freshIndex].add_item(penFresh);

    // marketplace
    Item claTextbook = Item("CLA 250 Textbook",
                            "Greek and Roman Art\
 and Architecture", 0, 2);
    this->locs[marketplaceIndex].add_item(claTextbook);

    // mackinacHall
    Item pencilMac = Item("Mackinac Pencil",
                          "A #2 pencil, tool\
 of choice for scantrons.", 0, .5);
    this->locs[mackinacHallIndex].add_item(pencilMac);
    Item penMac = Item("Mackinac Pen",
                       "A ballpoint pen, writes\
 surprisingly well. Blue ink", 0, .5);
    this->locs[mackinacHallIndex].add_item(penMac);

    // kirhofCenter
    Item pencilKirkhof = Item("Kirkhof Pencil",
                              "A #2 pencil, tool\
 of choice for scantrons.", 0, .5);
    this->locs[kirkhofCenterIndex].add_item(pencilKirkhof);

    // henryHall
    Item pencilHenry = Item("Henry Hall Pencil",
                            "A #2 pencil, tool\
 of choice for scantrons.", 0, .5);
    this->locs[henryHallIndex].add_item(pencilHenry);

    // kirkhofCenterParkingLot
    Item penParking = Item("Parking Pen",
                           "A ballpoint pen, writes\
 surprisingly well. Blue ink", 0, .5);
    this->locs[kirkhofCenterParkingLotIndex].add_item(penParking);

    // Mary Idema Pew Library
    Item pencilLibrary = Item("Library Pencil",
                              "A #2 pencil, tool\
 of choice for scantrons.", 0, .5);
    this->locs[maryIdemaPewLibraryIndex].add_item(pencilLibrary);
    Item penLibrary = Item("Library Pen",
                           "A ballpoint pen, writes\
 surprisingly well. Blue ink", 0, .5);
    this->locs[maryIdemaPewLibraryIndex].add_item(penLibrary);
    Item missingNotebook = Item("Notebook",
                                "A misplaced notebook,\
     the owner must be looking for this...",
                                0, 1);
    this->locs[maryIdemaPewLibraryIndex].add_item(missingNotebook);


    // create npcs

    // Mackinac Hall
    NPC studentNoTextbook = NPC(
        "Frantic Student",
        "A stressed student,\
 they seem to be looking for something...");
    studentNoTextbook.set_messages({
"Have you seen my textbook? I can't find it anywhere!",
"I need to find my textbook, I have a test tomorrow!",
"I can't find my textbook, I'm going to fail my test!"});
    this->locs[mackinacHallIndex].add_npc(studentNoTextbook);

    // Library
    NPC libraryDeskWorker = NPC(
        "Library Desk Worker",
        "A student employee, sitting idly at the main desk.");
    libraryDeskWorker.set_messages({
"Welcome to the library, how can I help you?",
"How are you today?",
"Have you heard? Apparently there is an elf in the northern woods\
 that can save campus!"});
    this->locs[maryIdemaPewLibraryIndex].add_npc(libraryDeskWorker);

    // Fresh
    NPC freshEmployee = NPC(
        "Fresh Employee",
        "A student employee, checking student IDs at the door.");
    freshEmployee.set_messages({
"Welcome to Fresh, can I see your student ID?",
"An elf in the north woods? As if!",
"I'm so hungry, I wish I could eat some of this food..."});
    this->locs[freshIndex].add_npc(freshEmployee);
    NPC studentNoID = NPC(
        "Stressed Student",
        "A student trying to get into Fresh, they seem\
 to have misplaced their student ID.");
    studentNoID.set_messages({
"I can't find my student ID, I must have dropped it somewhere...",
"I need to find my student ID, I'm starving!",
"I can't find my student ID, I'm going to starve!"});
    this->locs[freshIndex].add_npc(studentNoID);

    // Blue Connection
    NPC connectionEmployee = NPC(
        "Connection Employee",
        "A student employee, taking orders at the counter.");
    connectionEmployee.set_messages({
"Welcome to the Blue Connection, what can I get for you?",
"The campus has been in disarray since the incident\
 if only someone could save us...",
"I'm so hungry, I wish I could eat some of this food..."});
    this->locs[blueConnectionIndex].add_npc(connectionEmployee);

    // Marketplace
    NPC marketplaceEmployee = NPC(
        "Marketplace Employee",
        "A student employee, stocking shelves.");
    marketplaceEmployee.set_messages({
"Welcome to the Marketplace, what can I get for you?",
"Rumors of an elf in the woods? I don't believe it.",
"I'm so hungry, I wish I could eat some of this food..."});
    this->locs[marketplaceIndex].add_npc(marketplaceEmployee);

    // Kirkhof Center
    NPC studiousStudent = NPC(
        "Studious Student",
        "A student, studying at a table.");
    studiousStudent.set_messages({
"Have you seen the elf in the woods? He's our only hope!",
"I'm so hungry, I wish I could eat some of this food..."});
    this->locs[kirkhofCenterIndex].add_npc(studiousStudent);

    // Clock Tower

    // Henry Hall
    NPC vendingMachineStocker = NPC(
        "Vending Machine Stocker",
        "A student employee, stocking vending machines.");
    vendingMachineStocker.set_messages({
"Welcome to Henry Hall, what can I get for you?",
"I've heard strange noises coming from the woods near Fresh...",
"I'm so hungry, I wish I could eat some of this food..."});
    this->locs[henryHallIndex].add_npc(vendingMachineStocker);
    
    // Laker Village

    // Kirkhof Center Parking Lot

    // Woods
    NPC elf = NPC(
        "Elf",
        "The elf that lives in the woods. It is very hungry.");
    elf.set_messages({
"I am the elf of the woods, I can save campus, but I need food.\
 Please bring me food.",
"Don't waste my time unless you have food.",
"I'm so hungry, I wish I could eat some of this food..."});
    this->locs[woodsIndex].add_npc(elf);



    this->locations = std::vector<std::reference_wrapper<Location> 
    >(this->locs.begin(), this->locs.end());


    // make neighbors

    // Laker Village:
    // East: Blue Connection
    // Northeast: Kirkhof Center Parking Lot
    locations[lakerVillageIndex].get().add_location(
        "East", locations[blueConnectionIndex]);
    locations[lakerVillageIndex].get().add_location(
        "Northeast", locations[kirkhofCenterParkingLotIndex]);

    // Blue Connection:
    // West: Laker Village
    // North: Kirkhof Center Parking Lot
    locations[blueConnectionIndex].get().add_location(
        "West", locations[lakerVillageIndex]);
    locations[blueConnectionIndex].get().add_location(
        "North", locations[kirkhofCenterParkingLotIndex]);

    // Kirkhof Center Parking Lot:
    // South: Blue Connection
    // Southwest: Laker Village
    // North: Mary Idema Pew Library
    // Northeast: Kirkhof Center
    locations[kirkhofCenterParkingLotIndex].get().add_location(
        "South", locations[blueConnectionIndex]);
    locations[kirkhofCenterParkingLotIndex].get().add_location(
        "Southwest", locations[lakerVillageIndex]);
    locations[kirkhofCenterParkingLotIndex].get().add_location(
        "North", locations[maryIdemaPewLibraryIndex]);
    locations[kirkhofCenterParkingLotIndex].get().add_location(
        "Northeast", locations[kirkhofCenterIndex]);

    // Mary Idema Pew Library:
    // South: Kirkhof Center Parking Lot
    // East: Kirkhof Center
    // Northeast: Clock Tower
    locations[maryIdemaPewLibraryIndex].get().add_location(
        "South", locations[kirkhofCenterParkingLotIndex]);
    locations[maryIdemaPewLibraryIndex].get().add_location(
        "East", locations[kirkhofCenterIndex]);
    locations[maryIdemaPewLibraryIndex].get().add_location(
        "Northeast", locations[clockTowerIndex]);

    // Kirkhof Center:
    // Southwest: Kirkhof Center Parking Lot
    // West: Mary Idema Pew Library
    // North: Clock Tower
    locations[kirkhofCenterIndex].get().add_location(
        "Southwest", locations[kirkhofCenterParkingLotIndex]);
    locations[kirkhofCenterIndex].get().add_location(
        "West", locations[maryIdemaPewLibraryIndex]);
    locations[kirkhofCenterIndex].get().add_location(
        "North", locations[clockTowerIndex]);

    // Clock Tower:
    // Southwest: Mary Idema Pew Library
    // South: Kirkhof Center
    // North: Henry Hall
    locations[clockTowerIndex].get().add_location(
        "Southwest", locations[maryIdemaPewLibraryIndex]);
    locations[clockTowerIndex].get().add_location(
        "South", locations[kirkhofCenterIndex]);
    locations[clockTowerIndex].get().add_location(
        "North", locations[henryHallIndex]);

    // Henry Hall:
    // South: Clock Tower
    // Northwest: Marketplace
    // Northeast: Fresh
    locations[henryHallIndex].get().add_location(
        "South", locations[clockTowerIndex]);
    locations[henryHallIndex].get().add_location(
        "Northwest", locations[marketplaceIndex]);
    locations[henryHallIndex].get().add_location(
        "Northeast", locations[freshIndex]);

    // Marketplace:
    // Southest: Henry Hall
    locations[marketplaceIndex].get().add_location(
        "Southeast", locations[henryHallIndex]);

    // Fresh:
    // Southwest: Henry Hall
    // North: Mackinac Hall
    // East: Woods
    locations[freshIndex].get().add_location(
        "Southwest", locations[henryHallIndex]);
    locations[freshIndex].get().add_location(
        "North", locations[mackinacHallIndex]);
    locations[freshIndex].get().add_location(
        "East", locations[woodsIndex]);

    // Mackinac Hall:
    // South: Fresh
    // Southeast: Woods
    locations[mackinacHallIndex].get().add_location(
        "South", locations[freshIndex]);
    locations[mackinacHallIndex].get().add_location(
        "Southeast", locations[woodsIndex]);

    // Woods:
    // West: Fresh
    // Northwest: Mackinac Hall
    locations[woodsIndex].get().add_location(
        "West", locations[freshIndex]);
    locations[woodsIndex].get().add_location(
        "Northwest", locations[mackinacHallIndex]);
}

// setup commands function
// creates a map of commands
// keys are strings of commands
// values are names of functions
std::map<std::string, std::function<void(std::vector<std::string>)> 
> Game::setup_commands()
{
    std::map<std::string, std::function<void(
        std::vector<std::string>)> > commandMap;
    // ChatGpt code vvvvv

    commandMap["help"] = std::bind(
        &Game::show_help, this, std::placeholders::_1);
    commandMap["?"] = std::bind(
        &Game::show_help, this, std::placeholders::_1);
    //chatgpt code  vvvvv
    
    
    // talk
    commandMap["talk"] = std::bind(
        &Game::talk, this, std::placeholders::_1);
    

    // meet
    commandMap["meet"] = std::bind(
        &Game::meet, this, std::placeholders::_1);
    commandMap["greet"] = std::bind(
        &Game::meet, this, std::placeholders::_1);

    // take
    commandMap["take"] = std::bind(
        &Game::take, this, std::placeholders::_1);
    commandMap["grab"] = std::bind(
        &Game::take, this, std::placeholders::_1);

    // give
    commandMap["give"] = std::bind(
        &Game::give, this, std::placeholders::_1);
    commandMap["offer"] = std::bind(
        &Game::give, this, std::placeholders::_1);
    commandMap["feed"] = std::bind(
        &Game::give, this, std::placeholders::_1);
    commandMap["drop"] = std::bind(
        &Game::give, this, std::placeholders::_1);

    // go
    commandMap["go"] = std::bind(
        &Game::go, this, std::placeholders::_1);
    commandMap["move"] = std::bind(
        &Game::go, this, std::placeholders::_1);
    commandMap["walk"] = std::bind(
        &Game::go, this, std::placeholders::_1);
    commandMap["run"] = std::bind(
        &Game::go, this, std::placeholders::_1);
    commandMap["jog"] = std::bind(
        &Game::go, this, std::placeholders::_1);

    // show items
    commandMap["show"] = std::bind(
        &Game::show_items, this, std::placeholders::_1);
    commandMap["inventory"] = std::bind(
        &Game::show_items, this, std::placeholders::_1);
    commandMap["items"] = std::bind(
        &Game::show_items, this, std::placeholders::_1);

    // look
    commandMap["look"] = std::bind(
        &Game::look, this, std::placeholders::_1);
    commandMap["examine"] = std::bind(
        &Game::look, this, std::placeholders::_1);
    commandMap["inspect"] = std::bind(
        &Game::look, this, std::placeholders::_1);
    commandMap["search"] = std::bind(
        &Game::look, this, std::placeholders::_1);

    // quit
    commandMap["quit"] = std::bind(
        &Game::quit, this, std::placeholders::_1);
    commandMap["exit"] = std::bind(
        &Game::quit, this, std::placeholders::_1);


    // additional1: party
    commandMap["party"] = std::bind(
        &Game::party, this, std::placeholders::_1);
    commandMap["join"] = std::bind(
        &Game::party, this, std::placeholders::_1);
    commandMap["group"] = std::bind(
        &Game::party, this, std::placeholders::_1);
    commandMap["bring"] = std::bind(
        &Game::party, this, std::placeholders::_1);
    // additional2: leave party
    
    commandMap["leave"] = std::bind(
        &Game::leavePartyMember, this, std::placeholders::_1);
    commandMap["abandon"] = std::bind(
        &Game::leavePartyMember, this, std::placeholders::_1);
    commandMap["kick"] = std::bind(
        &Game::leavePartyMember, this, std::placeholders::_1);
    commandMap["ungroup"] = std::bind(
        &Game::leavePartyMember, this, std::placeholders::_1);
    return commandMap;
}

// Generate a random location index and return the corresponding location 
std::reference_wrapper<Location> Game::random_location()
{
    // copilot code
    // random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(
        0, (int)(this->locations.size() - 1));
    // get random index
    int random_index = dis(gen);
    // return location at random index
    return this->locations[(long unsigned int)random_index];
}

// play function
void Game::play()
{
    // print game message
    std::cout 
    << "Welcome to GVSU!" << std::endl;
    std::cout 
    << "Several years ago, a catastrophe struck campus." 
    << std::endl;
    std::cout
    << "A student, cramming for finals, opened a portal,"
    << std::endl;
    std::cout
    << "letting a demon onto campus to take his exams for him."
    << std::endl;
    std::cout
    << "Instead of doing his finals, the demon took over campus,"
    << std::endl;
    std::cout
    << "and implemented a horrendous food service system."
    << std::endl;
    std::cout
    << "Legend has it, that an elf lives in the northern woods,"
    << std::endl;
    std::cout
    << "and, if it is fed enough calories, it will be powerful enough"
    << std::endl;
    std::cout
    << "to defeat the demon and save campus."
    << std::endl;
    std::cout 
    << "You must collect food items and bring them"
    << std::endl;
    std::cout
    << "to the elf in the woods." 
    << std::endl;
    std::cout 
    << "The elf will not accept inedible items, and will teleport you"
    << std::endl;
    std::cout
    << "to a random location if you give it one." 
    << std::endl;
    std::cout 
    << "You can only carry 30 pounds at a time," 
    << std::endl; 
    std::cout 
    <<"so you may need to make multiple trips." 
    << std::endl;
    std::cout 
    << "Once the elf has enough calories," 
    << std::endl;
    std::cout
    << "it will save campus and the game will end." 
    << std::endl;
    std::cout 
    << "Type 'help' or '?' for a list of commands." 
    << std::endl;
    
    // while game is in progress
    while (this->game_in_progress)
    {
        // prompt user for command
        std::cout 
        << "----------------------------------------------------------"
        << std::endl;
        std::cout
        << "What is your command?" 
        << std::endl;
        std::cout
        << std::endl;
        std::string token;
        std::getline(std::cin, token);

        std::istringstream iss(token);
        std::string command;
        std::vector<std::string> target;

        iss >> command;

        std::string target_part;
        while(iss >> target_part) {
            target.push_back(target_part);
        }

        // call command function
        // check if command exists
        if (this->commands.find(command) != this->commands.end())
        {
            // call command function
            
            //std::cout << "Command found." << std::endl;
            std::cout
            << std::endl;
            commands[command](target);

            
        }
        else
        {
            // print message
            std::cout
            << std::endl;
            std::cout 
            << "Command not found." 
            << std::endl;
        }
    }
    // check if elf got enough calories
    if (this->calories_needed <= 0)
    {
        // print success message
        std::cout << "The elf has defeated the demon and saved campus! You Win!" << std::endl;
    }
    else
    {
        // print failure message
        std::cout << "The students are doomed with bad food for all eternity! You Lose!" << std::endl;
    }
}

// show help: prints a list of commands
void Game::show_help(std::vector<std::string> target)
{
    //get rid of unused target warning
    target[0] = target[0];
    
    // commands iterator
    std::map<std::string, std::function<void(std::vector<std::string>)> >::iterator commands_iterator = this->commands.begin();
    
    // print message
    std::cout << "Commands List: " << std::endl;
    
    // print all commands
    while (commands_iterator != this->commands.end())
    {
        // print command
        std::cout 
        << commands_iterator->first 
        << std::endl;
        commands_iterator++;
    }
    
    // get current time
    time_t current_time = time(0);

    // convert current_time to string
    std::string current_time_string = ctime(&current_time);
    
    // print current time
    std::cout 
    << "The current time is: " 
    << current_time_string << std::endl;
}

// convert vector of strings to single string
std::string Game::strvector_to_str(std::vector<std::string> target)
{
    // target iterator
    std::vector<std::string>::iterator target_iterator = target.begin();

    // target as a single string to return
    std::string target_string = "";

    // loop over target and concatenate to target_string with spaces
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

// talk to NPC function
void Game::talk(std::vector<std::string> target)
{
    // convert target to string
    std::string target_npc = strvector_to_str(target);

    // npc holder for iterator
    std::vector<std::reference_wrapper<NPC> > npcs = this->current_location.get().get_npcs_ref();
    // npc iterator
    std::vector<std::reference_wrapper<NPC> >::iterator npc_iterator = npcs.begin();
    
    // check if target is in location
    // loop over npcs
    while (npc_iterator != npcs.end())
    {
        // check if npc name matches target
        // npc found in location
        if (npc_iterator->get().get_name() == target_npc)
        {
            // get current message from npc
            std::string message = npc_iterator->get().get_currentMessage();
            // print message
            std::cout 
            << npc_iterator->get().get_name()
            << " says: "
            << message 
            << std::endl;
            return;
        }
        npc_iterator++;
    }
    // otherwise npc is not in location
    // print message
    std::cout
    << "You do not see "
    << target_npc
    << " here."
    << std::endl;
}

// meet function
void Game::meet(std::vector<std::string> target)
{
    // convert target to string
    std::string target_npc = strvector_to_str(target);

    // check if target is in location
    std::vector<NPC> npcs = this->current_location.get().get_npcs();
    // npc iterator
    std::vector<NPC>::iterator npc_iterator = npcs.begin();

    // check if target is in location
    // loop over npcs
    while (npc_iterator != npcs.end())
    {
        // check if npc name matches target
        // npc found in location
        if (npc_iterator->get_name() == target_npc)
        {
            // get description from npc
            std::string description = npc_iterator->get_description();
            // print description
            std::cout 
            << npc_iterator->get_name()
            << ": "
            << description 
            << std::endl;
            return;
        }
        npc_iterator++;
    }
    // otherwise npc is not in room
    // print message
    std::cout
    << "You do not see "
    << target_npc
    << " here."
    << std::endl;
}

// take function
void Game::take(std::vector<std::string> target)
{
    // convert target to string
    std::string target_item = strvector_to_str(target);

    // check if target item is in room
    std::vector<Item> items = this->current_location.get().get_items();
    
    // item iterator
    std::vector<Item>::iterator item_iterator = items.begin();

    // check if target is in location
    // loop over items
    while (item_iterator != items.end())
    {
        // check if item name matches target
        // item found in location
        if (item_iterator->get_name() == target_item)
        {
            // add item to player inventory and update carry weight
            this->inventory.push_back(*item_iterator);
            this->current_weight += item_iterator->get_weight();

            // remove item from location
            this->current_location.get().remove_item(*item_iterator);

            // inform player they picked up item
            std::cout
            << "You obtain "
            << item_iterator->get_name()
            << std::endl;
            std::cout
            << std::endl;

            // inform player of current carry weight
            std::cout
            << "You are now carrying "
            << this->current_weight
            << " pounds."
            << std::endl;
            return;
        }
        item_iterator++;
    }
    // otherwise item is not in room
    // print message
    std::cout
    << "You do not see "
    << target_item
    << " here."
    << std::endl;
}

// give function
void Game::give(std::vector<std::string> target)
{
    // convert target to string
    std::string target_item = strvector_to_str(target);

    // item holder for iterator
    std::vector<Item> items = this->inventory;
    // item iterator
    std::vector<Item>::iterator item_iterator = items.begin();

    // check if target item is in inventory
    // loop over npcs
    while (item_iterator != inventory.end())
    {
        // check if item name matches target
        // item found in inventory
        if (item_iterator->get_name() == target_item)
        {
            // add item to location items
            this->current_location.get().add_item(*item_iterator);

            // refresh reference wrapped locations vector
            // otherwise references to locations will be invalidated
            this->locations = std::vector<std::reference_wrapper<Location> 
            >(this->locs.begin(), this->locs.end());
            
            // adapted from copilot code
            // remove weight from user's carry weight
            this->current_weight -= item_iterator->get_weight();
            
            // check if current location is woods
            if (this->current_location.get().get_name() == "Woods")
            {
                // check if item is edible
                if (item_iterator->get_calories() > 0)
                {
                    // item is edible
                    // subtract calories from calories needed
                    this->calories_needed -= item_iterator->get_calories();

                    // remove item from current location
                    this->current_location.get().remove_item(*item_iterator);

                    // inform player they gave item to the elf
                    std::cout
                    << "You gave "
                    << item_iterator->get_name()
                    << " to the elf."
                    << std::endl;
                    std::cout
                    << std::endl;

                    // inform player of current weight
                    std::cout
                    << "You are now carrying "
                    << this->current_weight
                    << " pounds."
                    << std::endl;
                    std::cout
                    << std::endl;

                    // inform player of calories needed
                    std::cout
                    << "The elf needs "
                    << this->calories_needed
                    << " more calories."
                    << std::endl;
                    std::cout
                    << std::endl;

                    // check if elf has enough calories
                    // player wins the game and it ends if so
                    if (this->calories_needed <= 0)
                    {
                        // remove item from inventory
                        this->inventory.erase(std::remove(inventory.begin(), inventory.end(), *item_iterator), inventory.end());
                        // end game
                        this->game_in_progress = false;
                        return;
                    }
                }
                // item is not edible
                else
                {
                    // teleport user to random location
                    this->current_location = this->random_location();

                    // inform the player that the elf was not satisfied
                    std::cout
                    << "The elf was not satisfied with your offering."
                    << std::endl;
                    std::cout
                    << std::endl;

                    // inform player of new location
                    std::cout
                    << "The elf has teleported you away..."
                    << std::endl;
                    std::cout
                    << std::endl;
                    std::cout
                    << "Any party members were left behind."
                    << std::endl;
                    std::cout
                    << "You are now at "
                    << this->current_location.get().get_name()
                    << std::endl;
                }
            }
            // item is not in woods
            // item was dropped into location items
            else
            {
                // tell player they dropped item
                std::cout
                << "You dropped "
                << item_iterator->get_name()
                << std::endl;
            }

            // remove item from inventory
            this->inventory.erase(std::remove(inventory.begin(), inventory.end(), *item_iterator), inventory.end());
            return;
        }
        item_iterator++;
    }
    // otherwise item is not in inventory
    // print message
    std::cout
    << "You do not have "
    << target_item
    << " in your inventory."
    << std::endl;
}

// go to direction function
void Game::go(std::vector<std::string> target)
{
    // convert target to string
    std::string target_direction = strvector_to_str(target);

    // set current location to visited
    this->current_location.get().set_visited();

    // check if user is carrying too much weight
    if (this->current_weight > 30)
    {
        // print message
        std::cout 
        << "You are carrying too much weight to move! Drop something first!" 
        << std::endl;
        return;
    }
    // player is not carrying too much weight
    else
    {
        // holder for neighbors iterator
        std::map<std::string, std::reference_wrapper<Location> 
        > neighbors = this->current_location.get().get_locations();

        // neighbor iterator
        std::map<std::string, std::reference_wrapper<Location> 
        >::iterator neighbor_iterator = neighbors.begin();

        // check if target direction is in neighbors
        // loop over neighbors
        while (neighbor_iterator != neighbors.end())
        {
            // check if target direction is in neighbors map
            // target direction is in neighbors
            if (neighbor_iterator->first == target_direction)
            {
                // check npcs in current location for party members

                // bool to help with party member removal loop (finished moving)
                bool party_moved = false;

                while (party_moved == false)
                {
                    // bool to help with party member removal loop (continue loop if true)
                    bool party_member_found = false;
                    
                    // npc holder for iterator
                    std::vector<std::reference_wrapper<NPC> > npcs = this->current_location.get().get_npcs_ref();
                    
                    // npc iterator
                    std::vector<std::reference_wrapper<NPC> >::iterator npc_iterator = npcs.begin(); 
                    
                    // check if npc is party member
                    // loop over npcs
                    while (npc_iterator != npcs.end())
                    {
                        // check if npc is party member
                        if (npc_iterator->get().get_partyMember() == true)
                        {
                            // move npc to new location
                            neighbor_iterator->second.get().add_npc(npc_iterator->get());
                            
                            // refresh reference wrapped locations vector
                            this->locations = std::vector<std::reference_wrapper<Location>
                            >(this->locs.begin(), this->locs.end());
                            
                            // remove npc from current location
                            this->current_location.get().remove_npc(npc_iterator->get());
                            
                            // set party member found to true
                            party_member_found = true;
                            // breaks and uses party_member_found to
                            // refresh npc iterator since it was invalidated
                            break;
                        }
                        // npc is not party member
                        else
                        {
                            // check next npc in location
                            npc_iterator++;
                        }
                       
                    }
                    // check if party member was found
                    // otherwise, refresh npcs iterator
                    // and check again
                    if (party_member_found == false)
                    {
                        // end of party npcs loop
                        party_moved = true;
                    }
                }
                
                // moves player to new location
                this->current_location = neighbor_iterator->second.get();

                // print message
                std::cout
                << "You go "
                << target_direction
                << std::endl;
                std::cout
                << std::endl;
                std::cout
                << "You are now at "
                << this->current_location.get().get_name()
                << std::endl;
                return;
            }
            neighbor_iterator++;
        }
        // otherwise target direction is not in neighbors
        // print message
        std::cout 
        << "You cannot go that way!" 
        << std::endl;
    }
}

// show items
void Game::show_items(std::vector<std::string> target)
{
    //get rid of unused warning
    target[0] = target[0];
    // print items in inventory
    // item iterator
    std::vector<Item>::iterator item_iterator = this->inventory.begin();
    // loop over inventor
    // value to store total calories
    int total_calories = 0;
    while (item_iterator != this->inventory.end())
    {
        // message
        std::cout
        << "You have the following items in your inventory: "
        << std::endl;
        // print items
        std::cout 
        << "    - "
        << *item_iterator 
        << std::endl;
        // increment iterator
        total_calories += item_iterator->get_calories();
        item_iterator++;
    }
    // print current weight
    std::cout 
    << "You are carrying " 
    << this->current_weight 
    << " pounds." 
    << std::endl;
    std::cout
    << std::endl;
    // print total inventory calories
    std::cout 
    << "Your inventory contains " 
    << total_calories 
    << " calories." 
    << std::endl;

}

// look function
void Game::look(std::vector<std::string> target)
{
    //get rid of unused warning
    target[0] = target[0];
    // print current location/neighbors/items/npcs
    // message
    std::cout
    << "You look around..."
    << std::endl;
    std::cout
    << std::endl;
    std::cout
    << "You are at: "
    << std::endl;
    std::cout
    << std::endl;
    std::cout 
    << this->get_current_location() 
    << std::endl;
}

//for testing
void Game::set_current_location(Location &loc) {
    this->current_location = loc;
}

// quit function
void Game::quit(std::vector<std::string> target)
{
    //get rid of unused warning
    target[0] = target[0];
    // set game in progress to false
    this->game_in_progress = false;
    // print message
    std::cout << "You have quit the game." << std::endl;
}

// party function
void Game::party(std::vector<std::string> target)
{
   // convert target to string
    std::string target_npc = strvector_to_str(target);

    // check if target is in room
    std::vector<std::reference_wrapper<NPC> > npcs = this->current_location.get().get_npcs_ref();
    // npc iterator
    std::vector<std::reference_wrapper<NPC> >::iterator npc_iterator = npcs.begin();
    // loop over npcs
    while (npc_iterator != npcs.end())
    {
        // check if npc name matches target
        if (npc_iterator->get().get_name() == target_npc)
        {
            // check if npc is elf
            if (npc_iterator->get().get_name() == "Elf")
            {
                // message
                std::cout
                << "The elf does not want to party with you."
                << std::endl;
                return;
            }
            // check if npc is already in party
            if (npc_iterator->get().get_partyMember() == true)
            {
                // message
                std::cout
                << npc_iterator->get().get_name()
                << " is already in your party!"
                << std::endl;
                return;
            }
            // change npc partyMember value to true
            npc_iterator->get().set_partyMember(true);
            // message
            std::cout
            << npc_iterator->get().get_name()
            << " has joined your party!"
            << std::endl;
            return;
            //break;
        }
        npc_iterator++;
    }
    // npc is not in room
    // print message
    std::cout
    << "You do not see "
    << target_npc
    << " here."
    << std::endl; 
}

// unfollow function
void Game::leavePartyMember(std::vector<std::string> target)
{
    // convert target to string
    std::string target_npc = strvector_to_str(target);

    // check if target is in room
    std::vector<std::reference_wrapper<NPC> > npcs = this->current_location.get().get_npcs_ref();
    // npc iterator
    std::vector<std::reference_wrapper<NPC> >::iterator npc_iterator = npcs.begin();
    // loop over npcs
    while (npc_iterator != npcs.end())
    {
        // check if npc name matches target
        if (npc_iterator->get().get_name() == target_npc)
        {
            // check if npc is in party
            if (npc_iterator->get().get_partyMember() == false)
            {
                // message
                std::cout
                << npc_iterator->get().get_name()
                << " is not in your party!"
                << std::endl;
                return;
            }
            // change npc partyMember value to false
            npc_iterator->get().set_partyMember(false);
            // message
            std::cout
            << npc_iterator->get().get_name()
            << " has left your party!"
            << std::endl;
            return;
            //break;
        }
        npc_iterator++;
    }
    // npc is not in room
    // print message
    std::cout
    << "You do not see "
    << target_npc
    << " here."
    << std::endl; 

    //note cannot party with elf
    //note cannot party with same npc twice
    
}

// get current location
std::reference_wrapper<Location> Game::get_current_location() const
{
    return this->current_location;
}

// get inventory
std::vector<Item> Game::get_inventory() const
{
    return this->inventory;
}

// get current weight
float Game::get_current_weight() const
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
