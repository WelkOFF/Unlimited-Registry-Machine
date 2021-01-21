#include "zero_range_command.hpp"

ZeroRangeCommand::ZeroRangeCommand(Registry *const newRegistry,
                                   TaskManager *const newTaskManager,
                                   const CellAddress newAddressBegin,
                                   const CellAddress newAddressEnd)
    : Command(newRegistry, newTaskManager),
      addressBegin(newAddressBegin),
      addressEnd(newAddressEnd) {}

void ZeroRangeCommand::execute()
{
  registry->resetRange(addressBegin, addressEnd);
  taskManager->goToNextCommand();
}

String ZeroRangeCommand::toString()
{
  return "/zero " + std::to_string(addressBegin) + " " + std::to_string(addressEnd);
}