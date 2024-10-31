#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include "zipfs.h"

namespace zipfs_algorithms {
    std::vector<char> readBook(const std::string& fileName) {
        std::ifstream f(fileName);
        char c;
        std::vector<char> v;

        while (f.get(c)) {
            if (std::isalpha(c) || std::isspace(c)) {
                v.push_back(c);
            } else {
                v.push_back(' ');
            }
        }
        return v;
    }

    std::vector<std::pair<std::string, int>> computeWordFrequency(const std::vector<char>& book) {
        std::vector<std::pair<std::string, int>> result;

        std::string s(book.begin(), book.end());
        std::istringstream ss(s);
        std::string word;

        while (ss >> word) {
            /* explaining this lambda function:
                - the current word is passed by reference so that it can be used inside
                - its input is each item in the vector, type std::pair<std::string,int>
                - returns an iterator object if the object exists, returns result.end() if not
            */
            auto find_lambda = [&word](const std::pair<std::string, int>& e) {
                return e.first == word;
            };
            auto it = std::find_if(result.begin(), result.end(), find_lambda);
            if (it != result.end()) {
                it->second++;
            } else {
                result.push_back({ word, 1});
            }
        }

        return result;
    }

    int countUniqueWords(const std::vector<char>& book) {
        std::string s(book.begin(), book.end());
        std::istringstream ss(s);
        // istream_iterator goes over the istringstream "ss" object and initializes the vector
        // gpt reccomended this
        std::vector<std::string> words((std::istream_iterator<std::string>(ss)), std::istream_iterator<std::string>());

        //
        auto uniqueEnd = std::unique(words.begin(), words.end());
        int count = 0;
        for (auto it = words.begin(); it != uniqueEnd; it++) {
            count++;
        }
        return count;
    }

    std::vector<std::pair<int, std::string>> sortFrequencies(const std::vector<std::pair<std::string, int>>& frequencies) {
        std::vector<std::pair<int, std::string>> result;

        std::for_each(frequencies.begin(), frequencies.end(), [&result](const auto& e){
            result.push_back({ e.second, e.first });
        });

        std::sort(result.begin(), result.end(), [](const auto& a, const auto& b){
            return a.first > b.first;
        });

        return result;
    }

    void writeFrequencyToFile(const std::vector<std::pair<int, std::string>> frequencies, const std::string& name) {
        std::ofstream f(name);
        int rank = 1;
        std::for_each(frequencies.begin(), frequencies.end(), [&](const auto& e){
            f << rank << " " << e.first<< " " << e.second << "\n";
            rank++;
        });
    }

    void printHapaxLegomenon(const std::vector<std::pair<int, std::string>> frequencies) {
        int count = 0;
        std::vector<std::string> words;

        std::for_each(frequencies.begin(), frequencies.end(), [&](const auto& e){
            if (e.first == 1) {
                count++;
                if (words.size() < 10) {
                    words.push_back(e.second);
                }
            }
        });

        std::cout << "Number of hapax legomena: " << count << std::endl;
        std::cout << "The first 10 are: ";
        std::for_each(words.begin(), words.end(), [](const auto& word){
            std::cout << word << " ";
        });
        std::cout << std::endl;
    }
}

int main() {

    auto v = zipfs_algorithms::readBook("../pg2701.txt");
    auto f = zipfs_algorithms::computeWordFrequency(v);
    int u = zipfs_algorithms::countUniqueWords(v);
    auto m = zipfs_algorithms::sortFrequencies(f);
    zipfs_algorithms::writeFrequencyToFile(m, "../frequency.txt");
    zipfs_algorithms::printHapaxLegomenon(m);

    // do the same for the other text
    auto v2 = zipfs_algorithms::readBook("../old_text.txt"); // first 5 pages of el principito in spanish
    auto f2 = zipfs_algorithms::computeWordFrequency(v2);
    auto multi2 = zipfs_algorithms::sortFrequencies(f2);
    zipfs_algorithms::writeFrequencyToFile(multi2, "../frequency_old_text.txt");
    zipfs_algorithms::printHapaxLegomenon(multi2);


    return 0;
}
