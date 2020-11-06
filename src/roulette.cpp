#include <roulette.hpp>
#include <stdlib.h>
#include <time.h>

// Class Constructor
Roulette::Roulette()
{
    srand((unsigned)time(NULL));
}

// Return a random number between 0 and MAX_NUM
int Roulette::throwRoulette()
{
    return rand() % MAX_NUM;
}

// Check if a number is black
int Roulette::isBlack(int toCheck)
{
    for(size_t i; i < BLACK_NUM_COUNT; ++i){
        if(toCheck == blackNumbers[i]) {
            return 1;
        }
    }
    return 0;
}
