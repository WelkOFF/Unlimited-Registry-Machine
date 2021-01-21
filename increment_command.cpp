#include "increment_command.hpp"

IncrementCommand::IncrementCommand(Registry *const newRegistry,
                                   TaskManager *const newTaskManager,
                                   const CellAddress newAddress)
    : Command(newRegistry, newTaskManager),
      address(newAddress) {}

void IncrementCommand::execute()
{
    registry->incrementCellValue(address);
    taskManager->goToNextCommand();
}

bool IncrementCommand::isInstruction()
{
    return true;
}

String IncrementCommand::toString()
{
    return "INC " + std::to_string(address);
}