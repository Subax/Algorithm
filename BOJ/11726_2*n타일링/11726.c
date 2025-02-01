#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int tiling(int n, int *mem1);
int main()
{
    int n, result;
    int mem[1001] = {0};
    scanf("%d", &n);

    result = tiling(n, mem);
    printf("%d\n", result);
    return 0;
}

int tiling(int n, int *mem)
{
    int temp1_2 = 0, temp2_2;
    if (n == 1) // Initialize
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    if (mem[n] > 0) // Memorization
    {
        return mem[n] % 10007;
    }

    // 1*2 먼저 넣는 경우
    if (n > 2)
    {
        temp1_2 = tiling(n - 2, mem);
    }

    // 2*2 먼저 넣는 경우
    temp2_2 = tiling(n - 1, mem);
    mem[n] = (temp1_2 + temp2_2) % 10007;

    return mem[n];
}