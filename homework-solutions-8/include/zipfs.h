#pragma once
#include<vector>
#include<string>
#include<map>

/**
 * @namespace zipfs_containers
 */
namespace zipfs_containers {
    /**
     * @brief Reads the content of a book from a file, returning only alphabetic characters and spaces.
     * Replaces any non-alphabetic characters (except spaces) with spaces.
     * @param fileName The name of the file containing the text to read.
     * @return A vector of characters containing the book's text with non-alphabetic characters replaced by spaces.
     */
    std::vector<char> readBook(const std::string& fileName);

    /**
     * @brief Computes the frequency of each word in a given book.
     * Uses a map to store each unique word and its frequency count.
     * @param book A vector of characters containing the text of the book.
     * @return A map where each key is a unique word, and its corresponding value is the word's frequency.
     */
    std::map<std::string, int> computeWordFrequency(const std::vector<char>& book);

    /**
     * @brief Counts the number of unique words in a given book.
     * Uses a set to ensure each word is counted only once.
     * @param book A vector of characters containing the text of the book.
     * @return The count of unique words in the book.
     */
    int countUniqueWords(const std::vector<char>& book);

    /**
     * @brief Sorts word frequencies in descending order by frequency.
     * Uses a multimap to store each frequency and its corresponding word, allowing duplicate frequencies.
     * @param frequencies A map where each key is a unique word, and its value is the word's frequency.
     * @return A multimap with keys as frequencies and values as corresponding words, sorted in descending order of frequency.
     */
    std::multimap<int, std::string, std::greater<>> sortFrequencies(const std::map<std::string, int>& frequencies);

     /**
     * @brief Writes the sorted word frequencies to a file.
     * Uses structured binding to iterate over the multimap of frequencies.
     * @param m A multimap where keys are frequencies and values are words, sorted in descending order.
     * @param name The name of the file where the frequencies will be written.
     * The format of each line is: "rank frequency word".
     */
    void writeFrequencyToFile(const std::multimap<int, std::string, std::greater<>>& m, const std::string& name);

    /**
     * @brief Prints the count of hapax legomena (words that occur only once) and the first 10 examples.
     * Uses structured binding to iterate over the multimap.
     * @param m A multimap where keys are frequencies and values are words.
     * Only words with a frequency of 1 are considered hapax legomena.
     */
    void printHapaxLegomenon(const std::multimap<int, std::string, std::greater<>>& m);
}

/**
 * @namespace zipfs_algorithms
 */
namespace zipfs_algorithms {
    /**
     * @brief Reads the content of a book from a file, returning only alphabetic characters and spaces.
     * Replaces any non-alphabetic characters (except spaces) with spaces.
     * @param fileName The name of the file containing the text to read.
     * @return A vector of characters containing the book's text with non-alphabetic characters replaced by spaces.
     */
    std::vector<char> readBook(const std::string& fileName);

    /**
     * @brief Computes the frequency of each word in a given book.
     * @param book A vector of characters containing the text of the book.
     * @return A vector of pairs, where each pair consists of a word and its frequency count.
     * If a word already exists in the vector, its count is incremented; otherwise, a new entry is created.
     */
    std::vector<std::pair<std::string, int>> computeWordFrequency(const std::vector<char>& book);

    /**
     * @brief Counts the number of unique words in a given book.
     * @param book A vector of characters containing the text of the book.
     * @return The count of unique words in the book.
     */
    int countUniqueWords(const std::vector<char>& book);

    /**
     * @brief Sorts word frequencies in descending order by frequency.
     * @param frequencies A vector of pairs, each containing a word and its frequency.
     * @return A vector of pairs, each containing a frequency and the corresponding word,
     * sorted in descending order of frequency.
     */
    std::vector<std::pair<int, std::string>> sortFrequencies(const std::vector<std::pair<std::string, int>>& frequencies);

    /**
     * @brief Writes the sorted word frequencies to a file.
     * @param frequencies A vector of pairs containing the frequency and corresponding word,
     * sorted in descending order.
     * @param name The name of the file where the frequencies will be written.
     * The format of each line is: "rank frequency word".
     */
    void writeFrequencyToFile(const std::vector<std::pair<int, std::string>> frequencies, const std::string& name);

    /**
     * @brief Prints the count of hapax legomena (words that occur only once) and the first 10 examples.
     * @param frequencies A vector of pairs containing the frequency and corresponding word.
     * Only words with a frequency of 1 are considered hapax legomena.
     */
    void printHapaxLegomenon(const std::vector<std::pair<int, std::string>> frequencies);
}
