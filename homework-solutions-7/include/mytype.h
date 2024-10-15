#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace homework {

    class MyType {
        int i;
        double d;

        public:
            MyType(int i, double d) : i(i), d(d) {}

            auto operator==(const MyType& other) const {
                return i == other.i && d == other.d;
            }

            /**
             * @brief Stream insertion operator for MyType (serialization)
             */
            friend std::ostream& operator<<(std::ostream& os, const MyType& mt);

             /**
             * @brief Stream extraction operator for MyType (deserialization)
             */
            friend std::istream& operator>>(std::istream& is, MyType& mt);
    };

    /**
    * @brief Write the MyType object to a file
    * @param mt The MyType object to write
    * @param filename The name of the file to write to
    */
    void writeToFile(const MyType& mt, const std::string& filename);
    /**
    **
    * @brief Read the MyType object from a file
    * @param filename The name of the file to read from
    * @return The MyType object read from the file
    */
    MyType readFromFile(const std::string& filename);



} // namespace homework
