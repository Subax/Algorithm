#define _CRT_SECURE_NO_WARNIGNS
#include <stdio.h>

int main()
{
    int T, a, b, temp;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &a, &b);
        temp = a;
        b--; // 하나 뺀 값으로 해야 b = 2일때 한 번 반복해서 제곱이 됨
        while (b--)
        {
            temp = temp * a % 10; // pow
        }

        if (temp % 10 == 0) // 10th computer
        {
            printf("10\n");
        }
        else
        {
            printf("%d\n", temp % 10);
        }
    }
    return 0;
}