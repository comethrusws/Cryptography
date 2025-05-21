//Implement Rail-Fence Cipher
#include <stdio.h>
#include <string.h>
void railFenceCipher(char* plaintext, int rails) 
{
    int length = strlen(plaintext);
    char rail[rails][length]; 
    for (int i = 0; i < rails; i++) 
    {
        for (int j = 0; j < length; j++) 
        {
            rail[i][j] = '\n';
        }
    }
    int row = 0, col = 0;
    int direction = 1;
    for (int i = 0; i < length; i++) 
    {
        rail[row][col++] = plaintext[i];
        if (row == 0) 
        {
            direction = 1;
        } 
        else if (row == rails - 1) 
        {
            direction = -1;
        }
        row += direction;
    }
    printf("Rail setup:\n");
    for (int i = 0; i < rails; i++) 
    {
        for (int j = 0; j < length; j++) 
        {
            if (rail[i][j] != '\n') 
            {
                printf("%c ", rail[i][j]);
            } 
            else 
            {
                printf(". "); 
            }
        }
        printf("\n");
    }
    printf("Ciphertext: ");
    for (int i = 0; i < rails; i++) 
    {
        for (int j = 0; j < length; j++) 
        {
            if (rail[i][j] != '\n') 
            {
                printf("%c", rail[i][j]);
            }
        }
    }
    printf("\n");
}
int main() 
{
    char plaintext[100];
    int rails;
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    railFenceCipher(plaintext, rails);
    return 0;
}