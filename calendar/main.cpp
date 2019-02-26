#include <fstream>
#include <iostream>
#include <map>

typedef struct {
    int start_minutes;
    int end_minutes;
} Time;

int main() {
    std::map<int, int> time_map;
    std::fstream myFile;
    Time time;
    myFile.open("data/data.txt", std::ios::in);

    while (!myFile.eof()) {
        int start_hours;
        int end_hours;
        myFile >> start_hours >> time.start_minutes >> end_hours >> time.end_minutes;

        time.start_minutes += start_hours * 60;
        time.end_minutes += end_hours * 60;
        time_map[time.start_minutes] = time.end_minutes;
    }

    for (auto it = time_map.begin(); it != time_map.end(); it++) {
        std::cout << it->first << ", " << it->second << '\n';
        if (it->second > std::next(it, 1)->first) {
            std::cout << "ERROR!\n";
        }
    }
}