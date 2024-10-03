#include "gtest/gtest.h"
#include "expression.h"
#include <string>
#include <tuple>
#include <vector>




TEST(ExpressionTest, ConstantClass) {
    expression::Constant c1(1);
    expression::Constant c2(2);
    expression::Constant c3(3);

    std::string c1_str = c1.toString();
    std::string c2_str = c2.toString();
    std::string c3_str = c3.toString();

    double c1_eval = c1.evaluate();
    double c2_eval = c2.evaluate();
    double c3_eval = c3.evaluate();

    ASSERT_EQ(c1_str, "1.000000"); // tests prove wrong due to the amounts of 0s so I need to add them
    ASSERT_EQ(c2_str, "2.000000");
    ASSERT_EQ(c3_str, "3.000000");

    ASSERT_EQ(c1_eval, 1);
    ASSERT_EQ(c2_eval, 2);
    ASSERT_EQ(c3_eval, 3);
}


TEST(ExpressionTest, BinaryPlusClass) {
    expression::Constant c1(1);
    expression::Constant c2(2);
    expression::Constant c3(3);

    expression::BinaryPlus bp(c1, c2);
    expression::BinaryPlus bp2(bp, c3);

    std::string c1plusc2plusc3 = bp2.toString();

    double result = bp2.evaluate();

    ASSERT_EQ(c1plusc2plusc3, "((1.000000, 2.000000), 3.000000)");
    ASSERT_EQ(result, 6);
}
