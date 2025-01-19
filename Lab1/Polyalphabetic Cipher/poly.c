#include <stdio.h>
#include <string.h>
#include <ctype.h>

void polya(char plaintext[], char key[]) {
    int textLength = strlen(plaintext);
    int keyLength = strlen(key);
    char encryptedText[100];
    int keyIndex = 0;

    for (int i = 0; i < textLength; i++) {
        char currentChar = plaintext[i];

        // check if the character is alphabetic
        if (isalpha(currentChar)) {
            char offset = isupper(currentChar) ? 'A' : 'a'; // check for uppercase or lowercase
            int keyShift = tolower(key[keyIndex % keyLength]) - 'a'; // get shift value from key
            encryptedText[i] = ((currentChar - offset + keyShift) % 26) + offset;
            keyIndex++;
        } else {
            // if not alphabetic, it is what t is
            encryptedText[i] = currentChar;
        }
    }

    encryptedText[textLength] = '\0'; // null-terminate  string
    printf("encrypted text: %s\n", encryptedText);
}

int main() {
    char plaintext[100];
    char key[100];

    printf("enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // newline rem garcha

    printf("enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // newline remove garcha

    polya(plaintext, key);

    return 0;
}
