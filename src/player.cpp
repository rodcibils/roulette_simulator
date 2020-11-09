#include <player.hpp>
#include <roulette.hpp>
#include <iostream>

const char  Player::names[PLAY_COUNT] = {'A', 'B', 'C', 'D', 'E', 'F'};

// Class Constructor
Player::Player(int style)
{
    play_style = style;
    balance = 0;
    initWallet();
}

// Initialize player wallet
void Player::initWallet()
{
    wallet = {1, 2, 3, 4};
}

// Get balance of player
int Player::getBalance()
{
	return balance;
}

// Determines the result of the current play
void Player::determinePlay(int number)
{
	// Check if player won or lose this throw according to its playing style
	int hasWon = false;
	if(number > 0){
		switch(play_style) {
			case PLAY_RED:
				hasWon = !Roulette::isBlack(number);
				break;
			case PLAY_BLACK:
				hasWon = Roulette::isBlack(number);
				break;
			case PLAY_MAJOR:
				hasWon = (number >= 19 && number <= 36);
				break;
			case PLAY_MINOR:
				hasWon = (number >= 1 && number <= 18);
				break;
			case PLAY_EVEN:
				hasWon = (number % 2 == 0);
				break;
			case PLAY_ODD:
				hasWon = (number % 2 != 0);
				break;
		}
	}
	int bet = wallet.front();
	if(wallet.size() > 1){
		bet = wallet.front() + wallet.back();
	}
	if(bet > MAX_BET || bet < MIN_BET) {
		// The bet exceeds the bet limits for the table
		// The player wallet is cleaned back to initial state
		initWallet();
		bet = wallet.front() + wallet.back();
	}
	std::cout << "Player " << names[play_style] << " bet: " << bet;
	if(hasWon) {
		// The player won this throw
		std::cout << " -- WON!" << std::endl;
		// Add earnings at the end of the player's wallet
		wallet.push_back(bet);
		// Add earnings to player balance
		balance += bet;
		return;
	}
	// The player lose this throw
	std::cout << " -- LOSE!" << std::endl;
	// Subtract loses to player balance
	balance -= bet;
	// Remove first and last element of the wallet
	wallet.pop_front();
	if(wallet.size() > 0) wallet.pop_back();
	// If the wallet is empty, it is refilled
	if(wallet.size() == 0){
		initWallet();
	}
}
