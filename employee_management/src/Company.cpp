#include "Company.hpp"

#include <algorithm>
#include <stdexcept>

void Company::add_department(Department d) { departments.insert(d); }

void Company::delete_department(std::string department)
{
    departments.erase(department);
}

void Company::add_employee(const std::string department, const Employee e)
{
    auto d = departments.find(department);

    if (d == departments.end())
        throw std::invalid_argument(
            "The '" + department + "' department doesn't exist!"
        );

    auto new_department = Department(*d);
    new_department.add_employee(e);

    departments.erase(d);
    departments.insert(new_department);
}
