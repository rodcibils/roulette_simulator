#include <player.hpp>
#include <roulette.hpp>
#include <stdint.h>

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
}
