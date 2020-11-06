#include <player.hpp>

// Class Constructor
Player::Player(int style)
{
    play_style = style;
    initWallet();
}

// Initialize player wallet
void Player::initWallet()
{
    wallet = {1, 2, 3, 4};
}
