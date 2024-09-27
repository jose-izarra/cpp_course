#include "gtest/gtest.h"
#include "student_class.h"
#include <string>
#include <tuple>
#include <vector>

TEST(GenerateInfo, TupleTest) {
    std::tuple<std::string, int, double> info = student_class::generateStudentInfo();

    std::string name = std::get<0>(info);
    int age = std::get<1>(info);
    double gpa = std::get<2>(info);

    // this test was done by copilot
    EXPECT_TRUE(name != "");
    EXPECT_TRUE(age >= 0 && age < 120);
    EXPECT_TRUE(gpa >= 0.0 && gpa <= 10.0);

}


TEST(StudentTest, InitializeTest) {
    student_class::Student s;
    EXPECT_EQ(s.get_name(), "");
    EXPECT_EQ(s.get_age(), 0);
    EXPECT_EQ(s.get_gpa(), 0.0);

    student_class::Student s2("John", 20, 3.5);
    EXPECT_EQ(s2.get_name(), "John");
    EXPECT_EQ(s2.get_age(), 20);
    EXPECT_EQ(s2.get_gpa(), 3.5);
}



TEST(StudentTest, GetterTests) {
    student_class::Student s("John", 20, 3.5);

    EXPECT_EQ(s.get_name(), "John");
    EXPECT_EQ(s.get_age(), 20);
    EXPECT_EQ(s.get_gpa(), 3.5);
}

TEST(StudentTest, SetterTests) {
    student_class::Student s;

    s.set_name("John");
    s.set_gpa(7.5);
    s.set_age(20);

    EXPECT_EQ(s.get_name(), "John");
    EXPECT_EQ(s.get_gpa(), 7.5);
    EXPECT_EQ(s.get_age(), 20);

    EXPECT_THROW(s.set_age(-1), std::invalid_argument);
    EXPECT_THROW(s.set_age(121), std::invalid_argument);

    EXPECT_THROW(s.set_gpa(-1.0), std::invalid_argument);
    EXPECT_THROW(s.set_gpa(10.1), std::invalid_argument);
}


TEST(StudentTest, PrintInfoTest) {
    student_class::Student s("John", 20, 3.5);

    testing::internal::CaptureStdout();
    s.printInfo();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = "Name: John\nAge: 20\nGPA: 3.5\n";
    EXPECT_EQ(output, expected_output);
}


TEST(StudentTest, StudentCountTest) {
    student_class::Student s1;
    student_class::Student s2;

    EXPECT_EQ(s1.get_student_count(), 2);
    EXPECT_EQ(s2.get_student_count(), 2);



    student_class::Student s3;

    EXPECT_EQ(s1.get_student_count(), 3);
    EXPECT_EQ(s2.get_student_count(), 3);
    EXPECT_EQ(s3.get_student_count(), 3);
}

TEST(StudentTest, CourseEnroll) {
    student_class::Student s("John", 20, 3.5);

    student_class::Student::Course c1("Math", 2024);
    student_class::Student::Course c2("Physics", 2024);
    student_class::Student::Course c3("Programming", 2023);

    s.enroll(c1);
    s.enroll(c2);
    s.enroll(c3);

    auto courses = s.get_courses();

    EXPECT_EQ(courses.size(), 3);

    EXPECT_EQ(courses[0].courseName, "Math");
    EXPECT_EQ(courses[0].year, 2024);

    EXPECT_EQ(courses[1].courseName, "Physics");
    EXPECT_EQ(courses[1].year, 2024);

    EXPECT_EQ(courses[2].courseName, "Programming");
    EXPECT_EQ(courses[2].year, 2023);
}
