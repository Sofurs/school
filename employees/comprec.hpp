#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef struct {
    unsigned int id;
    unsigned int month;
    unsigned int day;
    unsigned int arrival;
    unsigned int leaving;

} Employee;

class CompRec {
   public:
    CompRec();
    ~CompRec();

    void getData(std::string& data);
    void calcHours();

    void printVec();
    void printHours();

   private:
    Employee employees;
    std::vector<Employee> accRecord;
    std::map<unsigned int, unsigned int> hourWork;
    std::string empData;

    void parseString();
    void fillStruct(unsigned int num);
};