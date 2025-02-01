#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int adding(int n, int *mem1);
int main()
{
    int T, n, result;
    int mem[1001] = {0};
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        result = adding(n, mem);
        printf("%d\n", result);
    }
    return 0;
}

int adding(int n, int *mem)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n == 3)
    {
        return 4;
    }

    if (mem[n] > 0)
    {
        return mem[n];
    }

    int t1, t2 = 0, t3 = 0, temp;

    // 1 먼저
    t1 = adding(n - 1, mem);

    // 2 먼저
    t2 = adding(n - 2, mem);

    // 3 먼저
    t3 = adding(n - 3, mem);

    mem[n] = t1 + t2 + t3;
    return mem[n];
}