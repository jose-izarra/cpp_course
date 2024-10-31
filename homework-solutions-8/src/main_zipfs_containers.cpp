#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include "zipfs.h"


namespace zipfs_containers {
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

    std::map<std::string, int> computeWordFrequency(const std::vector<char>& book) {
        std::map<std::string, int> m;

        std::string s(book.begin(), book.end());
        std::istringstream ss(s);
        std::string word;

        while (ss >> word) {
            m[word]++;
        }

        return m;
    }

    int countUniqueWords(const std::vector<char>& book) {
        std::set<std::string> container;

        std::string s(book.begin(), book.end());
        std::istringstream ss(s);
        std::string word;

        while (ss) {
            ss >> word;
            container.insert(word);
        }
        return container.size();
    }

    std::multimap<int, std::string, std::greater<>> sortFrequencies(const std::map<std::string, int>& frequencies) {
        std::multimap<int, std::string, std::greater<>> result;

        using mypair = std::pair<int, std::string>; // useian alias for better visibility

        for (auto const& p: frequencies) {
            result.insert(mypair(p.second, p.first));
        }

        return result;
    }

    void writeFrequencyToFile(const std::multimap<int, std::string, std::greater<>>& m, const std::string& name) {
        std::ofstream f(name);
        int rank = 1;

        // with structured-binding for advanced milestone
        for (const auto& [freq, word] : m) {
            f << rank << " " << freq << " " << word << "\n";
            rank++;
        }
    }

    void printHapaxLegomenon(const std::multimap<int, std::string, std::greater<>>& m) {
        int count = 0;
        std::vector<std::string> words;

        for (const auto& [freq, word] : m) {
            if (freq == 1) {
                count++;
                if (words.size() < 10) {
                    words.push_back(word); // only save 10 examples
                }
            }
        }

        std::cout << "Number of hapax legomena: " << count << std::endl;
        std::cout << "Some of them are: ";
        for (const auto& w : words) {
            std::cout << w << " ";
        }
        std::cout << std::endl;
    }
}


int main() {

    auto v = zipfs_containers::readBook("../pg2701.txt");
    /* these can be commented out to see the content inside each of the variables
    std::cout << "Contents of the file" << std::endl;
    for (char &c: v) {
        std::cout << c;
    }
    */
    auto f = zipfs_containers::computeWordFrequency(v);
    /*
    std::cout << "Word Frequency: " << std::endl;
    for (auto const& w: f) {
        std::cout << w.first  // string (key)
              << ':'
              << w.second // string's value
              << std::endl;
    }
    */

    int u = zipfs_containers::countUniqueWords(v);
    std::cout << "Number of unique words: " << u << std::endl;

    auto multi = zipfs_containers::sortFrequencies(f);
    /*
    for (auto const& i: multi) {
        std::cout << i.first  // frequency (key)
              << ':'
              << i.second // frequency's value (word)
              << std::endl;
    }
    */

    zipfs_containers::writeFrequencyToFile(multi, "../frequency.txt");
    zipfs_containers::printHapaxLegomenon(multi);

    // do the same for the other text
    auto v2 = zipfs_containers::readBook("../old_text.txt"); // first 5 pages of el principito in spanish
    auto f2 = zipfs_containers::computeWordFrequency(v2);
    auto multi2 = zipfs_containers::sortFrequencies(f2);
    zipfs_containers::writeFrequencyToFile(multi2, "../frequency_old_text.txt");
    zipfs_containers::printHapaxLegomenon(multi2);

    return 0;
}
