#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000009

long go(int n, int memV, long mem[100000][4]);
int main()
{
    int T;
    scanf("%d", &T);

    int *n = (int *)malloc(sizeof(int) * T);
    long mem[100000][4] = {
        0,
    }; // mem[i][1] = n == i이고 memV == 1일때의 결과!!!!!!, mem[i][0]에는 맨 처음 go 호출일 때 사용(memV == 0), 나머지는 중간 연산때 memorization에 사용

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n[i]);
    }

    for (int i = 0; i < T; i++)
    {
        printf("%ld\n", go(n[i], 0, mem));
    }
    free(n);
    return 0;
}
long go(int n, int memV, long mem[100000][4])
{
    long t1 = 0, t2 = 0, t3 = 0;

    if (n == 0)
    {
        return 1;
    }

    if (mem[n - 1][memV] > 0) // Memorization
    {
        return mem[n - 1][memV];
    }

    if (memV != 1)
    {
        t1 = go(n - 1, 1, mem) % MOD;
    }
    if (memV != 2 && n > 1)
    {
        t2 = go(n - 2, 2, mem) % MOD;
    }
    if (memV != 3 && n > 2)
    {
        t3 = go(n - 3, 3, mem) % MOD;
    }

    mem[n - 1][memV] = (t1 + t2 + t3) % MOD;

    return mem[n - 1][memV];
}

// 이전의 go()에서 어떤 수를 사용했는지 저장하는 배열이 있으면 좋겠다
// *****절대로 음수가 나올 수 없는데 음수가 나온다? => overflow 검사하기*****