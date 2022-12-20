#include "figure.hpp"

std::string Figure::to_string() const
{
    switch (type)
    {
        case Type::Pawn : return "P";
        case Type::Bishop : return "B";
        case Type::Knight : return "N";
        case Type::Rook : return "R";
        case Type::Queen : return "Q";
        case Type::King :  return "K";
        default: return " ";
    }
}