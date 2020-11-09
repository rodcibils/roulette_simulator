#include <roulette.hpp>
#include <stdlib.h>
#include <time.h>

const int Roulette::blackNumbers[BLACK_NUM_COUNT] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29,
    31, 33, 35};

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
    for(size_t i=0; i < BLACK_NUM_COUNT; ++i){
        if(toCheck == Roulette::blackNumbers[i]) {
            return true;
        }
    }
    return false;
}
