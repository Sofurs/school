#include <fstream>
#include <iostream>

int main() {
    std::fstream inFile;
    std::fstream tagFile;
    std::fstream textFile;

    inFile.open("html.txt", std::ios_base::in);
    tagFile.open("tag.txt", std::ios_base::out | std::ios_base::trunc);
    textFile.open("text.txt", std::ios_base::out | std::ios_base::trunc);

    char temp;
    char option;

    while (inFile >> temp) {
        if (temp == '<')
            option = 't';  // tag
        else if (temp == '>') {
            tagFile << temp;
            option = 'c';  // content
            continue;
        }

        if (option == 't')
            tagFile << temp;
        else if (option == 'c')
            textFile << temp;
    }

    inFile.close();
    tagFile.close();
    textFile.close();

    return 0;
}