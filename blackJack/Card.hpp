#pragma once

#include <iostream>
#include <string>
#include <vector>

enum class Suit
{
    H,
    D,
    C,
    S,
};

class Card
{
    int type, value;
    Suit suit;

    std::string letter() const;

  public:
    Card(int type, Suit suit);
    inline int get_value() const { return value; }

    void print() const;
};