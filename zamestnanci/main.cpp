#include <fstream>
#include <iostream>
#include <string>

typedef struct {
    std::string name;
    std::string surname;
} Person;

typedef struct {
    unsigned int name = 0;
    std::string nameS;
    unsigned int surname = 0;
    std::string surnameS;
} Max;

int main() {
    Person people[1000];
    Max pplMax;

    std::fstream myFile;
    std::string buffer;
    unsigned int lines;
    myFile.open("mena_zamestnancov.txt", std::ios_base::in);

    if (myFile.is_open()) {
        while (!myFile.eof()) {
            getline(myFile, buffer);
            lines++;
        }
    }

    myFile.close();
    myFile.open("mena_zamestnancov.txt", std::ios_base::in);

    if (myFile.is_open()) {
        for (int i = 0; i < lines / 2; i++) {
            getline(myFile, people[i].surname);
            if (pplMax.surname < people[i].surname.length()) {
                pplMax.surname = people[i].surname.length();
                pplMax.surnameS = people[i].surname;
            }
        }
        for (int i = 0; i < lines / 2; i++) {
            getline(myFile, people[i].name);
            if (pplMax.name < people[i].name.length()) {
                pplMax.name = people[i].name.length();
                pplMax.nameS = people[i].name;
            }
        }
    }

    myFile.close();

    std::fstream outFile;
    outFile.open("vystup.txt", std::ios_base::out | std::ios_base::trunc);

    if (outFile.is_open()) {
        for (int i = 0; i < lines / 2; i++) {
            outFile << people[i].name + " " + people[i].surname + '\n';
        }
    }

    std::cout << "Num: " << lines / 2 << '\n';
    std::cout << "Length: " << pplMax.nameS << " => " << pplMax.name << '\n';
    std::cout << '\t' << pplMax.surnameS << " => " << pplMax.surname << '\n';

    outFile.close();

    return 0;
}
