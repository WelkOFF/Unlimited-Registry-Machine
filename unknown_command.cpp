#include "unknown_command.hpp"
void UnknownCommand::execute()
{
    std::cout << toString() << std::endl;
}

String UnknownCommand::toString()
{
    return "Invalid command...";
}