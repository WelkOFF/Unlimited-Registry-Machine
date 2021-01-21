#include "zero_command.hpp"

ZeroCommand::ZeroCommand(Registry *const newRegistry,
                         TaskManager *const newTaskManager,
                         const CellAddress newAddress)
    : Command(newRegistry, newTaskManager),
      address(newAddress)
{
}

void ZeroCommand::execute()
{
    registry->resetCell(address);
    taskManager->goToNextCommand();
}

bool ZeroCommand::isInstruction()
{
    return true;
}

String ZeroCommand::toString()
{
    return "ZERO " + std::to_string(address);
}
