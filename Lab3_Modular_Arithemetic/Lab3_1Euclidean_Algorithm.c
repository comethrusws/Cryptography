//Write a program to implement Euclidean Algorithm.
#include <stdio.h>
int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main() 
{
    int a, b, result;
    printf("Enter two integers: ");
    scanf("%d", &a);
    scanf("%d", &b);
    if (a < b) 
    {
        int temp = a;
        a = b;
        b = temp;
    }
    result = gcd(a, b);
    printf("The GCD of %d and %d is %d\n", a, b, result);
    return 0;
}