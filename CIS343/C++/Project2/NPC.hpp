// Author: Richard Roy
// Date: 10/10/23

// include guard
#ifndef _NPC_
#define _NPC_

// includes
#include <string>
#include <vector>


// defines npc class
class NPC
{
public:
    // default constructor
    NPC();

    // constructor with parameters
    NPC(std::string name, std::string description);

    // getters
    std::string get_name() const;
    std::string get_description() const;
    std::string get_currentMessage();
    int get_messageNumber() const;
    std::vector<std::string> get_messages() const;
    bool get_partyMember() const;

    // setters
    void set_name(std::string name);
    void set_description(std::string description);
    void set_currentMessage(std::string message);
    void set_messageNumber(int number);
    void set_messages(std::vector<std::string> messages);
    void set_partyMember(bool partyMember);

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
    bool partyMember;
};

#endif