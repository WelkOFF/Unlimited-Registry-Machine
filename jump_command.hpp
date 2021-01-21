#ifndef JUMP_COMMAND
#define JUMP_COMMAND
#include "command.hpp"
class JumpCommand : public Command
{
public:
    JumpCommand(Registry *const, TaskManager *const, const longNumber);

    virtual void execute() final;

    virtual bool isInstruction() final;

    virtual String toString() final;

private:
    const longNumber nextCommandPosition;
};
#endif