//tests/test_sum.cpp
#include "gtest/gtest.h"
#include "sum.h"
#include <vector>
#include <numeric>
#include <list>
#include <array>
#include <tuple>

using namespace homework;

TEST(SumVector, Int){
    std::vector<int> vint = {1,2,3,4,5};
    auto sum_ints = sum_elements(vint);
    auto sum_ints_ref = std::accumulate(vint.begin(), vint.end(), 0);
    ASSERT_EQ(sum_ints,sum_ints_ref);
}

TEST(SumVector, Double){
    std::vector<double> vdouble = {1.1,2.2,3.3,4.4,5.5};
    auto sum_doubles = sum_elements(vdouble, 0.0);
    auto sum_doubles_ref = std::accumulate(vdouble.begin(), vdouble.end(), 0.0);
    ASSERT_NEAR(sum_doubles,sum_doubles_ref,1e-10);
}

TEST(SumVector, String){
    std::vector<std::string> vstring = {"hello", "world"};
    /*  advanced milestone
        We need to add std::string() to initialize the sum because writing "" would confuse the compiler
        and it would think it is a C string literal, char (aka a single character like 'p')
        Therefore, by passing std::string() we are essentially passing the same "" but the compiler knows its a string, not a char
    */
    auto sum_string = sum_elements(vstring, std::string());
    ASSERT_EQ(sum_string, "helloworld");
}

TEST(SumSequence, List){
    std::list<int> lint = {1,2,3,4,5};
    auto sum_ints = sum_elements(lint, 0);
    auto sum_ints_ref = std::accumulate(lint.begin(),lint.end(),0);
    ASSERT_EQ(sum_ints,sum_ints_ref);
}

TEST(SumSequence, Array){
    std::array<int,5> aint = {1,2,3,4,5};
    auto sum_ints = sum_elements(aint, 0);
    auto sum_ints_ref = std::accumulate(aint.begin(),aint.end(),0);
    ASSERT_EQ(sum_ints,sum_ints_ref);
}

TEST(SumVector, CustomType){
    struct MyType{
        int i;
        double d;

        // We need to add the overload += operator to support the summation in sum_elements
        MyType& operator+=(const MyType& other) {
            i += other.i;
            d += other.d;
            return *this;
        }

        // We need to add the overload == operator for ASSERT_EQ to work of MyType objects
        bool operator==(const MyType& other) const{
            return i == other.i && d == other.d;
        }

    };
    std::vector<MyType> vmt = {{1, 1.1}, {2, 2.2}, {3, 3.3}};
    auto sum_mts = sum_elements(vmt, MyType{0, 0.0});
    ASSERT_EQ(sum_mts, (MyType{6, 6.6}) );
}




TEST(Tuple, make){
    auto t = homework::make_tuple(1, 2.2, "hello");
    ASSERT_EQ(std::get<0>(t), 1);
    ASSERT_NEAR(std::get<1>(t),2.2,1e-10);
    ASSERT_EQ(std::get<2>(t),"hello");
}

TEST(Tuple, make2){
    auto t = homework::make_tuple("word", std::vector<int>{1,2,3});
    ASSERT_EQ(std::get<0>(t), "word");
    ASSERT_EQ(std::get<1>(t), (std::vector<int>{1,2,3}));
}
