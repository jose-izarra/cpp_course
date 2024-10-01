#pragma once
#include<iostream>
#include <tuple>
#include <string>
#include <vector>
#include <random>

namespace student_class
{
    /**
     * @brief Generates random student information.
     *
     * This function creates a random student's name, age, and GPA.
     *
     * @return A tuple containing a string (name), an integer (age), and a double (GPA).
     */
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

    /**
     * @brief Represents a student with associated information and courses.
     *
     * The Student class holds a student's name, age, GPA, and a list of enrolled courses.
     * It provides methods to retrieve and modify this information.
     */
    class Student
    {
        public:
            // Forward declaration of the nested Course class
            /**
             * @brief Represents a course taken by a student.
             */
            class Course;

        private:
            static int student_count;  ///< Tracks the total number of Student objects created.
            std::vector<Student::Course> courses;  ///< List of courses the student is enrolled in.
            std::string name;  ///< Name of the student.
            int age;  ///< Age of the student.
            double gpa;  ///< GPA of the student.
        public:
            /**
             * @brief Gets the student's name.
             * @return The name of the student.
             */
            std::string get_name() const{
                return this->name;
            }

            /**
             * @brief Gets the student's age.
             * @return The age of the student.
             */
            int get_age() const{
                return this->age;
            }

            /**
             * @brief Gets the student's GPA.
             * @return The GPA of the student.
             */
            double get_gpa() const{
                return this->gpa;
            }

            /**
             * @brief Gets the list of courses the student is enrolled in.
             * @return A vector containing the student's enrolled courses.
             */
            std::vector<Student::Course> get_courses() const{
                return this->courses;
            }

            /**
             * @brief Sets the student's name.
             * @param name The name to set for the student.
             */
            void set_name(std::string name) {
                this->name = name;
            }

            /**
             * @brief Sets the student's age.
             *
             * Validates that the age is between 0 and 120.
             *
             * @param age The age to set for the student.
             * @throws std::invalid_argument if the age is not in a valid range.
             */
            void set_age(int age) {
                if ( !(age >= 0 && age < 120) ) {
                    throw std::invalid_argument("Invalid age");
                } else {
                    this->age = age;
                }
            }

            /**
             * @brief Sets the student's GPA.
             *
             * Validates that the GPA is between 0.0 and 10.0.
             *
             * @param gpa The GPA to set for the student.
             * @throws std::invalid_argument if the GPA is not in a valid range.
             */
            void set_gpa(double gpa) {
                if ( !(gpa >= 0.0 && gpa <= 10.0) ) {
                    throw std::invalid_argument("Invalid GPA");
                } else {
                    this->gpa = gpa;
                }
            }
            /**
             * @brief Sets the student's name.
             *
             * @param name The name to set for the student.
             */
            void setName(std::string newName) {
                name = newName;
            }
             /**
             * @brief Prints the student's information.
             *
             * Outputs the student's name, age, and GPA to the standard output.
             */

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
