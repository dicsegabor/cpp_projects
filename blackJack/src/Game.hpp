#pragma once

#include "Deck.hpp"
#include "Player.hpp"
#include <vector>

class Game
{
    Player dealer;
    std::vector<Player> players;
    Deck deck;

    void deal_card_for(Player &player);

    void initial_deal();

    void deal_for_all();

    void deal_for_the_dealer();

    void check_winner();

    void display_dealer_hided() const;

    void print(bool hide_dealer_card = true) const;

  public:
    Game(size_t number_of_players);

    void new_game();
};