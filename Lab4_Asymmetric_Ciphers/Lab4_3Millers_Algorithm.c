//Implement Miller’s Algorithm for testing Primality.
#include <stdio.h>
#include <stdlib.h>
long long power_mod(long long base, long long exp, long long mod) 
{
    long long result = 1;
    base = base % mod;
    while (exp > 0) 
    {
        if (exp % 2 == 1) 
            result = (result * base) % mod;
            exp = exp >> 1; 
            base = (base * base) % mod;
    }
    return result;
}
int miller_test(long long d, long long n) 
{
    long long a = 2 + rand() % (n - 4);
    long long x = power_mod(a, d, n);
    if (x == 1 || x == n - 1)
        return 1;
    while (d != n - 1) 
    {
        x = (x * x) % n;
        d *= 2;
        if (x == 1) 
            return 0; 
        if (x == n - 1) 
            return 1;
    }
    return 0;
}
int is_prime(long long n, int k) 
{
    if (n <= 1 || n == 4) 
        return 0;
    if (n <= 3) 
        return 1;
    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (int i = 0; i < k; i++) 
    {
        if (!miller_test(d, n))
                return 0;
    }
    return 1;
}
int main() 
{
    long long num;
    int k = 5;
    printf("Enter a number to check for primality: ");
    scanf("%lld", &num);
    if (is_prime(num, k))
        printf("%lld is a Prime Number.\n", num);
    else
        printf("%lld is NOT a Prime Number.\n", num);
    return 0;
}