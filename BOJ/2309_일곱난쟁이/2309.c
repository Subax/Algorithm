#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int dwarf[9];
    int total = 0;
    int subTotal = 0;
    int temp, signal = 0;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &dwarf[i]);
        total += dwarf[i];
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == j)
            {
                continue;
            }
            subTotal = dwarf[i] + dwarf[j];
            if (total - subTotal == 100)
            {
                dwarf[i] = 0, dwarf[j] = 0;
                signal = 1;
                break;
            }
        }
        if (signal == 1)
        {
            break;
        }
    }

    for (int i = 0; i < 8; i++) // Selection sorting
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (dwarf[i] > dwarf[j]) // Switching
            {
                temp = dwarf[i];
                dwarf[i] = dwarf[j];
                dwarf[j] = temp;
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (dwarf[i] > 0)
        {
            printf("%d\n", dwarf[i]);
        }
    }
    return 0;
}

/*
Memo
1) 연산횟수 => 아홉명 중에 7명 뽑기 = 아홉명 중에 2명 뽑기 : N * (N-1) / 2! 따라서 O(N^2)
                               나머지 합을 구하는 시간: O(1) 따라서 이렇게 알고리즘 짜면 시간 복잡도 O(N^2)
*/