#ifndef ROULETTE_HPP
#define ROULETTE_HPP

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
    static int isBlack(int toCheck);

    // Array of black numbers in the roulette
    static const int blackNumbers[BLACK_NUM_COUNT];

private:
};

#endif
