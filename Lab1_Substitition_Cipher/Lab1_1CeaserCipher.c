//WAP to implement Ceaser Cipher.
#include <stdio.h>
#include <string.h>
void encrypt(char* message, int shift) 
{
    for (int i = 0; message[i] != '\0'; i++) 
    {
        if (message[i] >= 'A' && message[i] <= 'Z') 
        {
            message[i] = ((message[i] - 'A' + shift) % 26) + 'A';
        }
        else if (message[i] >= 'a' && message[i] <= 'z') 
        {
            message[i] = ((message[i] - 'a' + shift) % 26) + 'a';
        }
    }
}
void decrypt(char* message, int shift) 
{
    for (int i = 0; message[i] != '\0'; i++) 
    {
        if (message[i] >= 'A' && message[i] <= 'Z') 
        {
            message[i] = ((message[i] - 'A' - shift + 26) % 26) + 'A';
        }
        else if (message[i] >= 'a' && message[i] <= 'z') 
        {
            message[i] = ((message[i] - 'a' - shift + 26) % 26) + 'a';
        }
    }
}
int main() 
{
    char message[100];
    int shift;
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    printf("Enter shift value: ");
    scanf("%d", &shift);
    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);
    decrypt(message, shift);
    printf("Decrypted message: %s\n", message);
    return 0;
}