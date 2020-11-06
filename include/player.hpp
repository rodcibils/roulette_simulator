#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <list>

// Playing styles for players
#define PLAY_RED 0
#define PLAY_BLACK 1
#define PLAY_MAJOR 2
#define PLAY_MINOR 3
#define PLAY_ODD 4
#define PLAY_EVEN 5
#define PLAY_COUNT 6

// Max and min bets
#define MAX_BET 4000
#define MIN_BET 5

class Player
{
public:
    // Class Constructor
    Player(int style);

private:
    // Player playing style
    int play_style;
    // Player current wallet
    std::list<int> wallet;
    // Player names
    const char names[PLAY_COUNT] = {'A', 'B', 'C', 'D', 'E', 'F'};

    // Initialize player wallet
    void initWallet();
};

#endif
