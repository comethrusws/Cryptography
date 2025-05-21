#include <stdio.h>

void extended_gcd(int m, int b) 
{
    int A1 = 1, A2 = 0, A3 = m;
    int B1 = 0, B2 = 1, B3 = b;
    int Q, T1, T2, T3;
    int step = 0;
    
    printf("Step\t\tQ\tA1\tA2\tA3\tB1\tB2\tB3\n");
    printf("-------------------------------------------------------------\n");
    printf("%d\t\t-\t%d\t%d\t%d\t%d\t%d\t%d\n", step++, A1, A2, A3, B1, B2, B3);
    
    while (B3 != 0) 
    {
        Q = A3 / B3;  
        T1 = A1 - Q * B1;
        T2 = A2 - Q * B2;
        T3 = A3 - Q * B3;
        A1 = B1;
        A2 = B2;
        A3 = B3;
        B1 = T1;
        B2 = T2;
        B3 = T3;
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", step++, Q, A1, A2, A3, B1, B2, B3);
    }
    printf("-------------------------------------------------------------\n");
    
    printf("GCD(%d, %d) = %d\n", m, b, A3);
    
    if (A3 == 1) 
    {
        while (A2 < 0) {
            A2 += m;
        }
        A2 = A2 % m;
        
        printf("The modular inverse of %d modulo %d is %d\n", b, m, A2);
    } 
    else 
    {
        printf("No modular inverse exists for %d modulo %d because GCD is not 1\n", b, m);
    }
}

int main() 
{
    int m, b;
    printf("Enter the value of m: ");
    scanf("%d", &m);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    
    if (m <= 0) {
        printf("Error: m must be a positive integer\n");
        return 1;
    }
    
    extended_gcd(m, b);
    return 0;
}