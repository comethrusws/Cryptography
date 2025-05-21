//Implement Row-Transpose Cipher
#include <stdio.h>
#include <string.h>
void rowTransposeCipher(char* plaintext, int key) 
{
    int length = strlen(plaintext);
    int rows = (length / key) + (length % key != 0);
    char grid[rows][key];
    int k = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < key; j++) 
        {
            if (k < length) 
            {
                grid[i][j] = plaintext[k++];
            } 
            else 
            {
                grid[i][j] = ' '; 
            }
        }
    }
    printf("Grid (row-wise):\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < key; j++) 
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("Ciphertext: ");
    for (int j = 0; j < key; j++) 
    {
        for (int i = 0; i < rows; i++) 
        {
            if (grid[i][j] != ' ') 
            {
                printf("%c", grid[i][j]);
            }
        }
    }
    printf("\n");
}
int main() 
{
    char plaintext[100];
    int key;
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;
    printf("Enter the key (number of columns): ");
    scanf("%d", &key);
    rowTransposeCipher(plaintext, key);
    return 0;
}