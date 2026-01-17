#include "utility.h"

int utilitys::inputValidation()
{
    std::cout << "choose input: ";
    int Choice;
    while (!(std::cin >> Choice)) //if you input something that is not a int it 
    {                             //will make the choice variable false untill u input a int
    
        std::cout << "Error you have inputed a invalid value please input a number:  " << std::endl;
        std::cin.clear();
        std::streamsize InputBufferLimit = 10000;
        std::cin.ignore(InputBufferLimit, '\n');
    }
    return Choice;
}