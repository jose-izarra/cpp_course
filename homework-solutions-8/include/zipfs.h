#pragma once
#include<vector>
#include<string>
#include <map>


namespace zipfs {
    std::vector<char> readBook(std::string fileName);


    std::map<std::string, int> computeWordFrequency(const std::vector<char>& book);

    int countUniqueWords(const std::vector<char>& book);

    std::multimap<int, std::string> sortFrequencies(const std::map<std::string, int>& frequencies);

    void writeFrequencyToFile(const std::multimap<int, std::string, std::greater<>>& m);

    void printHapaxLegomenon(const std::multimap<int, std::string, std::greater<>>& m);
}
