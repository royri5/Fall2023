#include "NPC.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

// The NPC class represents information about a character that can be in a Location. An NPC has a name,
// description, message number, and vector of messages. Each time the player speaks to an NPC, the
// message number should increase by 1, resulting in the next message in the vector being printed the next
// time the player speaks to the character. The message number should go back to 0 after it goes past the
// length of the message vector. The class must have:
//  * A constructor that accepts a name and a description (neither can be blank).
//  * Getters for name and description.
//  * A getter for a message that returns the current message (as indicated by message number), then
//    chages the message number appropriately.
//  * An overloaded stream operator that returns only the name of the NPC.

// defining npc class
// default constructor
NPC::NPC()
{
    this->name = "noname";
    this->description = "no description";
    this->messageNumber = 0;
    this->messages = {"default message"};
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
}

// getters
// getName
std::string NPC::get_name() const
{
    return this->name;
}

// getDescription
std::string NPC::get_description() const
{
    return this->description;
}

// getCurrentMessage (if increments over max message number, resets to 0)
// below is Github Copilot code
std::string NPC::get_currentMessage()
{
    std::string retval = this->messages.at(this->messageNumber);
    this->incrementMessageNumber();
    return retval;
}

// may not need below getters
// getMessageNumber
int NPC::get_messageNumber() const
{
    return this->messageNumber;
}

// getMessages
std::vector<std::string> NPC::get_messages() const
{
    return this->messages;
}

// setters
// setName
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

// setDescription
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
// make sure not to override messages
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

    // check if message number is greater than the size of the messages vector
    if (number >= int(this->messages.size()))
    {
        throw std::invalid_argument("Message number cannot be greater than or equal to the size of the messages vector");
    }
    // check if message number is less than 0
    if (number < 0)
    {
        throw std::invalid_argument("Message number cannot be less than 0");
    }

    // set message number
    this->messageNumber = number;
}

// setMessages
void NPC::set_messages(std::vector<std::string> newmessages)
{
    this->messages = newmessages;
}

// increment message number
// make sure not to increment past max message number
// if so, reset to 0
void NPC::incrementMessageNumber()
{
    // if message number is greater than or equal to the size of the messages vector, reset message number to 0
    if ((this->messageNumber + 1) >= int(this->messages.size()))
    {
        this->messageNumber = 0;
    }
    else
    {
        // increment message number
        this->messageNumber++;
    }
}

// overloaded stream operator
std::ostream &operator<<(std::ostream &output, const NPC &npc)
{
    //output << npc.name << "\n";
    output << npc.name << "\n";
    return output;
}

// overloaded equality operator
bool operator==(const NPC &a, const NPC &b)
{
    // return a.getName() == b.getName() && a.getDescription() == b.getDescription() && a.getMessageNumber() == b.getMessageNumber() && a.getMessages() == b.getMessages();
    return a.name == b.name && a.description == b.description && a.messageNumber == b.messageNumber && a.messages == b.messages;
}

// overload not equals
bool operator!=(const NPC &a, const NPC &b)
{
    // return a.getName() != b.getName() || a.getDescription() != b.getDescription() || a.getMessageNumber() != b.getMessageNumber() || a.getMessages() != b.getMessages();
    return a.name != b.name || a.description != b.description || a.messageNumber != b.messageNumber || a.messages != b.messages;
}