#include <fstream>
#include <iostream>
#include <string>
#include <vector>

typedef struct {
    unsigned int num;
    unsigned int time;
} Sportsman;

unsigned int num = 0;

void addSportsman(Sportsman* ptr) {
    unsigned int val;
    unsigned int secTime;
    unsigned int maxIndex;

    std::cout << "Enter num: ";
    std::cin >> val;

    std::cout << "Enter time: ";
    std::cin >> secTime;

    for (int i = 0; i <= num; i++) {
        if (ptr[i].time < secTime) {
            maxIndex = i;
            break;
        }
    }

    if (num) {
        for (int i = num; i > maxIndex; i--) {
            ptr[i].num = ptr[i - 1].num;
            ptr[i].time = ptr[i - 1].time;
        }

        ptr[maxIndex].num = val;
        ptr[maxIndex].time = secTime;
    } else {
        ptr[0].num = val;
        ptr[0].time = secTime;
    }

    num++;
}

void deleteSportsman(Sportsman* ptr) {
    unsigned int val;
    unsigned int pos;

    std::cout << "Enter num: ";
    std::cin >> val;

    for (int i = 0; i < num; i++) {
        if (ptr[i].num == val) {
            pos = i;
            break;
        }
    }

    if (pos == num - 1) {
        num--;
    } else {
        for (int i = pos; i < num - 1; i++) {
            ptr[i].num = ptr[i + 1].num;
            ptr[i].time = ptr[i + 1].time;
        }
        num--;
    }
}

void showResults(Sportsman* ptr) {
    int pos;
    for (int i = 0; i < num; i++) {
        int min = ptr[i].time / 6000;
        int sec = (ptr[i].time % 6000) / 100;
        int ms = (ptr[i].time % 6000) % 100;
        std::cout << i + 1 << " " << ptr[i].num << " " << min << " " << sec << " " << ms << '\n';
    }
}

int main() {
    Sportsman sportsmen[50];

    while (1) {
        unsigned int opt;
        // std::cout << "\033[2J";
        // std::cout << "\033[1;1H";
        std::cout << "1: addSportsman()\n";
        std::cout << "2: deleteSportsman()\n";
        std::cout << "3: showResult\n";
        std::cout << "Option: ";
        std::cin >> opt;

        switch (opt) {
            case 1:
                addSportsman(sportsmen);
                break;
            case 2:
                deleteSportsman(sportsmen);
                break;
            case 3:
                showResults(sportsmen);
                break;
            default:
                return 0;
                break;
        }
    }

    return 0;
}