#ifndef COMMAND_PARSER
#define COMMAND_PARSER
#include <sstream>
#include <memory>
#include "registry.hpp"
#include "task_manager.hpp"
#include "executable.hpp"

using String = std::string;

class CommandParser
{
public:
    CommandParser(Registry *const newRegistry, TaskManager *const newTaskManager);
    
    Pointer<Executable> parseCommand(String textCommand);

private:
    Registry *const registry;
    TaskManager *const taskManager;
};
#endif