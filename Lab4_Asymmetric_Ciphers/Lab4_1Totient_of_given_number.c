//Find the totient of the given number.
#include <stdio.h>
int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int totient(int n) 
{
    int result = 1;
    for (int i = 2; i < n; i++) 
    {
        if (gcd(i, n) == 1)
            result++;
    }
    return result;
}
int main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Totient of %d is %d\n", n, totient(n));
    return 0;
}