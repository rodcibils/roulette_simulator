#ifndef ROULETTE_HPP
#define ROULETTE_HPP

#include <map>
#include <stdint.h>

#define MAX_NUM 37
#define BLACK_NUM_COUNT 18

class Roulette
{
public:
    // Class Constructor
    Roulette();
    // Throw roulette
    int throwRoulette();
    // Check if number is black
    int isBlack(int toCheck);

private:
    // Array of black numbers on the roulette
    const int blackNumbers[BLACK_NUM_COUNT] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29,
        31, 33, 35};
};

#endif
