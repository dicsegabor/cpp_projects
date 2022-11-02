#include "Company.h"

#include <iostream>

void Company::print_data() const
{
    std::cout << name << "\n";
    for (const auto &e : employees)
    {
        std::cout << "\t";
        e.print_data();
        std::cout << "\n";
    }
}