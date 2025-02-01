#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int convertTo1(int in, int *mem);

int main()
{
    int input;
    scanf("%d", &input);

    // 메모리 할당
    int *mem = (int *)malloc(sizeof(int) * (input + 1));

    // 메모리 초기화
    for (int i = 0; i <= input; i++)
    {
        mem[i] = 0;
    }

    // 결과 출력
    printf("%d\n", convertTo1(input, mem));

    // 메모리 해제
    free(mem);

    return 0;
}

int convertTo1(int in, int *mem)
{
    if (in == 1)
    {
        return 0;
    }

    // 이미 계산된 값 반환
    if (mem[in] > 0)
    {
        return mem[in];
    }

    // 최소 연산 횟수 계산
    int result = convertTo1(in - 1, mem);

    if (in % 2 == 0)
    {
        result = (result < convertTo1(in / 2, mem) + 1) ? result : convertTo1(in / 2, mem);
    }

    if (in % 3 == 0)
    {
        result = (result < convertTo1(in / 3, mem) + 1) ? result : convertTo1(in / 3, mem);
    }

    mem[in] = result + 1; // Memorization
    return mem[in];
}