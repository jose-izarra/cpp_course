#include "split.h"
#include <vector>
#include <string>
#include <iostream>


namespace homework {

    std::vector<std::string> split(const std::string& str) {
        std::vector<std::string> result;
        int N = str.length();
        int i = 0;

        // to keep track of start and end of each word
        int start = 0;
        int end = 0;

        while (i < N) {
            while (i < N && str[i] == ' ') { i++; }

            start = i;
            while (i < N && str[i] != ' ') { i++; }
            end = i;

            std::string word;

            if (start < i) {  // Ensure a valid word was found
                result.push_back(str.substr(start, i - start));
            }
        }

        return result;
    }
}
