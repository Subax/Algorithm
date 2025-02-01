#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int go(int N, int *mem);
int main()
{
    int N;
    scanf("%d", &N);

    int *mem = (int *)calloc(N, sizeof(int));

    int result = go(N, mem);
    printf("%d\n", result);

    return 0;
}

int go(int N, int *mem)
{
    int res3, res5;
    if (N < 3)
    {
        return -1;
    }
    else if (N == 3 || N == 5)
    {
        return 1;
    }

    if (mem[N - 1] > 0 || mem[N - 1] == -1) // Memorization
    {
        return mem[N - 1];
    }

    res3 = go(N - 3, mem);
    if (res3 != -1)
    {
        mem[N - 4] = res3;
    }

    res5 = go(N - 5, mem);
    if (res5 != -1)
    {
        mem[N - 6] = res5;
    }

    if (res3 == -1 && res5 == -1)
    {
        mem[N - 1] = -1;
    }

    if ((res3 > res5 || res3 == -1) && res5 != -1)
    {
        mem[N - 1] = 1 + res5;
    }
    else if (res3 != -1)
    {
        mem[N - 1] = 1 + res3;
    }

    return mem[N - 1];
}