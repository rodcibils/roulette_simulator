#include <player.hpp>
#include <roulette.hpp>
#include <stdint.h>
#include <iostream>

#define MAX_BETS 10000

int main(int argc, char **argv)
{
    // Players initialization
    Player *players[PLAY_COUNT];
    for(size_t i=0; i<PLAY_COUNT; ++i) {
        players[i] = new Player(i);
    }

    // Roulette initialization
    Roulette *roulette = new Roulette();

    // Main loop of the program
    for(size_t i=0; i<MAX_BETS; ++i) {
        int curNumber = roulette->throwRoulette();
        std::cout << "Throw # " << (i+1) << std::endl;
        std::cout << "Number: " << curNumber << std::endl;
        for(size_t j=0; j<PLAY_COUNT; ++j){
            players[j]->determinePlay(curNumber);
        }
    }
}
