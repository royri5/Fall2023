#include "NPC.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * @class NPC
 * @brief The NPC class represents non-playable characters in the game.
 * @author Richard Roy - richard.alex.roy@gmail.com
 * @date 10/5/23
 * 
 * This class defines attributes and methods for managing NPC objects, including
 * their name, description, messages, and party membership status.
 */

/**
 * @brief Default constructor for NPC class.
 * 
 * Initializes an NPC object with default values for its attributes.
 */
NPC::NPC()
{
    this->name = "noname";
    this->description = "no description";
    this->messageNumber = 0;
    this->messages = {"default message"};
    this->partyMember = false;
}

/**
 * @brief Parameterized constructor for NPC class with exception handling.
 * 
 * Initializes an NPC object with the provided name and description, and performs
 * exception handling to ensure they are not blank.
 * 
 * @param npcname The name of the NPC.
 * @param npcdescription The description of the NPC.
 * 
 * @throws std::invalid_argument If `npcname` or `npcdescription` is blank.
 */
NPC::NPC(std::string npcname, std::string npcdescription)
{
    // Exception handling for blank name and description
    if (npcname == "")
    {
        throw std::invalid_argument("Name cannot be blank");
    }
    if (npcdescription == "")
    {
        throw std::invalid_argument("Description cannot be blank");
    }

    // Initialize member variables
    this->name = npcname;
    this->description = npcdescription;
    this->messageNumber = 0;
    this->messages = {"default message"};
    this->partyMember = false;
}

/* Getter methods */

/**
 * @brief Getter method for the name of the NPC.
 * 
 * @return The name of the NPC.
 */
std::string NPC::get_name() const 
{
    return this->name; 
}

/**
 * @brief Getter method for the description of the NPC.
 * 
 * @return The description of the NPC.
 */
std::string NPC::get_description() const 
{
    return this->description; 
}

/**
 * @brief Getter method for the current message of the NPC.
 * 
 * Gets the current message of the NPC and increments the message number.
 * 
 * @return The current message of the NPC.
 */
std::string NPC::get_currentMessage()
{
    // below is Github Copilot code
    std::string retval = this->messages.at((size_t)this->messageNumber);
    this->incrementMessageNumber();
    return retval;
}

/**
 * @brief Getter method for the list of messages of the NPC.
 * 
 * @return A vector of strings containing the NPC's messages.
 */
std::vector<std::string> NPC::get_messages() const 
{
    return this->messages; 
}

/**
 * @brief Getter method for the current message number of the NPC.
 * 
 * @return The current message number.
 */
int NPC::get_messageNumber() const 
{
    return this->messageNumber; 
}

/**
 * @brief Getter method to check if the NPC is a party member.
 * 
 * @return `true` if the NPC is a party member, `false` otherwise.
 */
bool NPC::get_partyMember() const 
{
    return this->partyMember; 
}

/* Setter methods with exception handling */

/**
 * @brief Setter method for the name of the NPC with exception handling.
 * 
 * Sets the name of the NPC, and performs exception handling to ensure it is not blank.
 * 
 * @param npcname The new name for the NPC.
 * 
 * @throws std::invalid_argument If `npcname` is blank.
 */
void NPC::set_name(std::string npcname)
{
    // Exception handling for blank name
    if (npcname == "")
    {
        throw std::invalid_argument("Name cannot be blank");
    }
    this->name = npcname;
}

/**
 * @brief Setter method for the description of the NPC with exception handling.
 * 
 * Sets the description of the NPC, and performs exception handling to ensure it is not blank.
 * 
 * @param npcdescription The new description for the NPC.
 * 
 * @throws std::invalid_argument If `npcdescription` is blank.
 */
void NPC::set_description(std::string npcdescription)
{
    // Exception handling for blank description
    if (npcdescription == "")
    {
        throw std::invalid_argument("Description cannot be blank");
    }
    this->description = npcdescription;
}

/** below is Github Copilot code **/
/**
 * @brief Setter method to add a message to the NPC's list of messages.
 * 
 * Adds a new message to the list of messages, and increments the message number.
 * 
 * @param currentmessage The message to be added.
 */
void NPC::set_currentMessage(std::string currentmessage)
{
    // add message to messages vector
    this->messages.push_back(currentmessage);
    // increment message number
    this->messageNumber++;
}

/**
 * @brief Setter method to set the current message number of the NPC.
 * 
 * Sets the current message number to a specified value.
 * 
 * @param number The new message number.
 * 
 * @throws std::invalid_argument If `number` is out of range or negative.
 */
void NPC::set_messageNumber(int number)
{
    // Exception handling for invalid message number
    if (number >= int(this->messages.size()))
    {
        throw std::invalid_argument("Message number cannot be greater than or equal to the size of the messages vector");
    }
    // Exception handling for negative message number
    if (number < 0)
    {
        throw std::invalid_argument("Message number cannot be less than 0");
    }
    this->messageNumber = number;
}

/**
 * @brief Setter method to set the list of messages for the NPC.
 * 
 * @param newmessages A vector of strings containing the new messages.
 */
void NPC::set_messages(std::vector<std::string> newmessages) 
{
    this->messages = newmessages; 
}

/**
 * @brief Setter method to set whether the NPC is a party member or not.
 * 
 * @param partymember `true` if the NPC is a party member, `false` otherwise.
 */
void NPC::set_partyMember(bool partymember)
{
    this->partyMember = partymember;
}

/* Utility methods */

/**
 * @brief Utility method to increment the message number of the NPC.
 * 
 * This method increments the message number, and if it reaches the end of the messages,
 * it wraps around to the beginning.
 */
void NPC::incrementMessageNumber()
{
    // Overflow check/handling
    if ((this->messageNumber + 1) >= int(this->messages.size()))
    {
        this->messageNumber = 0;
    }
    else
    {
        this->messageNumber++;
    }
}

/* Overloaded operators */

/**
 * @brief Overloaded stream operator to print the name of the NPC.
 * 
 * @param output The output stream.
 * @param npc The NPC object to be printed.
 * 
 * @return The output stream with the NPC's name.
 */
std::ostream &operator<<(std::ostream &output, const NPC &npc)
{
    output 
    << npc.name 
    << "\n";
    
    return output;
}

/**
 * @brief Overloaded equality operator to compare two NPC objects.
 * 
 * @param a The first NPC object to be compared.
 * @param b The second NPC object to be compared.
 * 
 * @return `true` if the two NPC objects are equal, `false` otherwise.
 */
bool operator==(const NPC &a, const NPC &b)
{
    return a.name == b.name 
    && a.description == b.description 
    && a.messageNumber == b.messageNumber 
    && a.messages == b.messages;
}

/**
 * @brief Overloaded inequality operator to compare two NPC objects.
 * 
 * @param a The first NPC object to be compared.
 * @param b The second NPC object to be compared.
 * 
 * @return `true` if the two NPC objects are not equal, `false` otherwise.
 */
bool operator!=(const NPC &a, const NPC &b)
{
    return a.name != b.name 
    || a.description != b.description 
    || a.messageNumber != b.messageNumber 
    || a.messages != b.messages;
}