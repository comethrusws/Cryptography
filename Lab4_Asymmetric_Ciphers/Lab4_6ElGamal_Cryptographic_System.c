//Implement ElGamal Cryptographic System.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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
int rand_range(int min, int max) 
{
    return min + rand() % (max - min + 1);
}
int main() 
{
    int p = 23;
    int g = 5;
    int x = rand_range(1, p - 2);
    int y = power(g, x, p);
    int m = 15;
    int k = rand_range(1, p - 2);
    int c1 = power(g, k, p);
    int c2 = (m * power(y, k, p)) % p;
    int s = power(c1, x, p);
    int m_decrypted = (c2 * power(s, p - 2, p)) % p;
    printf("Public parameters: p = %d, g = %d\n", p, g);
    printf("Private key: x = %d\n", x);
    printf("Public key: y = %d\n", y);
    printf("Original message: %d\n", m);
    printf("Ciphertext: (c1 = %d, c2 = %d)\n", c1, c2);
    printf("Decrypted message: %d\n", m_decrypted);
    if (m == m_decrypted) 
    {
        printf("The message was successfully decrypted. Encryption and decryption are successful!\n");
    } 
    else 
    {
        printf("The message was not successfully decrypted. Encryption or decryption failed.\n");
    }
    return 0;
}