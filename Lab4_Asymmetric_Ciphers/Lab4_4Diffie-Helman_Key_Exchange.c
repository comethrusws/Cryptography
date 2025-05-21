//Implement Diffie-Helman Key Exchange.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int power(int base, int exp, int mod) 
{
    int result = 1;
    base = base % mod;
    while (exp > 0) 
    {
        if (exp % 2 == 1) 
        {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}
int main() 
{
    int p, g, a, b;
    printf("Enter a prime number (p): ");
    scanf("%d", &p);
    printf("Enter a primitive root modulo p (g): ");
    scanf("%d", &g);
    printf("Enter Alice's private key (a): ");
    scanf("%d", &a);
    printf("Enter Bob's private key (b): ");
    scanf("%d", &b);
    printf("\nInitial values:\n");
    printf("Prime number (p): %d\n", p);
    printf("Primitive root modulo p (g): %d\n", g);
    printf("Alice's private key (a): %d\n", a);
    printf("Bob's private key (b): %d\n", b);
    int A = power(g, a, p);
    int B = power(g, b, p);
    printf("\nComputed public keys:\n");
    printf("Alice's public key (A): %d\n", A);
    printf("Bob's public key (B): %d\n", B);
    printf("\nExchanging public keys...\n");
    int s_a = power(B, a, p);
    int s_b = power(A, b, p);
    printf("\nComputed shared secret keys:\n");
    printf("Alice's shared secret key (s_a): %d\n", s_a);
    printf("Bob's shared secret key (s_b): %d\n", s_b);
    if (s_a == s_b) 
    {
        printf("\nThe shared secret keys are equal. Key exchange successful!\n");
    } 
    else 
    {
        printf("\nThe shared secret keys are not equal. Key exchange failed.\n");
    }
    return 0;
}