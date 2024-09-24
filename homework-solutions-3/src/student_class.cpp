#include<iostream>
#include<tuple>
#include<string>
#include"student_class.h"


int main()
{
    student_class::Student s1;
    s1.setName("John");
    s1.set_age(20);
    s1.set_gpa(3.5);

    const student_class::Student::Course c1("Math", 2021);
    const student_class::Student::Course c2("English", 2021);

    s1.enroll(c1);
    s1.enroll(c2);

    s1.printInfo();
    s1.printCourses();

    return 0;
}
