#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char* sentence;
    size_t size = 100;

    sentence = (char*)malloc(size * sizeof(char));

    getline(&sentence, &size, stdin);

    char* token;

    token = strtok(sentence, " ");

    char words[100][100];
    unsigned int count = 0;
    unsigned int maxLength = 0;

    while (token != NULL) {
        strcpy(words[count], token);
        if (strlen(words[count]) - 1 > maxLength) {
            maxLength = strlen(words[count]) - 1;
        }
        count++;
        token = strtok(NULL, " ");
    }

    words[count - 1][maxLength] = '\0';
    unsigned int margin = 2;
    if (margin % 2) {
        margin++;
    }

    for (int i = 0; i < maxLength + margin + 2; i++) {
        printf("*");
    }
    printf("\n");

    for (int i = 0; i < count; i++) {
        printf("*");
        for (int j = 0; j < margin / 2; j++) {
            printf(" ");
        }
        printf("%s", words[i]);
        for (int k = 0; k < margin / 2 + maxLength - strlen(words[i]); k++) {
            printf(" ");
        }
        printf("*\n");
    }

    for (int i = 0; i < maxLength + margin + 2; i++) {
        printf("*");
    }
    printf("\n");

    return 0;
}