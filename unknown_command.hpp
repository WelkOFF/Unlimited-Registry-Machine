#ifndef UNKNOWN_COMMAND
#define UNKNOWN_COMMAND
#include "executable.hpp"
class UnknownCommand : public Executable
{
public:
    UnknownCommand() = default;

    virtual void execute() final;

    virtual String toString() final;
};
#endif