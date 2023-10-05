#include <iostream>

#include "Headers/Alienware/alienware.h"
#include "Headers/Config.h"


int main()
{
    int color;
    std::cout << "Enter color: ";
    std::cin >> color;
    std::cout << "\nColor: " + color << std::endl;
    
    // Alienware
    alienwareStaticColor();

    // Logitech

    // TODO: Coming soon...

    std::cout << "Function import success\n";
}



