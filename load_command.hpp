#ifndef LOAD_COMMAND
#define LOAD_COMMAND
#include "command.hpp"
class LoadCommand : public Command
{
public:
    LoadCommand(Registry *const, TaskManager *const, const String &newText);

    virtual void execute() final;

    virtual String toString() final;

private:
    const String text;
};
#endif