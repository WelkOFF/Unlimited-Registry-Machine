#include "run_command.hpp"

RunCommand::RunCommand(Registry *const newRegistry,
                       TaskManager *const newTaskManager)
    : Command(newRegistry, newTaskManager)
{
}

void RunCommand::execute()
{
    taskManager->removeLast();
    taskManager->executeCommands();
}

String RunCommand::toString()
{
    return "/run";
}
