#include <stdio.h>
int gcd(int a, int b);
int main()
{
    int GCD, LCM;
    int a, b;

    scanf("%d %d", &a, &b);
    GCD = gcd(a, b);
    LCM = GCD * (a / GCD) * (b / GCD);

    printf("%d\n%d\n", GCD, LCM);
    return 0;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else if (b == 1) // There is no GCD
    {
        return 1;
    }

    return gcd(b, a % b);
}