#include "Card.hpp"
#include <iostream>
#include <string>

static const char suit_names[4] = {'H', 'D', 'C', 'S'};

std::string Card::letter() const
{
    switch (type)
    {
        case 1 : return "A";
        case 11 : return "J";
        case 12 : return "Q";
        case 13 : return "K";
        default : return std::to_string(type);
    }
}

Card::Card(int type, Suit suit) : type(type), suit(suit)
{
    value = type > 10 ? 10 : type;
}

void Card::print() const
{
    std::cout << suit_names[static_cast<int>(suit)] << letter();
}