#ifndef EXECUTABLE
#define EXECUTABLE
#include <iostream>
#include <string>
#include <memory>
using longNumber = unsigned long long;

using String = std::string;

template <typename T>
using Pointer = std::unique_ptr<T>;

class Executable
{
public:
	virtual void execute() = 0;

	virtual String toString() = 0;

	virtual bool isInstruction();

	virtual ~Executable() = default;
};
#endif