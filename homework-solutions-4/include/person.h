#pragma once
#include<iostream>
#include <tuple>
#include <string>
#include <vector>
#include <random>

namespace person_lib
{

    class Person {
        public:
            std::string name; ///< Name of the person.
            int age; ///< Age of the person.
            std::vector<std::string> hobbies; ///< Hobbies of the person.

    };

};
