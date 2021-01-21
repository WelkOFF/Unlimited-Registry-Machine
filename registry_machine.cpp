#include <iostream>
#include <string>
#include <exception>
#include "registry_machine.hpp"
#include "registry.hpp"
#include "task_manager.hpp"
#include "command_parser.hpp"

void RegistryMachine::start()
{
    std::string line{};
    Registry registry{};
    TaskManager taskManager(&registry);
    CommandParser parser{&registry, &taskManager};

    std::cout << "Enter command or type \"quit\" to quit" << std::endl;
    while (std::getline(std::cin, line))
    {
        try
        {
            if (line == "quit")
            {
                break;
            }

            Pointer<Executable> cmd = parser.parseCommand(line);

            taskManager.addCommand(std::move(cmd));

            taskManager.executeLast();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "Enter command or type \"quit\" to quit" << std::endl;
    }
}