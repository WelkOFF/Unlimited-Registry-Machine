#include "command.hpp"

Command::Command(Registry *const newRegistry, TaskManager *const newTaskManager)
    : registry(newRegistry),
      taskManager(newTaskManager) {}