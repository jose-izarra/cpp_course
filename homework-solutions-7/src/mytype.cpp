#include "mytype.h"
#include <fstream>
#include <string>
#include <iostream>


namespace homework {
    /**
     * @brief Stream insertion operator for MyType (serialization)
     */
    std::ostream& operator<<(std::ostream& os, const MyType& mt) {
        os << mt.i << " " << mt.d;
        return os;
    }

    /**
     * @brief Stream extraction operator for MyType (deserialization)
     */
    std::istream& operator>>(std::istream& is, MyType& mt) {
        is >> mt.i >> mt.d;
        return is;
    }

    void writeToFile(const MyType& mt, const std::string& filename) {
        // Write the MyType object to a file with the given filename
        std::ofstream file(filename, std::ios::out); // std::ios::out -> This mode is used to open a file for writing. If the file already exists, its contents are erased/
        if (!file) {
            std::cerr << "Error opening file" << std::endl;
            return;
        }

        file << mt << std::endl;
    }

    MyType readFromFile(const std::string& filename) {
        // Read the MyType object from a file with the given filename and
        std::ifstream ifs(filename);
        if (!ifs) {
            throw std::runtime_error("Could not open file for reading");
        }
        MyType mt(0, 0.0);  // Initial values will be overwritten by >>
        ifs >> mt;  // Use the >> operator defined for MyType
        return mt;
    }
}




int main() {
    homework::MyType mt(42,3.14);
    homework::writeToFile(mt,"mytype.txt");
    auto mt2 = homework::readFromFile("mytype.txt");
    return 0;
}
