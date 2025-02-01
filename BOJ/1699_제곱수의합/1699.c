#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int go(int N, int *mem);
int main()
{
    int N, temp, min = 100000;
    scanf("%d", &N);
    int *mem = (int *)calloc(N, sizeof(int));

    min = go(N, mem);
    printf("%d\n", min);

    return 0;
}

// go(N) == N = N일때 minimum 제곱수 항의 개수
int go(int N, int *mem)
{
    int temp, min = 100000;
    if (N == 0)
    {
        return 0; // success case: 1이 이미 더해져서 호출됐으니 0 더해주면 끝
    }
    if (mem[N - 1] > 0) // 자연수 N을 연산한 결과 Memorization
    {
        return mem[N - 1];
    }

    // 마지막 수에 집중: 최댓값인 항은 어느값부터 시작할 지 확정적으로 알 수 없으나, 제일 작은 마지막 수는 확정적으로 알 수 있음
    for (int i = 1; i * i <= N; i++)
    {
        temp = go(N - i * i, mem) + 1;
        if (temp < min)
        {
            min = temp;
        }
    }
    mem[N - 1] = min;
    return mem[N - 1];
}