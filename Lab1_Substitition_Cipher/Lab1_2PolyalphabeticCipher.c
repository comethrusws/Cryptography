//WAP to implement Polyalphabetic Cipher.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void encrypt(char* message, char* key, char* cipherText) 
{
    int i = 0;
    int j = 0;
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    for (i = 0; i < messageLength; i++) 
    {
        if (isalpha(message[i])) 
        {
            char offset = isupper(message[i]) ? 'A' : 'a';
            cipherText[i] = (message[i] - offset + (toupper(key[j % keyLength]) - 'A')) % 26 + offset;
            j++;
        } 
        else 
        {
            cipherText[i] = message[i];
        }
    }
    cipherText[i] = '\0';
}
void decrypt(char* cipherText, char* key, char* decryptedText) 
{
    int i = 0;
    int j = 0;
    int cipherTextLength = strlen(cipherText);
    int keyLength = strlen(key);
    for (i = 0; i < cipherTextLength; i++) 
    {
        if (isalpha(cipherText[i])) 
        {
            char offset = isupper(cipherText[i]) ? 'A' : 'a';
            decryptedText[i] = (cipherText[i] - offset - (toupper(key[j % keyLength]) - 'A') + 26) % 26 + offset;
            j++;
        } 
        else 
        {
            decryptedText[i] = cipherText[i];
        }
    }
    decryptedText[i] = '\0';
}
int main() 
{
    char message[100];
    char key[50];
    char cipherText[100];
    char decryptedText[100];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    encrypt(message, key, cipherText);
    printf("Encrypted message: %s\n", cipherText);
    decrypt(cipherText, key, decryptedText);
    printf("Decrypted message: %s\n", decryptedText);   
    return 0;
}