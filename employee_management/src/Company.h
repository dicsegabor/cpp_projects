#pragma once

#include <boost/serialization/access.hpp>
#include <boost/serialization/list.hpp>
#include <string>
#include <list>

#include "Employee.h"

class Company
{
  private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    { 
      ar & name;
      ar & employees;
    }

    std::string name;
    std::list<Employee> employees;

  public:
    Company() {}
    Company(std::string name) : name(name)
    {
        employees = std::list<Employee>();
    }

    void add_employee(Employee e) { employees.push_back(e); }

    void print_data() const;
};