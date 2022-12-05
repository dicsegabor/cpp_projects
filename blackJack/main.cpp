#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

#include "Card.hpp"
#include "Player.hpp"
#include "Deck.hpp"

int main(){

    Deck deck = Deck();
    Player p1 = Player("P1");
    p1.add_card(deck.deal_card());
    p1.add_card(deck.deal_card());
    p1.add_card(deck.deal_card());
    p1.add_card(deck.deal_card());
    p1.add_card(deck.deal_card());
    p1.print_hand();
    std::cout << p1.sum_card_values();

    return 0;
}