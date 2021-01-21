#include <iostream>
#include <fstream>
#include "registry_machine.hpp"
int main()
{
    RegistryMachine urm;
    urm.start();
}
/* 
    The /add <filename> function is not implemented, there is a refactored fib.urm file,
    that works just like the original fir.urm file, but without the /add function in order
    to test the rest of the functionality of the program. :D
*/
