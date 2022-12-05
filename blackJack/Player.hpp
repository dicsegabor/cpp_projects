#pragma once

#include "Card.hpp"
#include <string>
#include <vector>

class Player
{
    std::string name;
    std::vector<Card> cards;

  public:
    Player(std::string name);

    inline std::string get_name() const { return name; }

    inline void add_card(Card card) { cards.push_back(card); }

    int sum_card_values() const;

    void print_hand() const;
};