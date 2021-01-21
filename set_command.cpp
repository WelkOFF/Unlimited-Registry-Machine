#include "set_command.hpp"

SetCommand::SetCommand(Registry *const newRegistry,
                       TaskManager *const newTaskManager,
                       const CellAddress newAddress,
                       const CellValue newValue)
    : Command(newRegistry, newTaskManager),
      address(newAddress),
      value(newValue) {}

void SetCommand::execute()
{
  registry->setCellValue(address, value);
  taskManager->goToNextCommand();
}

String SetCommand::toString()
{
  return "/set " + std::to_string(address) + " " + std::to_string(value);
}