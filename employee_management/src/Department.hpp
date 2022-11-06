#pragma once

#include <boost/serialization/access.hpp>
#include <boost/serialization/vector.hpp>
#include <string>
#include <vector>

#include "Employee.hpp"

class Department
{
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &name;
        ar &employees;
    }

    std::string name;
    std::vector<Employee> employees;

  public:
    Department() {}
    Department(const Department &other)
    {
        name      = other.name;
        employees = std::vector<Employee>(other.employees);
    }
    Department(std::string name)
        : name(name), employees(std::vector<Employee>())
    {
    }

    void add_employee(const Employee &e) { employees.push_back(e); }

    const std::string get_name() const { return name; }

    bool operator<(const Department &other) const { return name < other.name; }
};