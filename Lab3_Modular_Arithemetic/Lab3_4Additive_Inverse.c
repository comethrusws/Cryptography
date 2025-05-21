//Write a program to find Additive Inverse.
#include <stdio.h>
void display_addition_modulo_table(int n) 
{
    printf("Addition Modulo %d Table:\n", n);
    printf("\t");
    for (int i = 0; i < n; i++) 
    {
        printf("%d\t", i);
    }
    printf("\n");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d|\t", i);
        for (int j = 0; j < n; j++) 
        {
            printf("%d\t", (i + j) % n);
        }
        printf("\n");
    }
}
void display_inverse_table(int n) 
{
    printf("Inverse Table Modulo %d:\n", n);
    printf("\tInverse\n");
    for (int i = 1; i < n; i++) 
    {
        int inverse = -1;
        for (int j = 1; j < n; j++) 
        {
            if ((i * j) % n == 1) 
            {
                inverse = j;
                break;
            }
        }
        printf("-------------------------------\n");
        if (inverse == -1) 
        {
            printf("%d|\tNo Inverse\n", i);
        } 
        else 
        {
            printf("%d|\t%d\n", i, inverse);
        }
    }
}
int find_inverse(int a, int n) 
{
    for (int i = 1; i < n; i++) 
    {
        if ((a * i) % n == 1) 
        {
            return i;
        }
    }
    return -1;
}
int main() 
{
    int n, a;
    printf("Enter the value of n for modulo operation: ");
    scanf("%d", &n);
    display_addition_modulo_table(n);
    printf("\n");
    display_inverse_table(n);
    printf("\nEnter the integer to find its inverse modulo %d: ", n);
    scanf("%d", &a);
    int inverse = find_inverse(a, n);
    if (inverse == -1) 
    {
        printf("No inverse exists for %d modulo %d.\n", a, n);
    } 
    else 
    {
        printf("The inverse of %d modulo %d is %d.\n", a, n, inverse);
    }
    return 0;
}