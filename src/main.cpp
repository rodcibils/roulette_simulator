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
        std::cout << std::endl;
    }

    // Display players final balance
    int finalBalance = 0;
    std::cout << std::endl << std::endl;
    for(size_t i=0; i<PLAY_COUNT; ++i){
        int curBalance = players[i]->getBalance();
        std::cout << "Player " << Player::names[i] << " final balance: " << curBalance << std::endl;
        finalBalance += curBalance;
    }
    std::cout << "TOTAL BALANCE: " << finalBalance << std::endl;
}
