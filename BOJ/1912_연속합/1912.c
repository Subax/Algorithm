#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long go(int N, int *arr, int *mem);
int main()
{
    int N;
    long long max = -100000000; // possible lowest digit
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int) * N);
    int *mem = (int *)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < N; i++)
    {
        go(i, arr, mem);
        if (mem[i] > max)
        {
            max = mem[i];
        }
    }

    printf("%lld\n", max);

    return 0;
}

// go(N) == N번째 원소를 마지막 원소로 하는 부분수열의 최댓값
long long go(int N, int *arr, int *mem)
{
    long long temp, sum;
    if (N == 0)
    {
        mem[N] = arr[N];
        return mem[N];
    }
    if (mem[N] != 0) // Memorization
    {
        return mem[N];
    }

    temp = go(N - 1, arr, mem);
    if (temp > 0)
    {
        mem[N] = temp + arr[N];
    }
    else
    {
        mem[N] = arr[N];
    }

    return mem[N];
}