#include "NPC.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

// tests

// constructor testing
// tests default constructor
void test_default_constructor()
{
}
// tests regular constructor
void test_constructor()
{
    NPC npc = NPC("Bob", "A goblin wizard");
    if (npc.getName() == "Bob" && npc.getDescription() == "A goblin wizard" && npc.getCurrentMessage() == "default message" && npc.getMessageNumber() == 0 && npc.getMessages() == std::vector<std::string>({"default message"}))
    {
        printf("test_constructor Passed\n");
    }
    else
    {
        printf("test_constructor Failed\nexpected: Bob\n\
        A goblin wizard\n\n0\n{}\nbut was: %s\n%s\n%s\n%d\n%s",
               npc.getName(),
               npc.getDescription(),
               npc.getCurrentMessage(),
               npc.getMessageNumber(),
               npc.getMessages());
    }
}
// tests regular constructor with blank name
void test_constructor_exception_name()
{
    // catch exception generated when name is blank
    try
    {
        NPC npc = NPC("", "A goblin wizard");
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
        NPC npc = NPC("Bob", "");
    }
    catch (std::invalid_argument &e)
    {
        printf("test_constructor_exception_description Passed\n");
    }
    printf("test_constructor_exception_description done\n");
}

// setter tests
// tests setName
void test_setName(NPC npc)
{
    npc.setName("Bill");
    if (npc.getName() == "Bill")
    {
        printf("test_setName Passed\n");
    }
    else
    {
        printf("test_setName Failed\nexpected: Bill\nbut was: %s", npc.getName());
    }
}
// tests setDescription
void test_setDescription(NPC npc)
{
    npc.setDescription("A goblin necromancer");
    if (npc.getDescription() == "A goblin necromancer")
    {
        printf("test_setDescription Passed\n");
    }
    else
    {
        printf("test_setDescription Failed\nexpected: A goblin necromancer\nbut was: %s", npc.getDescription());
    }
}
// tests setCurrentMessage
void test_setCurrentMessage(NPC npc)
{
    npc.setCurrentMessage("Hello");
    if (npc.getCurrentMessage() == "Hello")
    {
        printf("test_setCurrentMessage Passed\n");
    }
    else
    {
        printf("test_setCurrentMessage Failed\nexpected: Hello\nbut was: %s", npc.getCurrentMessage());
    }
}
// tests setMessages
void test_setMessages(NPC npc)
{
    npc.setMessages({"Hello", "How are you?", "Goodbye"});
    if (npc.getMessages() == std::vector<std::string>({"Hello", "How are you?", "Goodbye"}))
    {
        printf("test_setMessages Passed\n");
    }
    else
    {
        printf("test_setMessages Failed\nexpected: Hello\nHow are you?\nGoodbye\nbut was: %s\n%s\n%s",
               npc.getMessages()[0],
               npc.getMessages()[1],
               npc.getMessages()[2]);
    }
}
// tests messaging system (need messages to test)
void test_messaging_system1(NPC npc)
{
    npc.setCurrentMessage("Hello");
    npc.setCurrentMessage("How are you?");
    npc.setCurrentMessage("Goodbye");
    // test each message number
    npc.setMessageNumber(1);
    if (npc.getCurrentMessage() == "Hello")
    {
        printf("(1)first message test Passed\n");
    }
    else
    {
        printf("(1)first message test Failed\nexpected: Hello\nbut was: %s\n", npc.getCurrentMessage());
    }
    if (npc.getCurrentMessage() == "How are you?")
    {
        printf("(1)second message test Passed\n");
    }
    else
    {
        printf("(1)second message test Failed\nexpected: How are you?\nbut was: %s\n", npc.getCurrentMessage());
    }
    if (npc.getCurrentMessage() == "Goodbye")
    {
        printf("(1)third message test Passed\n");
    }
    else
    {
        printf("(1)third message test Failed\nexpected: Goodbye\nbut was: %s\n", npc.getCurrentMessage());
    }
    if (npc.getCurrentMessage() == "default message")
    {
        printf("(1)fourth message test Passed\n");
    }
    else
    {
        printf("(1)fourth message test Failed\nexpected: Hello\nbut was: %s\n", npc.getCurrentMessage());
    }
}
// tests messaging system (need messages to test)
void test_messaging_system2(NPC npc)
{
    npc.setMessages({"Hello", "How are you?", "Goodbye"});
    // test each message number
    if (npc.getCurrentMessage() == "Hello")
    {
        printf("(2)first message test Passed\n");
    }
    else
    {
        printf("(2)first message test Failed\nexpected: Hello\nbut was: %s\n", npc.getCurrentMessage());
    }
    if (npc.getCurrentMessage() == "How are you?")
    {
        printf("(2)second message test Passed\n");
    }
    else
    {
        printf("(2)second message test Failed\nexpected: How are you?\nbut was: %s\n", npc.getCurrentMessage());
    }
    if (npc.getCurrentMessage() == "Goodbye")
    {
        printf("(2)third message test Passed\n");
    }
    else
    {
        printf("(2)third message test Failed\nexpected: Goodbye\nbut was: %s\n", npc.getCurrentMessage());
    }
    if (npc.getCurrentMessage() == "Hello")
    {
        printf("(2)fourth message test Passed\n");
    }
    else
    {
        printf("(2)fourth message test Failed\nexpected: Hello\nbut was: %s\n", npc.getCurrentMessage());
    }
}

// test incrementMessageNumber
void test_increment_message_number(NPC npc)
{
    npc.setMessages({"Hello", "How are you?", "Goodbye"});
    if (npc.getCurrentMessage() == "Hello")
    {
        printf("(increment)first message test Passed\n");
    }
    else
    {
        printf("(increment)first message test Failed\nexpected: Hello\nbut was: %s\n", npc.getCurrentMessage());
    }
    if (npc.getCurrentMessage() == "How are you?")
    {
        printf("(increment)second message test Passed\n");
    }
    else
    {
        printf("(increment)second message test Failed\nexpected: How are you?\nbut was: %s\n", npc.getCurrentMessage());
    }
    if (npc.getCurrentMessage() == "Goodbye")
    {
        printf("(increment)third message test Passed\n");
    }
    else
    {
        printf("(increment)third message test Failed\nexpected: Goodbye\nbut was: %s\n", npc.getCurrentMessage());
    }
    if (npc.getCurrentMessage() == "Hello")
    {
        printf("(increment)fourth message test Passed\n");
    }
    else
    {
        printf("(increment)fourth message test Failed\nexpected: Hello\nbut was: %s\n", npc.getCurrentMessage());
    }
}

// getter tests
// tests getName
void test_getName(NPC npc)
{
    if (npc.getName() == "Bob")
    {
        printf("test_getName Passed\n");
    }
    else
    {
        printf("test_getName Failed\nexpected: Bob\nbut was: %s", npc.getName());
    }
}
// tests getDescription
void test_getDescription(NPC npc)
{
    if (npc.getDescription() == "A goblin wizard")
    {
        printf("test_getDescription Passed\n");
    }
    else
    {
        printf("test_getDescription Failed\nexpected: A goblin wizard\nbut was: %s", npc.getDescription());
    }
}
// tests getMessages
void test_getMessages(NPC npc)
{
    npc.setMessages({"Hello", "How are you?", "Goodbye"});
    if (npc.getMessages() == std::vector<std::string>({"Hello", "How are you?", "Goodbye"}))
    {
        printf("test_getMessages Passed\n");
    }
    else
    {
        printf("test_getMessages Failed\nexpected: Hello\nHow are you?\nGoodbye\nbut was: %s\n%s\n%s",
               npc.getMessages()[0],
               npc.getMessages()[1],
               npc.getMessages()[2]);
    }
}

// main for all tests
//int main(void)
// {
//     std::vector<NPC> npcs;
//     // constructor tests
//     test_default_constructor();
//     test_constructor();
//     test_constructor_exception_name();
//     test_constructor_exception_description();

//     NPC testNPC("Bob", "A goblin wizard");
//     npcs.push_back(testNPC);

//     // overloaded stream operator test
//     std::cout << (npcs.at(0));

//     // setter tests
//     test_setName(npcs.at(0));
//     test_setDescription(npcs.at(0));
//     test_setCurrentMessage(npcs.at(0));
//     test_setMessages(npcs.at(0));
//     test_messaging_system1(npcs.at(0));
//     test_messaging_system2(npcs.at(0));
//     test_increment_message_number(npcs.at(0));

//     // getter tests
//     test_getName(npcs.at(0));
//     test_getDescription(npcs.at(0));
//     test_getMessages(npcs.at(0));
// }