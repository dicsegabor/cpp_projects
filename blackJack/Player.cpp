#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>

Player::Player(std::string name) : name(name), cards(std::vector<Card>()) {}

int Player::sum_card_values() const
{
    int sum = 0;
    for (const auto &card : cards) sum += card.get_value();

    return sum;
}

void Player::print_hand() const
{
    for (const auto &card : cards)
    {
        card.print();
        std::cout << " ";
    }
}