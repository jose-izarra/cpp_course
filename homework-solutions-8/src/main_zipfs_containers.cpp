#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
// #include "zipfs.h"


namespace zipfs {
    std::vector<char> readBook(std::string fileName) {
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

        while (ss) {
            ss >> word;

            if (m.contains(word)) {
                m[word]++;
            } else {
                m.insert({word, 1});
            }
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

        // for (auto it = m.begin(); it != m.end(); it++) {
            // f << rank << " " << it->first << " " << it->second << "\n";
            // rank++;
        // }
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

    auto v = zipfs::readBook("pg2701.txt");
    /* these can be commented out to see the content inside each of the variables
    std::cout << "Contents of the file" << std::endl;
    for (char &c: v) {
        std::cout << c;
    }
    */
    auto f = zipfs::computeWordFrequency(v);
    /*
    std::cout << "Word Frequency: " << std::endl;
    for (auto const& w: f) {
        std::cout << w.first  // string (key)
              << ':'
              << w.second // string's value
              << std::endl;
    }
    */

    int u = zipfs::countUniqueWords(v);
    std::cout << "Number of unique words: " << u << std::endl;

    auto multi = zipfs::sortFrequencies(f);
    /*
    for (auto const& i: multi) {
        std::cout << i.first  // frequency (key)
              << ':'
              << i.second // frequency's value (word)
              << std::endl;
    }
    */

    zipfs::writeFrequencyToFile(multi, "frequency.txt");
    zipfs::printHapaxLegomenon(multi);

    // do the same for the other text
    auto old_text = zipfs::readBook("old_text.txt"); // first 5 pages of el principito in spanish
    auto frequencies = zipfs::computeWordFrequency(old_text);
    auto multimap = zipfs::sortFrequencies(frequencies);
    zipfs::writeFrequencyToFile(multimap, "frequency_old_text.txt");
    zipfs::printHapaxLegomenon(multimap);

    return 0;

}
