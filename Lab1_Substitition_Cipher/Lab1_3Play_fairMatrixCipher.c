//WAP to implement Play-fair matrix Cipher.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void sanitizeText(char* text) 
{
    int i = 0, j = 0;
    while (text[i]) 
    {
        if (isalpha(text[i])) 
        {
            text[j++] = toupper(text[i]);
        }
        i++;
    }
    text[j] = '\0';
}
void createMatrix(char* key, char matrix[SIZE][SIZE]) 
{
    int i, j, k = 0;
    int keyLen = strlen(key);
    int used[26] = {0};
    for (i = 0; i < keyLen; i++) 
    {
        key[i] = toupper(key[i]);
        if (key[i] == 'J') key[i] = 'I';
        if (!used[key[i] - 'A']) 
        {
            used[key[i] - 'A'] = 1;
            matrix[k / SIZE][k % SIZE] = key[i];
            k++;
        }
    }
    for (i = 0; i < 26; i++) 
    {
        if (!used[i] && (i + 'A' != 'J')) 
        {
            matrix[k / SIZE][k % SIZE] = i + 'A';
            k++;
        }
    }
}
void findPosition(char letter, char matrix[SIZE][SIZE], int* row, int* col) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            if (matrix[i][j] == letter) 
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void prepareText(char* text, char* preparedText) 
{
    int len = strlen(text);
    int j = 0;
    for (int i = 0; i < len; i++) 
    {
        if (i < len - 1 && text[i] == text[i + 1]) 
        {
            preparedText[j++] = text[i];
            preparedText[j++] = 'X';
            i++;
        } 
        else 
        {
            preparedText[j++] = text[i];
        }
    }
    if (j % 2 != 0) 
    {
        preparedText[j++] = 'X';
    }
    preparedText[j] = '\0';
}
void encrypt(char* message, char* key, char matrix[SIZE][SIZE], char* cipherText) 
{
    int len = strlen(message);
    char preparedText[100];
    prepareText(message, preparedText);
    int i = 0;
    int row1, col1, row2, col2;
    while (preparedText[i] != '\0') 
    {
        findPosition(preparedText[i], matrix, &row1, &col1);
        findPosition(preparedText[i + 1], matrix, &row2, &col2);
        if (row1 == row2) 
        {
            cipherText[i] = matrix[row1][(col1 + 1) % SIZE];
            cipherText[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        }
        else if (col1 == col2) 
        {
            cipherText[i] = matrix[(row1 + 1) % SIZE][col1];
            cipherText[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        }
        else 
        {
            cipherText[i] = matrix[row1][col2];
            cipherText[i + 1] = matrix[row2][col1];
        }
        i += 2;
    }
    cipherText[i] = '\0';
}
void decrypt(char* cipherText, char* key, char matrix[SIZE][SIZE], char* plainText) 
{
    int len = strlen(cipherText);
    int i = 0;
    int row1, col1, row2, col2;
    while (cipherText[i] != '\0') 
    {
        findPosition(cipherText[i], matrix, &row1, &col1);
        findPosition(cipherText[i + 1], matrix, &row2, &col2);
        if (row1 == row2) 
        {
            plainText[i] = matrix[row1][(col1 - 1 + SIZE) % SIZE];
            plainText[i + 1] = matrix[row2][(col2 - 1 + SIZE) % SIZE];
        }
        else if (col1 == col2) 
        {
            plainText[i] = matrix[(row1 - 1 + SIZE) % SIZE][col1];
            plainText[i + 1] = matrix[(row2 - 1 + SIZE) % SIZE][col2];
        }
        else 
        {
            plainText[i] = matrix[row1][col2];
            plainText[i + 1] = matrix[row2][col1];
        }
        i += 2;
    }
    plainText[i] = '\0';
}
int main() 
{
    char message[100], key[50];
    char matrix[SIZE][SIZE];
    char cipherText[100], decryptedText[100];
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    sanitizeText(key);
    sanitizeText(message);
    createMatrix(key, matrix);
    encrypt(message, key, matrix, cipherText);
    printf("Encrypted message: %s\n", cipherText);
    decrypt(cipherText, key, matrix, decryptedText);
    printf("Decrypted message: %s\n", decryptedText);
    return 0;
}