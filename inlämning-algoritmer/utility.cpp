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
double utilitys::randomDecimalValue(double Min, double Max)
{
    double f = (double)rand() / RAND_MAX;
    double RandomTempreture = Min + f * (Max - Min);
    return RandomTempreture;
}
int utilitys::randomValue(int Max, int Min)
{
    return rand() % (Min - Max) + Max;
}

std::string utilitys::TimeGenerator()
{
    time_t TimeStamp;
    time(&TimeStamp);
    struct tm timeInfo;
    localtime_s(&timeInfo, &TimeStamp);
    char temp[26];
    asctime_s(temp, sizeof(temp), &timeInfo);
    temp[strlen(temp) - 1] = '\0'; // tar bort newline
    return temp;
}
