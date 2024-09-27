#pragma once
#include<iostream>
#include <tuple>
#include <string>
#include <vector>
#include <random>

namespace student_class
{
    std::tuple<std::string, int, double> generateStudentInfo()
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> int_dis(0, 9);
            std::uniform_int_distribution<int> int_dis2(18, 25);
            std::uniform_real_distribution<double> double_dis(0.0, 10.0);

            std::string list_of_names[] = {"John", "Jane", "Doe", "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller"};
            std::string name = list_of_names[int_dis(gen)];
            int age = int_dis2(gen);
            double gpa = double_dis(gen);

            auto student_info = std::make_tuple(name, age, gpa);
            return student_info;
        }

    class Student
    {
        public:
            // Forward declaration of the nested Course class
            class Course;

        private:
            static int student_count;
            std::vector<Student::Course> courses;
            std::string name;
            int age;
            double gpa;
        public:

            std::string get_name() const{
                return this->name;
            }
            int get_age() const{
                return this->age;
            }
            double get_gpa() const{
                return this->gpa;
            }

            std::vector<Student::Course> get_courses() const{
                return this->courses;
            }

            void set_name(std::string name) {
                this->name = name;
            }


            void set_age(int age) {
                if ( !(age >= 0 && age < 120) ) {
                    throw std::invalid_argument("Invalid age");
                } else {
                    this->age = age;
                }
            }

            void set_gpa(double gpa) {
                if ( !(gpa >= 0.0 && gpa <= 10.0) ) {
                    throw std::invalid_argument("Invalid GPA");
                } else {
                    this->gpa = gpa;
                }
            }

            void setName(std::string newName) {
                name = newName;
            }

            void printInfo() const{
                std::cout << "Name: " << this->name << std::endl;
                std::cout << "Age: " << this->age << std::endl;
                std::cout << "GPA: " << this->gpa << std::endl;
            }

            Student() {
                student_count++;
                this->name = "";
                this->age = 0;
                this->gpa = 0.0;
            }

            Student(std::string name, int age, double gpa) {
                if ( !(age >= 0 && age < 120) ) {
                    throw std::invalid_argument("Invalid age");
                } else if ( !(gpa >= 0.0 && gpa <= 10.0) ) {
                    throw std::invalid_argument("Invalid GPA");
                } else {
                    this->name = name;
                    this->age = age;
                    this->gpa = gpa;

                    student_count++;
                }
            }

            static int get_student_count() {
                return student_count;
            }

            friend bool compareGrade(const Student& a, const Student& b);

            void enroll(const Student::Course& c) {
                this->courses.push_back(c);
            }

            void printCourses() {
                std::cout << "------ Printing Courses -----" << std::endl;
                for (auto c: this->courses) {
                    std::cout << "Course: " << c.courseName << ", Year: " << c.year << std::endl;
                }
            }

            class Course {
                public:
                    std::string courseName;
                    int year;
                    Course(std::string courseName, int year): courseName(courseName), year(year) {};
            };
    };

    int Student::student_count = 0;


    // when redefining this, an error is thrown

    // void Student::printInfo() const{
    //     std::cout << "Name: " << this->name << std::endl;
    //     std::cout << "Age: " << this->age << std::endl;
    //     std::cout << "GPA: " << this->gpa << std::endl;
    // };

    bool compareGrade(const Student& a, const Student& b) {
        if ( a.gpa > b.gpa ) { return true; }
        else { return false; }
    }

}
