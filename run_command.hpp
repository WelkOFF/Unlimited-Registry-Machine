#ifndef RUN_COMMAND
#define RUN_COMMAND
#include "command.hpp"
class RunCommand : public Command
{
public:
    RunCommand(Registry *const, TaskManager *const);

    virtual void execute() final;

    virtual String toString() final;
};
#endif