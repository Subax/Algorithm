#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int go(int N, int *p, int *mem)
{
    int max = 0, temp;
    if (N == 1)
    {
        return p[0];
    }
    if (mem[N] > 0)
    {
        return mem[N];
    }

    for (int i = 1; i <= N; i++)
    {
        temp = p[i - 1] + go(N - i, p, mem);
        if (temp > max)
        {
            max = temp;
        }
    }
    mem[N] = max;
    return mem[N];
}

int main()
{
    int N;
    scanf("%d", &N);

    int *p = (int *)malloc(sizeof(int) * N);
    int *mem = (int *)calloc(N + 1, sizeof(int));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &p[i]);
    }

    int result = go(N, p, mem);
    printf("%d\n", result);

    free(p);
    free(mem);
    return 0;
}