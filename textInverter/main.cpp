#include <fstream>
#include <iostream>

int main() {
    std::fstream inFile;
    std::fstream outFile;

    inFile.open("data.txt", std::ios_base::in);
    outFile.open("iData.txt", std::ios_base::out | std::ios_base::trunc);

    if (inFile.is_open() && outFile.is_open()) {
        char temp;
        char cmp;

        while (inFile >> temp) {
            cmp = tolower(temp);
            if (cmp != temp) {
                outFile << cmp;
                std::cout << cmp << '\n';
            } else {
                outFile << (char)toupper(temp);
                std::cout << (char)toupper(temp) << '\n';
            }
        }
    }

    inFile.close();
    outFile.close();

    return 0;
}