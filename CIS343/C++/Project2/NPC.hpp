// include guard
#ifndef _NPC_
#define _NPC_

// includes
#include <string>
#include <vector>

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

// defines npc class
class NPC
{
public:
    // default constructor
    NPC();

    // constructor with parameters
    NPC(std::string name, std::string description);

    // getters
    std::string getName() const;
    std::string getDescription() const;
    // may need parameter
    std::string getCurrentMessage();
    // may not need
    int getMessageNumber() const;
    std::vector<std::string> getMessages() const;

    // setters
    // think about what return type these should be
    void setName(std::string name);
    void setDescription(std::string description);
    // may not need
    void setCurrentMessage(std::string message);
    void setMessageNumber(int number);
    void setMessages(std::vector<std::string> messages);

    // increment message number
    void incrementMessageNumber();

    // overloaded stream operator
    friend std::ostream &operator<<(
        std::ostream &output,
        const NPC &npc);
    // overloaded equality operator
    friend bool operator==(
        const NPC &a,
        const NPC &b);
    // overloaded inequality operator
    friend bool operator!=(
        const NPC &a,
        const NPC &b);

private:
    // class variables
    std::string name;
    std::string description;
    int messageNumber;
    std::vector<std::string> messages;
};

#endif