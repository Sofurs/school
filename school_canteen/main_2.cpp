#include <fstream>
#include <iostream>
#include <map>
#include <string>

typedef struct {
    int id;
    char lunch;
} Menu_system;

typedef struct {
    int val = 0;
    char type;
} Highest;

int main() {
    std::map<int, char> lunch;
    std::map<char, int> count;

    Menu_system menu;
    std::fstream myFile;

    try {
        myFile.open("data/dataset1.txt", std::ios::in);

        if (!myFile.is_open()) {
            throw "File isn't open!";
            exit(1);
        }

        while (!myFile.eof()) {
            myFile >> menu.id >> menu.lunch;
            lunch[menu.id] = menu.lunch;
        }
    }

    catch (const char *err) {
        std::cerr << err << '\n';
    }

    for (auto it = lunch.begin(); it != lunch.end(); it++) {
        count[it->second] = count[it->second] + 1;
    }

    Highest num;
    for (auto it = count.begin(); it != count.end(); it++) {
        if (it->second > num.val) {
            num.val = it->second;
            num.type = it->first;
        }
    }

    for (auto it = count.begin(); it != count.end(); it++) {
        if (it->second < 20 && it->first != num.type) {
            num.val += it->second;
            it->second = 0;
        }
    }

    count[num.type] = num.val;

    for (auto it = count.begin(); it != count.end(); it++) {
        std::cout << it->first << " => " << it->second << '\n';
    }
}