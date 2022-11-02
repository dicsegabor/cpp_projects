#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <fstream>
#include "Company.h"

#include <boost/archive/archive_exception.hpp>
#include <iostream>

int main()
{
    // Create object
    Company c = Company("Company");
    c.add_employee(Employee("Edgar", "Accountant", "Accounting", 56, 400000));

    // Serialize object
    {
        std::ofstream ofs("db");
        boost::archive::text_oarchive oa(ofs);
        oa << c;
    }

    // Create object, with deserialization
    Company c2;
    {
        std::ifstream ifs("db");
        boost::archive::text_iarchive ia(ifs);
        ia >> c2;
    }

    // Print object data
    {
        boost::archive::text_oarchive oa(std::cout);
        oa << c2;
    }

    return 0;
}