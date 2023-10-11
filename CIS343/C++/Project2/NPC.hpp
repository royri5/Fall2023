// Author: Richard Roy
// Date: 10/10/23

// Include guard to prevent multiple inclusions of this header file
#ifndef _NPC_
#define _NPC_

// Standard library includes
#include <string>
#include <vector>

/**
 * @class NPC
 * @brief Represents a Non-Player Character (NPC) in a game location.
 * 
 * The NPC class encapsulates the properties of an NPC, such as its name, description, messages, and party membership status.
 */
class NPC
{
public:
    // Public Member Functions 

    // Constructors
    NPC(); // Default constructor
    NPC(std::string name, std::string description); // Parameterized constructor

    // Getters
    std::string get_name() const;
    std::string get_description() const;
    std::string get_currentMessage();
    int get_messageNumber() const;
    std::vector<std::string> get_messages() const;
    bool get_partyMember() const;

    // Setters
    void set_name(std::string name);
    void set_description(std::string description);
    void set_currentMessage(std::string message);
    void set_messageNumber(int number);
    void set_messages(std::vector<std::string> messages);
    void set_partyMember(bool partyMember);

    // Utility Methods
    void incrementMessageNumber(); // Increments the message number

    // Overloaded Operators

    // Overloaded stream operator
    friend std::ostream &operator<<(
        std::ostream &output,
        const NPC &npc);
    // Overloaded equality operator
    friend bool operator==(
        const NPC &a,
        const NPC &b);
    // Overloaded inequality operator
    friend bool operator!=(
        const NPC &a,
        const NPC &b);

private:
    // Private Member Variables

    // class variables
    std::string name;                  // Name of the NPC
    std::string description;           // Description of the NPC
    int messageNumber;                 // Current message number
    std::vector<std::string> messages; // List of messages the NPC can say
    bool partyMember;                  // Indicates if the NPC is a party member
};

#endif // End of include guard