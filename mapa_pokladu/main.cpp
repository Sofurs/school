#include <map>

#include "fileParser.hpp"

struct values {
    int max_count = 0;
    int max_number;

    int min_count = 10;
    int min_number;
} S_2DArrayFrequency;

void flipEvenOddLines(t_MapBig &arr) {
    for (int i = 0; i < MAX_X * 2; i += 2) {
        for (int j = 0; j < MAX_Y * 2; j++) {
            arr[i][j] ^= arr[i + 1][j];
            arr[i + 1][j] ^= arr[i][j];
            arr[i][j] ^= arr[i + 1][j];
        }
    }
}

void printMap(t_MapBig &arr) {
    for (int i = 0; i < MAX_X * 2; i++) {
        for (int j = 0; j < MAX_Y * 2; j++) {
            if (arr[i][j] == S_2DArrayFrequency.max_number) {
                std::cout << "T"
                          << " ";
            } else if (arr[i][j] == S_2DArrayFrequency.min_number) {
                std::cout << "S"
                          << " ";
            } else {
                std::cout << arr[i][j] << " ";
            }
        }
        std::cout << '\n';
    }

    std::cout << "\nT - town\nS - stash\n";
}

void frequencyOfNumbers(t_MapBig &arr) {
    std::map<int, int> valuesOf2DArray;

    for (int i = 0, count = 0; i < MAX_X * 2; i++) {
        for (int j = 0; j < MAX_Y * 2; j++) {
            int count = valuesOf2DArray[arr[i][j]];
            count++;
            valuesOf2DArray[arr[i][j]] = count;
        }
    }

    for (std::map<int, int>::iterator it = valuesOf2DArray.begin(); it != valuesOf2DArray.end(); it++) {
        if (it->second > S_2DArrayFrequency.max_count) {
            S_2DArrayFrequency.max_count = it->second;
            S_2DArrayFrequency.max_number = it->first;
        }

        if (it->second < S_2DArrayFrequency.min_count) {
            S_2DArrayFrequency.min_count = it->second;
            S_2DArrayFrequency.min_number = it->first;
        }
    }
}

int main() {
    fileParser file1("data/1.txt");
    fileParser file2("data/2.txt");
    fileParser file3("data/3.txt");
    fileParser file4("data/4.txt");

    t_MapBig map;

    file1.copy2DArray(map, 0, 0);
    file2.copy2DArray(map, 0, 3);
    file3.copy2DArray(map, 4, 0);
    file4.copy2DArray(map, 4, 3);

    flipEvenOddLines(map);

    frequencyOfNumbers(map);

    printMap(map);

    return 0;
}
