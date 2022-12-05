#include "Game.hpp"

#define CLEAR_SCREEN std::cout << "\x1B[2J\x1B[H";

void Game::display_dealer_hided() const
{
    std::cout << std::left << std::setw(6) << dealer.get_name() << " | ??    | "
              << dealer.get_first_card().to_string() << " ??\n";
}

void Game::deal_card_for(Player &player) { player.add_card(deck.deal_card()); }

Game::Game(size_t number_of_players) : dealer(Player("Dealer"))
{
    for (size_t i = 1; i <= number_of_players; i++)
        players.push_back(Player("P" + std::to_string(i)));

    deck = Deck();
}

void Game::initial_deal()
{
    deal_card_for(dealer);
    deal_card_for(dealer);

    for (auto &player : players)
    {
        deal_card_for(player);
        deal_card_for(player);
    }
}

void Game::deal_for_all()
{
    std::string answer;
    for (auto &player : players)
    {
        CLEAR_SCREEN
        do {
            std::cout << player.to_string() << "\n";
            std::cout << "Do you want to draw an additional card (y/n)";
            while (answer != "y" || answer != "n") std::cin >> answer;

            if (answer == "y") player.add_card(deck.deal_card());
        }
        while (answer == "y");
    }
}

void Game::deal_for_the_dealer()
{
    while (dealer.sum_card_values() < 17) deal_card_for(dealer);
}

void Game::check_winner() {}

void Game::new_game()
{
    initial_deal();
    print();
    deal_for_all();
    print();
    deal_for_the_dealer();
    print();
    // check_winner();
}

void Game::print(bool hide_dealer_card) const
{
    CLEAR_SCREEN
    std::cout << "Name   | Point | Cards\n"
              << "-------|-------|------\n";

    if (hide_dealer_card)
        display_dealer_hided();
    else
        std::cout << dealer.to_string() << "\n";

    std::cout << "-------|-------|------\n";

    for (const auto &player : players) std::cout << player.to_string() << "\n";

    wait_for_enter();
}

void Game::wait_for_enter() const
{
    std::cout << "\nPress Enter to Continue...";
    std::cin.ignore();
}