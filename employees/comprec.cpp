#include "comprec.hpp"

CompRec::CompRec() {
}

CompRec::~CompRec() {
}

void CompRec::getData(std::string& data) {
    empData.clear();
    empData = data + '\n';

    parseString();
    accRecord.push_back(employees);
}

void CompRec::calcHours() {
    for (auto it = accRecord.begin(); it != accRecord.end(); it++) {
        hourWork[it->id] += it->leaving - it->arrival;
    }
}

void CompRec::parseString() {
    unsigned int temp = 0;

    for (int i = 0; i < empData.length(); i++) {
        if (empData[i] == ' ' || empData[i] == '\n') {
            fillStruct(temp);
            temp = 0;
        } else {
            temp *= 10;
            temp += empData[i] - '0';
        }
    }
}

void CompRec::fillStruct(unsigned int num) {
    static int vars = 0;

    switch (vars) {
        case 0:
            employees.id = num;
            break;
        case 1:
            employees.month = num;
            break;
        case 2:
            employees.day = num;
            break;
        case 3:
            employees.arrival = num;
            break;
        case 4:
            employees.leaving = num;
            break;
        default:
            break;
    }

    vars++;
    if (vars > 4) {
        vars = 0;
    }
}

void CompRec::printVec() {
    for (auto it = accRecord.begin(); it != accRecord.end(); it++) {
        std::cout << it->id << " " << it->month << " " << it->day << " " << it->arrival << " " << it->leaving << '\n';
    }
}

void CompRec::printHours() {
    for(auto it = hourWork.begin(); it != hourWork.end(); it++) {
        std::cout << "ID: " << it->first << " => " << it->second;

        if(it->second > 250) {
            std::cout << " overtime\n";
        } else if(it->second < 100) {
            std::cout << " insufficient\n";
        } else {
            std::cout << '\n';
        }
    }
}