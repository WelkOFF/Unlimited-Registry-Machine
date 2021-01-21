#include "load_command.hpp"

LoadCommand::LoadCommand(Registry *const newRegistry,
                         TaskManager *const newTaskManager,
                         const String &newText)
    : Command(newRegistry, newTaskManager),
      text(newText)
{
}

void LoadCommand::execute()
{
    taskManager->loadFile(text);
    taskManager->goToNextCommand();
}

String LoadCommand::toString()
{
    return "/load " + text;
}
