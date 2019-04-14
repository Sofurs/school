#include <fstream>
#include <iostream>
#include <string>

#include "data.hpp"

typedef struct {
    // total
    unsigned int totalNum = 0;
    unsigned int fromAbroad = 0;

    // Slovakia only
    unsigned int mobileNum = 0;
    unsigned int lineNum = 0;

    // Zilina only
    unsigned int lineNumZa = 0;
} TelNums;

int main() {
    TelNums telNums;
    std::fstream telNumFile;
    std::string buffer;

    telNumFile.open("telNum.txt", std::ios_base::in);

    if (telNumFile.is_open()) {
        while (!telNumFile.eof()) {
            getline(telNumFile, buffer);

            if (buffer.length() == MNUMLEN) {
                if (!buffer.compare(0, 4, MDIALCODESVK)) {
                    telNums.mobileNum++;
                } else {
                    telNums.fromAbroad++;
                }
            } else if (buffer.length() == LNUMLEN) {
                if (!comp3(LDIALCODEZA)) {
                    telNums.lineNum++;
                    telNums.lineNumZa++;
                } else if (!comp2(LDIALCODEBA) || !comp3(LDIALCODEDS) || !comp3(LDIALCODETR) || !comp3(LDIALCODETT) || !comp3(LDIALCODESC) || !comp3(LDIALCODENZ) || !comp3(LDIALCODELV) || !comp3(LDIALCODENI) || !comp3(LDIALCODETP) || !comp3(LDIALCODEPB) || !comp3(LDIALCODEMT) || !comp3(LDIALCODELM) || !comp3(LDIALCODEZV) || !comp3(LDIALCODEPR) || !comp3(LDIALCODELC) || !comp3(LDIALCODEBB) || !comp3(LDIALCODEPS) || !comp3(LDIALCODEPP) || !comp3(LDIALCODESN) || !comp3(LDIALCODEBR) || !comp3(LDIALCODEKK) || !comp3(LDIALCODEMI) || !comp3(LDIALCODEHM) || !comp3(LDIALCODERO)) {
                    telNums.lineNum++;
                } else {
                    telNums.fromAbroad++;
                }
            } else {
                telNums.fromAbroad++;
            }
            telNums.totalNum++;
        }
    }

    unsigned int percentageSvk = ((double)(telNums.mobileNum + telNums.lineNum) / telNums.totalNum) * 100;

    std::cout << "Slovakia: " << percentageSvk << "%, abroad: " << 100 - percentageSvk << "%\n";
    std::cout << "Mobile: " << telNums.mobileNum << ", line: " << telNums.lineNum << '\n';
    std::cout << "Line ZA: " << telNums.lineNumZa << '\n';

    return 0;
}