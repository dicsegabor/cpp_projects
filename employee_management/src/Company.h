#pragma once

#include "Department.h"

class Company
{
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &name;
        ar &departments;
    }

    std::string name;
    std::vector<Department> departments;

  public:
    Company() {}
    Company(std::string name) : name(name)
    {
        departments = std::vector<Department>();
    }

    void add_department(Department d);
    // Throws invalid_argument exception
    void add_employee(std::string department, Employee e);

    void delete_department(std::string);
};