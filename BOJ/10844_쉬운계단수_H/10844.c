#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MOD 1000000000

long go(int N, int num, long mem[101][10]);

int main()
{
    int N;
    scanf("%d", &N);

    long mem[101][10] = {0};

    // 초기값 설정 (1자리 숫자일 때 각 숫자로 끝나는 경우의 수는 1개)
    // ex) N=1 일때 1 / 2 / 3 ...일 경우의 수는 각각 1개
    for (int i = 0; i < 10; i++)
    {
        mem[1][i] = 1;
    }

    long result = 0;

    // 1부터 9까지의 숫자로 시작하는 경우의 수를 모두 더함
    for (int i = 1; i < 10; i++)
    {
        result = (result + go(N, i, mem)) % MOD;
    }

    printf("%ld\n", result);

    return 0;
}

// go(N, num, mem): 자리 수가 N이고, 마지막 숫자가 num일 때 계단 수의 개수를 반환
long go(int N, int num, long mem[101][10])
{
    // 이 If문으로 인해 N이 0이하로 내려가지 않음, N=1이 된 순간 이미 성공한 경우의 수인 것
    if (N == 1) // 기저 사례: 1자리 숫자는 이미 초기화되어 있음
    {
        return mem[N][num];
    }

    if (mem[N][num] > 0) // 이미 계산된 값이 있으면 반환
    {
        return mem[N][num];
    }

    long result = 0;

    // 이전 자리에서 num-1로 끝나는 경우
    if (num > 0)
    {
        result += go(N - 1, num - 1, mem);
    }
    // 이전 자리에서 num+1로 끝나는 경우
    if (num < 9)
    {
        result += go(N - 1, num + 1, mem);
    }

    mem[N][num] = result % MOD; // 결과를 저장
    return mem[N][num];
}