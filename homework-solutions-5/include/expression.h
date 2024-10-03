#pragma once
#include <string>

namespace expression {
     /**
     * @brief Abstract base class for all expressions.
     *
     * The Expression class serves as the base for different types of mathematical expressions.
     * It defines two pure virtual methods that must be overridden by any derived class:
     * - `toString()` to return a string representation of the expression.
     * - `evaluate()` to evaluate the expression and return its result as a double.
     */
    class Expression {
        public:
            /**
             * @brief Returns a string representation of the expression.
             *
             * This is a pure virtual function, meaning derived classes must implement it.
             *
             * @return std::string A string representing the expression.
             */
            virtual std::string toString() const = 0;

            /**
             * @brief Evaluates the expression and returns its result.
             *
             * This is a pure virtual function, meaning derived classes must implement it.
             *
             * @return double The result of evaluating the expression.
             */
            virtual double evaluate() const = 0;

            /**
             * @brief Virtual destructor for the Expression class.
             *
             * This is a virtual destructor, meaning derived classes can override it.
             */
            virtual ~Expression() = default;
    };

    /**
     * @brief Represents a constant number in an expression.
     *
     * The Constant class holds a single constant value and is a concrete implementation
     * of the Expression class. It overrides the `toString()` and `evaluate()` methods
     * to return the constant as a string and to return the value of the constant, respectively.
     */
    class Constant: public Expression {
        private:
            double num; ///< The constant value.
        public:
            /**
             * @brief Constructs a Constant object with a given value.
             *
             * @param d The constant value.
             */
            Constant (double d); // Constructor

            /**
             * @brief Returns a string representation of the constant.
             *
             * @return std::string The string representation of the constant.
             */
            std::string toString() const override;

            /**
             * @brief Returns the value of the constant.
             *
             * @return double The value of the constant.
             */
            double evaluate() const override;
    };

    /**
     * @brief Represents the addition of two expressions.
     *
     * The BinaryPlus class is a concrete implementation of the Expression class,
     * representing the addition of two expressions. It takes two expressions as
     * input and returns the result of adding them together.
     */
    class BinaryPlus: public Expression {
        private:
            const Expression& first;  ///< The first expression in the addition.
            const Expression& second; ///< The second expression in the addition.
        public:
            /**
             * @brief Constructs a BinaryPlus object with two expressions.
             *
             * @param a The first expression.
             * @param b The second expression.
             */
            BinaryPlus(const Expression& a, const Expression& b);

            /**
             * @brief Returns a string representation of the addition expression.
             *
             * @return std::string The string representation of the addition expression.
             */
            std::string toString() const override;

            /**
             * @brief Evaluates the addition of the two expressions and returns the result.
             *
             * @return double The result of adding the two expressions.
             */
            double evaluate() const override;
    };
} // namespace expression
