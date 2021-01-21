#include "jump_command.hpp"

JumpCommand::JumpCommand(Registry *const newRegistry,
                         TaskManager *const newTaskManager,
                         const longNumber newNextCommandPosition)
    : Command(newRegistry, newTaskManager),
      nextCommandPosition(newNextCommandPosition)
{
}

void JumpCommand::execute()
{
    taskManager->goToCommand(nextCommandPosition);
}

bool JumpCommand::isInstruction()
{
    return true;
}

String JumpCommand::toString()
{
    return "JUMP " + std::to_string(nextCommandPosition);
}
