#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int go(int N, int *arr, int *mem, int *prev);

int main()
{
    int N, result = 0, endIndex = -1;
    scanf("%d", &N);

    int *arr = (int *)malloc(sizeof(int) * N);
    int *mem = (int *)calloc(N, sizeof(int));   // dp 배열
    int *prev = (int *)malloc(sizeof(int) * N); // 최장 증가 부분수열의 경로 추적 배열

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        prev[i] = -1; // 이전 인덱스를 초기화
    }

    // dp 계산 및 최장 길이 찾기
    for (int i = 1; i <= N; i++)
    {
        go(i, arr, mem, prev);
        if (mem[i - 1] > result)
        {
            result = mem[i - 1];
            endIndex = i - 1; // 최장 길이의 마지막 원소 인덱스
        }
    }

    printf("%d\n", result);

    // 최장 증가 부분수열 경로 역추적
    int *sequence = (int *)malloc(sizeof(int) * result);
    int len = 0;
    while (endIndex != -1)
    {
        sequence[len++] = arr[endIndex];
        endIndex = prev[endIndex];
    }

    // 역순으로 출력
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%d ", sequence[i]);
    }
    printf("\n");

    free(arr);
    free(mem);
    free(prev);
    free(sequence);

    return 0;
}

// N번째 원소를 마지막으로 하는 부분 증가 수열의 길이 반환
int go(int N, int *arr, int *mem, int *prev)
{
    if (N == 1)
    {
        mem[0] = 1;
        return mem[0];
    }

    if (mem[N - 1] > 0)
    {
        return mem[N - 1]; // 이미 계산된 경우
    }

    int max_length = 1;
    for (int i = N - 2; i >= 0; i--)
    {
        if (arr[i] < arr[N - 1])
        {
            int temp = go(i + 1, arr, mem, prev);
            if (temp + 1 > max_length)
            {
                max_length = temp + 1;
                prev[N - 1] = i; // 이전 인덱스 저장
            }
        }
    }

    mem[N - 1] = max_length;
    return mem[N - 1];
}