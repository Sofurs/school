#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

#include "stack.hpp"

int main() {
    std::fstream myFile;
    Stack lifo;
    int numberRack = 0;
    myFile.open("file.txt", std::ios::in);

    while (!myFile.eof()) {
        std::string line;
        getline(myFile, line);
        std::clog << "Line: " << line << '\n';
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                numberRack *= 10;
                numberRack += line[i] - '0';
                if (line[i - 1] == '-') {
                    numberRack *= -1;
                }
                if (line[i + 1] != ' ') {
                    continue;
                } else {
                    lifo.push(numberRack);
                }
            } else if (line[i] == ' ') {
                numberRack = 0;
            } else {
                numberRack = 0;
                if (line[i] == '+') {
                    int a = lifo.pop();
                    int b = lifo.pop();
                    lifo.push(a + b);

                } else if (line[i] == '-') {
                    if(isdigit(line[i + 1])) {
                        continue;
                    }
                    int a = lifo.pop();
                    int b = lifo.pop();
                    lifo.push(b - a);

                } else if (line[i] == '*') {
                    int a = lifo.pop();
                    int b = lifo.pop();
                    lifo.push(a * b);

                } else {
                    std::cerr << "Unknown sign -> " << line[i] << '\n';
                }
            }
        }
    }
    std::cout << "Result: " << lifo.peek() << '\n';
}