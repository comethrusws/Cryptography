//WAP to implement Hill Cipher.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 2
int letterToNum(char letter) 
{
    return toupper(letter) - 'A';
}
char numToLetter(int num) 
{
    return num + 'A';
}
int determinant(int matrix[SIZE][SIZE]) 
{
    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % 26;
}
int modInverse(int a, int m) 
{
    for (int x = 1; x < m; x++) 
    {
        if ((a * x) % m == 1) 
        {
            return x;
        }
    }
    return -1;
}
int inverseMatrix(int matrix[SIZE][SIZE], int inverse[SIZE][SIZE]) 
{
    int det = determinant(matrix);
    int detInv = modInverse(det, 26);
    if (detInv == -1) 
    {
        return 0;
    }
    inverse[0][0] = (matrix[1][1] * detInv) % 26;
    inverse[0][1] = (-matrix[0][1] * detInv) % 26;
    inverse[1][0] = (-matrix[1][0] * detInv) % 26;
    inverse[1][1] = (matrix[0][0] * detInv) % 26;
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            if (inverse[i][j] < 0) 
            {
                inverse[i][j] += 26;
            }
        }
    }
    return 1;
}
void encrypt(char *message, int key[SIZE][SIZE], char *cipherText) 
{
    int len = strlen(message);
    int num[SIZE][1], result[SIZE][1];
    if (len % SIZE != 0) 
    {
        message[len] = 'X';
        len++;
    }
    for (int i = 0; i < len; i += SIZE) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            num[j][0] = letterToNum(message[i + j]);
        }
        for (int r = 0; r < SIZE; r++) 
        {
            result[r][0] = 0;
            for (int c = 0; c < SIZE; c++) 
            {
                result[r][0] = (result[r][0] + key[r][c] * num[c][0]) % 26;
            }
        }
        for (int r = 0; r < SIZE; r++) 
        {
            cipherText[i + r] = numToLetter(result[r][0]);
        }
    }
    cipherText[len] = '\0';
}
void decrypt(char *cipherText, int key[SIZE][SIZE], char *plainText) 
{
    int len = strlen(cipherText);
    int inverseKey[SIZE][SIZE];
    if (!inverseMatrix(key, inverseKey)) 
    {
        printf("The key matrix has no inverse. Decryption is not possible.\n");
        return;
    }
    int num[SIZE][1], result[SIZE][1];
    for (int i = 0; i < len; i += SIZE) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            num[j][0] = letterToNum(cipherText[i + j]);
        }
        for (int r = 0; r < SIZE; r++) 
        {
            result[r][0] = 0;
            for (int c = 0; c < SIZE; c++) 
            {
                result[r][0] = (result[r][0] + inverseKey[r][c] * num[c][0]) % 26;
            }
        }
        for (int r = 0; r < SIZE; r++) 
        {
            plainText[i + r] = numToLetter(result[r][0]);
        }
    }
    plainText[len] = '\0';
}
int main() 
{
    char message[100], cipherText[100], decryptedText[100];
    int key[SIZE][SIZE];
    printf("Enter the 2x2 key matrix (4 integers):\n");
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            scanf("%d", &key[i][j]);
        }
    }
    printf("Enter the message (only uppercase letters): ");
    getchar();
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    encrypt(message, key, cipherText);
    printf("Encrypted message: %s\n", cipherText);
    decrypt(cipherText, key, decryptedText);
    printf("Decrypted message: %s\n", decryptedText);
    return 0;
}