#include <stdio.h>
#include <string.h>

void caesar(char text[], int key) {
    int i;
    char ch;
    for (i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        
        // encrypt uppercase
        if (ch >= 'A' && ch <= 'Z') {
            text[i] = (ch - 'A' + key) % 26 + 'A';
        }
        // encrypt lowercase
        else if (ch >= 'a' && ch <= 'z') {
            text[i] = (ch - 'a' + key) % 26 + 'a';
        }
    }
}

int main() {
    char text[100];
    int key;

    printf("Enter a string to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // newline character remove garne

    printf("Enter the key: ");
    scanf("%d", &key);

    caesar(text, key);

    printf("Encrypted text: %s\n", text);

    return 0;
}
