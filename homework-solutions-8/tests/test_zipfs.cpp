#include "gtest/gtest.h"
#include "zipfs.h"

#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>

#include<string>
#include<set>
#include<vector>
#include<map>


// this is an initializer provided by Google Test to initialize the setup once and are usable throughout
// I am using this to write the content of the file only once
// To be able to use the variables defined here, I need to use TEST_F for my tests instead of TEST
// I found out about this through gpt and thought it was really useful for this case
class ZipfsTest : public ::testing::Test {
protected:
    static const std::string fileName;
    static const std::string fileContent;

    // Runs once for all tests in this test suite
    static void SetUpTestSuite() {
        // Write the content to the file once
        std::ofstream test_file(fileName);
        test_file << fileContent;
        test_file.close();
    }

    // Cleans up after all tests in the suite are done
    static void TearDownTestSuite() {
        // Remove the file to clean up
        std::remove(fileName.c_str());
    }
};

// Initialize static constants
const std::string ZipfsTest::fileName = "test.txt";
const std::string ZipfsTest::fileContent = "This ! . . is my test @ file"
                                                     ". It contains s some random Content ? is test test";



// zipfs_containers tests
TEST_F(ZipfsTest, ReadBookTest) { // only one test for this function since it is the same in both namespaces

    // create the expected output
    std::vector<char> expected;
    std::for_each(fileContent.begin(), fileContent.end(), [&expected](const auto& c){
        if (std::isalpha(c) || std::isspace(c)){
            expected.push_back(c);
        } else {
            expected.push_back(' ');
        }
    });


    auto result = zipfs_containers::readBook(fileName);

    ASSERT_EQ(result, expected);
}


TEST_F(ZipfsTest, ComputeWordFrequencyTestContainer) {
    auto book = zipfs_containers::readBook(fileName);
    auto result = zipfs_containers::computeWordFrequency(book);

    std::map<std::string, int> expected = {
        {"This", 1}, {"is", 2}, {"my", 1}, {"test", 3}, {"file", 1},
        {"It", 1}, {"contains", 1}, {"s", 1}, {"some", 1}, {"random", 1}, {"Content", 1}
    };

    ASSERT_EQ(result["This"], 1);
    ASSERT_EQ(result["test"], 3);
    ASSERT_EQ(result["is"], 2);

    // Additionally, check that no extra words are present in frequencies
    ASSERT_EQ(result.size(), 11) << "Frequencies map contains extra words"; // there are 11 words in the text
}

TEST_F(ZipfsTest, CountUniqueWordsTestContainer) {
    auto book = zipfs_containers::readBook(fileName);
    auto result = zipfs_containers::countUniqueWords(book);

    ASSERT_EQ(result, 11); // 11 unique words
}


TEST_F(ZipfsTest, SortFrequenciesTestContainer) {
    auto book = zipfs_containers::readBook(fileName);
    auto frequencies = zipfs_containers::computeWordFrequency(book);
    auto sortedFrequencies = zipfs_containers::sortFrequencies(frequencies);

    // Checking that the next frequency is smaller than or equal the current
    int previousFrequency = sortedFrequencies.begin()->first;
    for (const auto& [frequency, word] : sortedFrequencies) {
        ASSERT_LE(frequency, previousFrequency) << "Frequencies are not in descending order";
        previousFrequency = frequency;  // Update previous frequency
    }
}


// zipfs_algorithms tests
TEST_F(ZipfsTest, ComputeWordFrequencyTestAlgorithms) {
    auto book = zipfs_containers::readBook(fileName);
    auto frequencies = zipfs_algorithms::computeWordFrequency(book);

    std::vector<std::pair<std::string, int>> expected = {
        {"This", 1},
        {"is", 2},
        {"my", 1},
        {"test", 3},
        {"file", 1},
        {"It", 1},
        {"contains", 1},
        {"s", 1},
        {"some", 1},
        {"random", 1},
        {"Content", 1}
    };

    for (const auto& [word, count] : expected) {
        auto it = std::find_if(frequencies.begin(), frequencies.end(),
                               [&word](const auto& pair) { return pair.first == word; });
        ASSERT_NE(it, frequencies.end()) << "Word '" << word << "' not found in frequencies";
        ASSERT_EQ(it->second, count) << "Frequency mismatch for word '" << word << "'";
    }


    // Additionally, check that no extra words are present in frequencies
    ASSERT_EQ(frequencies.size(), 11) << "Frequencies map contains extra words";
}

TEST_F(ZipfsTest, CountUniqueWordsTestAlgorithms) {
    auto book = zipfs_containers::readBook(fileName);
    auto result = zipfs_algorithms::countUniqueWords(book);

    ASSERT_EQ(result, 13);
}

TEST_F(ZipfsTest, SortFrequenciesTestAlgorithms) {
    auto book = zipfs_containers::readBook(fileName);
    auto frequencies = zipfs_algorithms::computeWordFrequency(book);
    auto sortedFrequencies = zipfs_algorithms::sortFrequencies(frequencies);

    // Check that each frequency is in descending order
    int previousFrequency = sortedFrequencies.begin()->first;
    for (const auto& [frequency, word] : sortedFrequencies) {
        ASSERT_LE(frequency, previousFrequency) << "Frequencies are not in descending order";
        previousFrequency = frequency;  // Update previous frequency for the next iteration
    }
}
