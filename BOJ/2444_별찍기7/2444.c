#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) // 별 개수가 증가하는 방향
    {
        int k = n - i; // 공백 출력
        for (; k > 0; k--)
        {
            printf(" ");
        }

        int j = 2 * i - 1;
        for (; j > 0; j--)
        {
            printf("*");
        }
        printf("\n");
    }

    for (int i = n - 1; i > 0; i--) // 별 개수가 감소하는 방향
    {
        int k = n - i;
        for (; k > 0; k--)
        {
            printf(" ");
        }

        int j = 2 * i - 1;
        for (; j > 0; j--)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

/*
Problem
1. How to make empty space? => 별 오른쪽의 공백까지 신경쓸 필요는 없음 -> 왼쪽만 잘 처리하면 오른쪽은 알아서 정렬

Algorithm
1.
*/