//Write a program to implement Extended Euclidean Algorithm.
#include <stdio.h>
#include <math.h>
void extended_gcd(int m, int b) 
{
    int A1 = 1, A2 = 0, A3 = m;
    int B1 = 0, B2 = 1, B3 = b;
    int Q, T1, T2, T3;
    printf("Step\t\tA1\tA2\tA3\tB1\tB2\tB3\n");
    printf("-------------------------------------------------------------\n");
    printf("Initial\t\t%d\t%d\t%d\t%d\t%d\t%d\n", A1, A2, A3, B1, B2, B3);
    while (B3 != 0 && B3 != 1) 
    {
        Q = floor((double)A3 / B3);
        T1 = A1 - Q * B1;
        T2 = A2 - Q * B2;
        T3 = A3 - Q * B3;
        A1 = B1;
        A2 = B2;
        A3 = B3;
        B1 = T1;
        B2 = T2;
        B3 = T3;
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n", Q, A1, A2, A3, B1, B2, B3);
    }
    printf("-------------------------------------------------------------\n");
    if (B3 == 0) 
    {
        printf("No inverse exists.\n");
    } 
    else if (B3 == 1) 
    {
        printf("B3 = GCD(%d, %d) = %d\n", m, b, B3);
        printf("B2 = %d is the inverse of %d modulo %d.\n", B2, b, m);
    }
}
int main() 
{
    int m, b;
    printf("Enter the value of m: ");
    scanf("%d", &m);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    extended_gcd(m, b);
    return 0;
}