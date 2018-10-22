#include <iostream>
#include <string>
#include <string.h>

int main() {

    std::string line1, line2;

    getline(std::cin, line1, '\n');
    getline(std::cin, line2, '\n');

    int position;

    for(int i = 0; i < line1.length(); i++) {
        if(line1[i] == '*') {
            position = i;
            break;
        }
    }

    std::string firstWord, secondWord;
    for(int i = 0, j = position + 1; i < position || j < line1.length(); i++, j++) {
        if(i < position) 
            firstWord += line1[i];
        if(j < line1.length())
            secondWord += line1[j];
    }

    bool first = strstr(line2.c_str(), firstWord.c_str());
    bool second = strstr(line2.c_str(), secondWord.c_str());

    if(!first && second) {
        std::cout << "NIE" << '\n';
    } else if (first && !second) {
        std::cout << "NIE" << '\n';
    } else {
        std::cout << "ANO" << '\n';
    }

    return 0;
}