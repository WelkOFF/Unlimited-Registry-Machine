#include "print_memory_command.hpp"

PrintMemoryCommand::PrintMemoryCommand(Registry *const newRegistry,
                                       TaskManager *const newTaskManager,
                                       const CellAddress newAddressBegin,
                                       const CellAddress newAddressEnd)
    : Command(newRegistry, newTaskManager),
      addressBegin(newAddressBegin),
      addressEnd(newAddressEnd) {}

void PrintMemoryCommand::execute()
{
  registry->printRange(addressBegin, addressEnd);
  taskManager->goToNextCommand();
}

String PrintMemoryCommand::toString()
{
  return "/mem " + std::to_string(addressBegin) + " " + std::to_string(addressEnd);
}