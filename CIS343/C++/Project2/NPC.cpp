// Author: Richard Roy
// Date: 10/10/23

#include "NPC.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

// default constructor
NPC::NPC()
{
    this->name = "noname";
    this->description = "no description";
    this->messageNumber = 0;
    this->messages = {"default message"};
    this->partyMember = false;
}

// constructor with parameters
NPC::NPC(std::string npcname, std::string npcdescription)
{
    // exception checking
    // check if name is blank
    if (npcname == "")
    {
        throw std::invalid_argument("Name cannot be blank");
    }
    // check if description is blank
    if (npcdescription == "")
    {
        throw std::invalid_argument("Description cannot be blank");
    }
    // instantiate object variables
    this->name = npcname;
    this->description = npcdescription;
    this->messageNumber = 0;
    this->messages = {"default message"};
    this->partyMember = false;
}

// getters
std::string NPC::get_name() const
{
    return this->name;
}
std::string NPC::get_description() const
{
    return this->description;
}
// below is Github Copilot code
std::string NPC::get_currentMessage()
{
    std::string retval = this->messages.at((
        long unsigned int)this->messageNumber);
    this->incrementMessageNumber();
    return retval;
}
int NPC::get_messageNumber() const
{
    return this->messageNumber;
}
std::vector<std::string> NPC::get_messages() const
{
    return this->messages;
}
bool NPC::get_partyMember() const
{
    return this->partyMember;
}

// setters
void NPC::set_name(std::string npcname)
{
    // exception checking
    // check if name is blank
    if (npcname == "")
    {
        throw std::invalid_argument("Name cannot be blank");
    }
    // set name
    this->name = npcname;
}
void NPC::set_description(std::string npcdescription)
{
    // exception checking
    // check if description is blank
    if (npcdescription == "")
    {
        throw std::invalid_argument("Description cannot be blank");
    }
    // set description
    this->description = npcdescription;
}
// setCurrentMessage at the end of the messages vector
// increment message number
// below is Github Copilot code
void NPC::set_currentMessage(std::string currentmessage)
{
    // add message to end of messages vector
    this->messages.push_back(currentmessage);
    // increment message number
    this->messageNumber++;
}
// setMessageNumber (make sure message number cannot be
// greater than the size of the messages vector
// or less than 0)
void NPC::set_messageNumber(int number)
{
    // exception checking
    // check if message number is greater than
    // the size of the messages vector
    if (number >= int(this->messages.size()))
    {
        throw std::invalid_argument("Message number cannot\
         be greater than or equal to the size of the messages vector");
    }
    // check if message number is less than 0
    if (number < 0)
    {
        throw std::invalid_argument("Message number cannot\
         be less than 0");
    }
    // set message number
    this->messageNumber = number;
}
void NPC::set_messages(std::vector<std::string> newmessages)
{
    this->messages = newmessages;
}
void NPC::set_partyMember(bool partymember)
{
    this->partyMember = partymember;
}
// increment message number
// make sure not to increment past max message number
// if so, reset to 0
void NPC::incrementMessageNumber()
{
    // if message number is greater than or equal to the
    // size of the messages vector, reset message number to 0
    if ((this->messageNumber + 1) >= int(this->messages.size()))
    {
        this->messageNumber = 0;
    }
    else
    {
        this->messageNumber++;
    }
}

// overloaded operators
// overloaded stream operator
std::ostream &operator<<(std::ostream &output, const NPC &npc)
{
    output << npc.name << "\n";
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