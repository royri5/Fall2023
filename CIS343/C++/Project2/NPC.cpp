// Author: Richard Roy
// Date: 10/10/23

// Standard library includes
#include "NPC.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

// Default constructor
NPC::NPC()
{
    this->name = "noname";
    this->description = "no description";
    this->messageNumber = 0;
    this->messages = {"default message"};
    this->partyMember = false;
}

// Parameterized constructor with exception handling
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
// name
std::string NPC::get_name() const 
{
    return this->name; 
}
// description
std::string NPC::get_description() const 
{
    return this->description; 
}
// current message
std::string NPC::get_currentMessage()
{
    // below is Github Copilot code
    std::string retval = this->messages.at((size_t)this->messageNumber);
    this->incrementMessageNumber();
    return retval;
}
// lines of dialogue
std::vector<std::string> NPC::get_messages() const 
{
    return this->messages; 
}
// current message number
int NPC::get_messageNumber() const 
{
    return this->messageNumber; 
}
// is npc a party member
bool NPC::get_partyMember() const 
{
    return this->partyMember; 
}

/* Setter methods with exception handling */
// set name
void NPC::set_name(std::string npcname)
{
    // Exception handling for blank name
    if (npcname == "")
    {
        throw std::invalid_argument("Name cannot be blank");
    }
    this->name = npcname;
}
// set description
void NPC::set_description(std::string npcdescription)
{
    // Exception handling for blank description
    if (npcdescription == "")
    {
        throw std::invalid_argument("Description cannot be blank");
    }
    this->description = npcdescription;
}
// below is Github Copilot code
// set current message
void NPC::set_currentMessage(std::string currentmessage)
{
    // add message to messages vector
    this->messages.push_back(currentmessage);
    // increment message number
    this->messageNumber++;
}
// set message number
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
// set messages
void NPC::set_messages(std::vector<std::string> newmessages) 
{
    this->messages = newmessages; 
}
// set party member
void NPC::set_partyMember(bool partymember)
{
    this->partyMember = partymember;
}

/* Utility methods */
// increment message number
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

/* overloaded operators */
// overloaded stream operator
std::ostream &operator<<(std::ostream &output, const NPC &npc)
{
    output 
    << npc.name 
    << "\n";
    
    return output;
}
// overloaded equality operator
bool operator==(const NPC &a, const NPC &b)
{
    return a.name == b.name 
    && a.description == b.description 
    && a.messageNumber == b.messageNumber 
    && a.messages == b.messages;
}
// overload not equals
bool operator!=(const NPC &a, const NPC &b)
{
    return a.name != b.name 
    || a.description != b.description 
    || a.messageNumber != b.messageNumber 
    || a.messages != b.messages;
}