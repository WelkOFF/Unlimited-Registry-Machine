#include "move_command.hpp"

MoveCommand::MoveCommand(Registry *const newRegistry,
                         TaskManager *const newTaskManager,
                         const CellAddress newAddressFrom,
                         const CellAddress newAddressTo)

    : Command(newRegistry, newTaskManager),
      addressFrom(newAddressFrom),
      addressTo(newAddressTo)
{
}

void MoveCommand::execute()
{
    registry->copyCellValue(addressFrom, addressTo);
    taskManager->goToNextCommand();
}

bool MoveCommand::isInstruction()
{
    return true;
}

String MoveCommand::toString()
{
    return "MOVE " + std::to_string(addressFrom) + " " + std::to_string(addressTo);
}