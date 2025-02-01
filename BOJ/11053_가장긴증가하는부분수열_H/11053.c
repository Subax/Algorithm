#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int go(int N, int *arr, int *mem);

int main()
{
    int N, result = 0;
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int) * N); // 0 to N-1
    int *mem = (int *)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        go(i, arr, mem);
        if (mem[i - 1] > result)
        {
            result = mem[i - 1];
        }
    }

    printf("%d\n", result);

    free(arr);
    free(mem);
    return 0;
}

// N번째 원소를 마지막으로 하는 부분 수열의 길이 반환
int go(int N, int *arr, int *mem)
{
    if (N == 1)
    {
        mem[0] = 1;
        return mem[0]; // Base case: 첫 번째 원소만 있는 부분수열의 길이 = 1
    }

    if (mem[N - 1] > 0)
    {
        return mem[N - 1]; // 이미 계산된 값이 있으면 반환
    }

    int max_length = 1; // arr[N-1]만 포함하는 경우 길이
    for (int i = N - 2; i >= 0; i--)
    {
        if (arr[i] < arr[N - 1])
        {                                   // arr[i]가 arr[N-1]보다 작으면
            int temp = go(i + 1, arr, mem); // i+1번째 원소를 끝으로 하는 부분수열 길이 계산
            if (temp + 1 > max_length)
            {
                max_length = temp + 1; // 최댓값 갱신
            }
        }
    }

    mem[N - 1] = max_length; // 메모이제이션
    return mem[N - 1];
}