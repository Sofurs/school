#include <iostream>
#include <string>

struct Na {
    std::string data;
    std::string compl_data;
    bool is_dna = 0;
    bool is_rna = 0;
    int is_na = 0;

    // dna -> ATCG
    // rna -> UAGC
};

int main() {
    Na na;

    std::cout << "Enter data: ";
    getline(std::cin, na.data);

    for (int i = 0; i < na.data.length(); i++) {
        if (na.is_dna && na.is_rna) {
            std::cout << "Mixed na!";
            exit(1);
        }
        switch (toupper(na.data[i])) {
            case 'A':
                na.is_na++;
                break;
            case 'C':
                na.is_na++;
                break;
            case 'G':
                na.is_na++;
                break;
            case 'T':
                na.is_dna = true;
                break;
            case 'U':
                na.is_rna = true;
                break;
            default:
                std::cerr << "Wrong input character!";
                exit(1);
                break;
        }
    }

    if (na.is_dna && na.is_na) {
        std::cout << "Is Dna!\n";
    } else if (na.is_rna && na.is_na) {
        std::cout << "Is Rna!\n";
    } else {
        std::cout << "Not Dna or Rna!\n";
    }

    for (int i = 0; i < na.data.length(); i++) {
        switch (toupper(na.data[i])) {
            case 'A':
                if (na.is_dna) {
                    na.compl_data.push_back('U');
                } else if (na.is_rna) {
                    na.compl_data.push_back('T');
                }
                break;
            case 'C':
                na.compl_data.push_back('G');

                break;
            case 'G':
                na.compl_data.push_back('C');
                break;
            case 'T':
                na.compl_data.push_back('A');
                break;
            case 'U':
                na.compl_data.push_back('A');
                break;
        }
    }
    std::cout << "Compl_data: " << na.compl_data << '\n';
}