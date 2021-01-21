#include "jump_condition_command.hpp"

JumpCondtitionCommand::JumpCondtitionCommand(Registry *const newRegistry,
                                             TaskManager *const newTaskManager,
                                             const CellAddress newCellAddress1,
                                             const CellAddress newCellAddress2,
                                             const longNumber newNextCommandPosition)
    : Command(newRegistry, newTaskManager),
      cellAddress1(newCellAddress1),
      cellAddress2(newCellAddress2),
      nextCommandPosition(newNextCommandPosition)

{
}

void JumpCondtitionCommand::execute()
{
    if (registry->valueAt(cellAddress1) == registry->valueAt(cellAddress2))
    {
        taskManager->goToCommand(nextCommandPosition);
    }
    else
    {
        taskManager->goToNextCommand();
    }
}

bool JumpCondtitionCommand::isInstruction()
{
    return true;
}

String JumpCondtitionCommand::toString()
{
    return "JUMP " + std::to_string(cellAddress1) + " " + std::to_string(cellAddress2) + " " + std::to_string(nextCommandPosition);
}
