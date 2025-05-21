//Write a program to verify if the given two numbers are relatively prime or not.
#include <stdio.h>
int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int areRelativelyPrime(int a, int b) 
{
    return gcd(a, b) == 1;
}
int main() 
{
    int a, b;
    printf("Enter two integers: ");
    scanf("%d", &a);
    scanf("%d", &b);
    if (areRelativelyPrime(a, b))
        printf("%d and %d are relatively prime.\n", a, b);
    else
        printf("%d and %d are not relatively prime.\n", a, b);
    return 0;
}