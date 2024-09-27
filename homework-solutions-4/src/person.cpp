#include<iostream>
#include<tuple>
#include<string>
#include<vector>

#include "person.h"


int main()
{
    person_lib::Person p1{"Alice", 30, {"reading", "hiking"}};
    person_lib::Person p2 = p1; // Compiler-generated copy constructor
    p2.name = "Bob";
    p2.hobbies.push_back("swimming");


    return 0;

}
