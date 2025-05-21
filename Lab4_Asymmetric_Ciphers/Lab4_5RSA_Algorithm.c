//Implement RSA Algorithm.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
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
int modInverse(int e, int phi) 
{
    for (int x = 1; x < phi; x++) 
    {
        if ((e * x) % phi == 0) 
        {
            return x;
        }
    }
    return -1;
}
int main() 
{
    int p = 61;  
    int q = 53;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 17;
    while (gcd(e, phi) != 1) 
    {
        e++;
    }
    int d = modInverse(e, phi);
    printf("Public key: (e = %d, n = %d)\n", e, n);
    printf("Private key: (d = %d, n = %d)\n", d, n);
    int message = 42;
    int encrypted_message = power(message, e, n);
    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encrypted_message);
    int decrypted_message = power(encrypted_message, d, n);
    printf("Decrypted message: %d\n", decrypted_message);
    return 0;
}