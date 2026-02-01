#include "utility.h"

int utilitys::inputValidation(){
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
double utilitys::randomDecimalValue(double Min, double Max){
    double f = (double)rand() / RAND_MAX;
    double RandomTempreture = Min + f * (Max - Min);
    return RandomTempreture;
}
int utilitys::randomValue(int Max, int Min){
    return rand() % (Min - Max) + Max;
}

std::string utilitys::TimeGenerator()
{
    std::tm timeInfo = {};
    // i do this to get a random date in 2026
    timeInfo.tm_year = 2026-1900;
    timeInfo.tm_mon = randomValue(0, 11);    // tm_mon = 0-11
    timeInfo.tm_mday = randomValue(1, 28);   // tm_mday = 1-31, safer to use 1-28 to avoid invalid dates
    timeInfo.tm_hour = randomValue(0, 23);   // 0-23 hours
    timeInfo.tm_min = randomValue(0, 59);    // 0-59 minutes
    timeInfo.tm_sec = randomValue(0, 59);    // 0-59 seconds

    std::time_t timeStamp = std::mktime(&timeInfo);

    char temp[26];
    asctime_s(temp, sizeof(temp), &timeInfo);
    temp[strlen(temp) - 1] = '\0'; // remove newline
    return temp;
}
