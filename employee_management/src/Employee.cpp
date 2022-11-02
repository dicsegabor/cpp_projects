#include "Employee.h"

#include <iostream>

int Employee::number = 0;

Employee::Employee(
    std::string name, std::string job_title, std::string department, int age,
    int salary
)
    : name(name), job_title(job_title), department(department), id(number++),
      age(age), salary(salary)
{
}

void Employee::print_data() const { std::cout << id << ". " << name; }