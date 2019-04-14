#include <fstream>
#include <iostream>
#include <vector>

#include "comprec.hpp"

int main() {
    CompRec rec;
    std::string buffer;
    std::fstream inFile;

    inFile.open("data.txt", std::ios_base::in);

    if (inFile.is_open()) {
        while (!inFile.eof()) {
            getline(inFile, buffer);
            rec.getData(buffer);
        }
    }

    rec.calcHours();
    rec.printHours();
}