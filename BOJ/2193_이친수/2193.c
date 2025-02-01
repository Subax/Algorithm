#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long go(int N, int memV, long long mem[91][2]);
int main()
{
    int N;
    scanf("%d", &N);
    long long mem[91][2] = {0};
    long long result = go(N, -1, mem);
    printf("%lld\n", result);
    return 0;
}

long long go(int N, int memV, long long mem[91][2])
{
    if (N == 0) // It means success case
    {
        return 1;
    }
    if (mem[N][memV] > 0)
    {
        return mem[N][memV];
    }

    if (memV == -1) // If it is the first case of go()
    {
        mem[N][0] = go(N - 1, 1, mem); // The first digit of pinary number is 1
        return mem[N][0];
    }
    else if (memV == 0)
    {
        mem[N][memV] = go(N - 1, 0, mem) + go(N - 1, 1, mem);
    }
    else if (memV == 1)
    {
        mem[N][memV] = go(N - 1, 0, mem);
    }

    return mem[N][memV];
}

/*
MEMO
1) 첫 번째 자리는 무조건 1 -> 0또는 1로 시작하는 (N-1)자리의 이친수를 구하는 경우가 됨
2) 근데 알고보니 이거 그냥 fibonacci pattern이여서 fib()으로 풀면 된다는...
*/