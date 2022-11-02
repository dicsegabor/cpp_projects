#include "Company.h"
#include "Department.h"
#include <algorithm>
#include <stdexcept>

void Company::add_department(Department d) {}

void Company::add_employee(const std::string department, const Employee e)
{
    auto d = std::find_if(
        this->departments.begin(), this->departments.end(),
        [department](const Department &d) { return d.get_name() == department; }
    );

    if (d == this->departments.end())
        throw std::invalid_argument(
            "The '" + department + "' department doesn't exist!"
        );

    d->add_employee(e);
}

void Company::delete_department(std::string department) {}
