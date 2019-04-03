#include <fstream>
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<unsigned int, unsigned int> letters;
    std::fstream inFile;
    std::fstream outFile;
    inFile.open("data.txt", std::ios_base::in);

    unsigned int num;
    unsigned int value;
    unsigned int numLetter = 0;

    if (inFile.is_open()) {
        while (!inFile.eof()) {
            inFile >> num;
            inFile >> value;

            letters[num] += value;

            numLetter++;
            value = 0;
        }
    }

    inFile.close();

    unsigned int valueOfLetters = 0;
    outFile.open("vystup.txt", std::ios_base::out | std::ios_base::trunc);

    if (outFile.is_open()) {
        for (auto it = letters.begin(); it != letters.end(); it++) {
            outFile << it->first << " " << it->second << '\n';
            valueOfLetters += it->second;
        }
    }

    outFile.close();

    std::cout << "Letters: " << numLetter << '\n';  // eof on last line
    // std::cout << "Letters: " << numLetter - 1 << '\n'; // eof on line after last
    std::cout << "Value to pay: " << valueOfLetters << '\n';

    return 0;
}