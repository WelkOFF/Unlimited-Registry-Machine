#ifndef CODE_COMMAND
#define CODE_COMMAND
#include "command.hpp"
class CodeCommand : public Command
{
public:
    CodeCommand(Registry *const, TaskManager *const);

    virtual void execute() final;

    virtual String toString() final;
};
#endif