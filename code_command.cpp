#include "code_command.hpp"

CodeCommand::CodeCommand(Registry *const newRegistry,
                         TaskManager *const newTaskManager)
    : Command(newRegistry, newTaskManager)
{
}

void CodeCommand::execute()
{
    taskManager->removeLast();
    taskManager->printCommands();
    taskManager->goToNextCommand();
}

String CodeCommand::toString()
{
    return "/code";
}
