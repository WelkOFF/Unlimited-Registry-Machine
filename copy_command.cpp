#include "copy_command.hpp"

CopyCommand::CopyCommand(Registry *const newRegistry,
                         TaskManager *const newTaskManager,
                         const CellAddress newAddressFrom,
                         const CellAddress newAddressTo,
                         const longNumber newCount)
    : Command(newRegistry, newTaskManager),
      addressFrom(newAddressFrom),
      addressTo(newAddressTo),
      count(newCount) {}

void CopyCommand::execute()
{
    registry->copyRange(addressFrom, addressTo, count);
    taskManager->goToNextCommand();
}

String CopyCommand::toString()
{
    return "/copy " + std::to_string(addressFrom) + " " + std::to_string(addressTo) + " " + std::to_string(count);
}