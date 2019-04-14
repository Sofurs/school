#include <iostream>
#include <string>

#define SAMPLEISBN "ISBN "
#define SAMPLEEAN1 "978"
#define SAMPLEEAN2 "979"

enum Type { UNDEFINED,
            DEFINED10,
            DEFINED13 };

typedef struct {
    std::string isbnStr;
    Type type;
} ISBN;

void validate(ISBN& node) {
    int length = node.isbnStr.length();

    if (node.isbnStr.compare(0, 5, SAMPLEISBN)) {
        node.type = UNDEFINED;
        return;
    }

    if (length == 15) {
        int sum = 0;
        int multiplier = length - 5;

        for (int i = 0; i < length - 5; i++) {
            char temp = node.isbnStr[i + 5];

            if (temp != 'X') {
                sum += (temp - '0') * multiplier--;
            } else {
                sum += 10 * multiplier--;
            }
        }

        if (!(sum % 11)) {
            node.type = DEFINED10;
        } else {
            node.type = UNDEFINED;
        }

    } else if (length == 18) {
        if (node.isbnStr.compare(5, 3, SAMPLEEAN1) && node.isbnStr.compare(5, 3, SAMPLEEAN2)) {
            std::cout << node.isbnStr << '\n';
            node.type = UNDEFINED;
            return;
        }

        int sum = 0;

        for (int i = 0; i < length - 5; i++) {
            char temp = node.isbnStr[i + 5];

            if (!(i % 2)) {
                sum += temp - '0';
            } else {
                sum += (temp - '0') * 3;
            }
        }

        if (!(sum % 10)) {
            node.type = DEFINED13;
        } else {
            node.type = UNDEFINED;
        }

    } else {
        node.type = UNDEFINED;
        return;
    }
}

int main() {
    ISBN isbn;
    getline(std::cin, isbn.isbnStr);

    validate(isbn);

    std::cout << ((isbn.type == 1) ? "ISBN10" : (isbn.type == 2) ? "ISBN13" : "UNDEFINED")  << '\n';

    return 0;
}
