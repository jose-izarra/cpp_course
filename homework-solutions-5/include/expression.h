#pragma once
#include <string>

namespace expression {
    class Expression {
        public:
            virtual std::string toString() const = 0;
            virtual double evaluate() const = 0;
    };

    class Constant: public Expression {
        private:
            double num;
        public:
            Constant (double d); // Constructor
            std::string toString() const override;
            double evaluate() const override;
    };

    class BinaryPlus: public Expression {
        private:
            const Expression& first;
            const Expression& second;
        public:
            BinaryPlus(const Expression& a, const Expression& b);
            std::string toString() const override;
            double evaluate() const override;
    };
}
