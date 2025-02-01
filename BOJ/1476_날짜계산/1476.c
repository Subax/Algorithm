#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int year = 1;
    int E, S, M, e = 1, s = 1, m = 1;
    scanf("%d %d %d", &E, &S, &M);

    while (1)
    {
        if (e > 15 && e % 15 == 1) // searching for a number which exceeds proper range
        {
            e = 1;
        }
        if (s > 28 && s % 28 == 1)
        {
            s = 1;
        }
        if (m > 19 && m % 19 == 1)
        {
            m = 1;
        }

        if (E == e && S == s && M == m) // the case which finds the answer
        {
            break;
        }

        e++, s++, m++, year++;
    }

    printf("%d\n", year);
    return 0;
}