#include "expression.h"
#include <iostream>
#include <cassert>
#include<string>
#include <vector>

using namespace expression;

namespace expression {
    // definition for Expression
    // std::string Expression::toString() const {};
    // double Expression::evaluate() const {};


    // definitions for Constant
    Constant::Constant(double d): num(d) {};

    // override already defined in header file
    std::string Constant::toString() const {
        return std::to_string(num);
    }

    double Constant::evaluate() const {
        return num;
    }

    // definitions for BinaryPlus
    BinaryPlus::BinaryPlus(const Expression& a, const Expression& b): first(a), second(b) {}; // constructuro definition

    std::string BinaryPlus::toString() const {
        return "(" + first.toString() + ", " + second.toString() + ")";
    }

    double BinaryPlus::evaluate() const {
        return first.evaluate() + second.evaluate();
    }
}


void printExpression(const Expression& a) {
    std::cout << "Expression: " << a.toString() << ", Evaluate: " << a.evaluate() << std::endl;
}

int main() {
    // Inheritance in action.
    //Constant and BinaryPlus are both children of Expression
    Constant c1(1);
    Constant c2(2);
    Constant c3(3);

    BinaryPlus bp(c1, c2);
    BinaryPlus bp2(bp, c3);

    std::string c1plusc2plusc3 = bp2.toString();

    double result = bp2.evaluate();
    std::cout << c1plusc2plusc3 << " = " << result << std::endl; // ((1 +2) + 3) = 6

    assert(result == 6);

    // Polymorphism in action
    std::vector<const Expression*> expressions = {&c1, &c2, &c3, &bp, &bp2};
    for (const Expression* e_ptr : expressions) {
        const Expression& e = *e_ptr;
        printExpression(e);
    }

    return 0;

}
