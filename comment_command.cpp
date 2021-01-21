#include "comment_command.hpp"

CommentCommand::CommentCommand(Registry *const newRegistry,
                               TaskManager *const newTaskManager,
                               const String &newText)
    : Command(newRegistry, newTaskManager),
      text(newText)
{
}

void CommentCommand::execute()
{
    taskManager->goToNextCommand();
}

String CommentCommand::toString()
{
    return "/comment " + text;
}
