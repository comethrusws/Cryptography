#include <stdio.h>
#include <string.h>
#include <ctype.h>

void makeBigBoy(char text[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (islower(text[i])) {
            text[i] = toupper(text[i]);
        }
    }
}

// hill cipher encryption
void hillCipherEncrypt(char text[], int keyMatrix[2][2]) {
    char encryptedText[100];
    int len = strlen(text);

    // pad with 'X', odd length bhaye
    if (len % 2 != 0) {
        text[len++] = 'X';
        text[len] = '\0';
    }

    // process digraphs
    for (int i = 0; i < len; i += 2) {
        int ch1 = text[i] - 'A';
        int ch2 = text[i + 1] - 'A';

        encryptedText[i] = ((keyMatrix[0][0] * ch1 + keyMatrix[0][1] * ch2) % 26) + 'A';
        encryptedText[i + 1] = ((keyMatrix[1][0] * ch1 + keyMatrix[1][1] * ch2) % 26) + 'A';
    }

    encryptedText[len] = '\0'; // null-terminate
    printf("encrypted text: %s\n", encryptedText);
}

int main() {
    char text[100];
    int keyMatrix[2][2];

    printf("enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // remove newline
    makeBigBoy(text); // make uppercase

    printf("enter 2x2 key matrix (space-separated): ");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &keyMatrix[i][j]);
        }
    }

    hillCipherEncrypt(text, keyMatrix);

    return 0;
}
