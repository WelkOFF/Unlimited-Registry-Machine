#ifndef COMMENT_COMMAND
#define COMMENT_COMMAND
#include "command.hpp"
class CommentCommand : public Command
{
public:
    CommentCommand(Registry *const, TaskManager *const, const String &newText);

    virtual void execute() final;

    virtual String toString() final;

private:
    const String text;
};
#endif