#include <stdio.h>
#include <string.h>
#include <ctype.h>

// creates the playfair cipher matrix
void createMatrix(char key[], char matrix[5][5]) {
    int used[26] = {0};
    int row = 0, col = 0;

    used['J' - 'A'] = 1;

    // fill the matrix with key characters
    for (int i = 0; key[i] != '\0'; i++) {
        char letter = toupper(key[i]);
        if (letter >= 'A' && letter <= 'Z' && !used[letter - 'A']) {
            matrix[row][col++] = letter;
            used[letter - 'A'] = 1;
            if (col == 5) {
                row++;
                col = 0;
            }
        }
    }

    // fill remaining matrix with unused letters
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        if (!used[letter - 'A']) {
            matrix[row][col++] = letter;
            if (col == 5) {
                row++;
                col = 0;
            }
        }
    }
}

// finds the position of a letter in the matrix
void findPosition(char matrix[5][5], char letter, int *row, int *col) {
    if (letter == 'J') letter = 'I'; // treat 'I' and 'J' as the same
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (matrix[r][c] == letter) {
                *row = r;
                *col = c;
                return;
            }
        }
    }
}

// encrypts a digraph using the playfair cipher rules
void encryptDigraph(char digraph[2], char matrix[5][5]) {
    int row1, col1, row2, col2;

    findPosition(matrix, digraph[0], &row1, &col1);
    findPosition(matrix, digraph[1], &row2, &col2);

    if (row1 == row2) {
        // same row, shift columns right
        digraph[0] = matrix[row1][(col1 + 1) % 5];
        digraph[1] = matrix[row2][(col2 + 1) % 5];
    } else if (col1 == col2) {
        // same column, shift rows down
        digraph[0] = matrix[(row1 + 1) % 5][col1];
        digraph[1] = matrix[(row2 + 1) % 5][col2];
    } else {
        // rectangle, swap columns
        digraph[0] = matrix[row1][col2];
        digraph[1] = matrix[row2][col1];
    }
}

void playfairEncrypt(char text[], char key[]) {
    char matrix[5][5];
    createMatrix(key, matrix);

    char cleanedText[100], digraph[2];
    int cleanIndex = 0;

    // preprocess text: remove non-alphabetic, replace 'J' with 'I'
    for (int i = 0; text[i] != '\0'; i++) {
        char letter = toupper(text[i]);
        if (isalpha(letter)) {
            if (letter == 'J') letter = 'I';
            cleanedText[cleanIndex++] = letter;
        }
    }
    cleanedText[cleanIndex] = '\0';

    // add filler 'X' to duplicate letters in pairs
    int textLength = strlen(cleanedText);
    char encryptedText[100];
    int encryptedIndex = 0;

    for (int i = 0; i < textLength; i += 2) {
        digraph[0] = cleanedText[i];
        if (i + 1 < textLength && cleanedText[i] != cleanedText[i + 1]) {
            digraph[1] = cleanedText[i + 1];
        } else {
            digraph[1] = 'X'; // add filler
        }

        encryptDigraph(digraph, matrix);
        encryptedText[encryptedIndex++] = digraph[0];
        encryptedText[encryptedIndex++] = digraph[1];
    }
    encryptedText[encryptedIndex] = '\0';

    printf("encrypted text: %s\n", encryptedText);
}

int main() {
    char text[100], key[100];

    printf("enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // remove newline

    printf("enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // remove newline

    playfairEncrypt(text, key);

    return 0;
}
