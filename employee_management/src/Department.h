#pragma once

#include <boost/serialization/access.hpp>
#include <boost/serialization/vector.hpp>
#include <vector>
#include <string>

#include "Employee.h"

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
    Department(std::string name) : name(name), employees(std::vector<Employee>()) {}

    void add_employee(const Employee &e) { employees.push_back(e); }

    const std::string get_name() const { return this->name; }

    bool operator<(const Department &other) { return this->name < other.name; }
};