#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);

    int *arr = (int *)malloc(sizeof(int) * T * 3); // 1항, 2항, 결과항까지 3항 저장용 가변배열 선언

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &arr[i * 3], &arr[i * 3 + 1]);
    }

    for (int i = 0; i < T; i++)
    {
        int result = arr[i * 3] + arr[i * 3 + 1];
        printf("Case #%d: %d\n", i + 1, result);
    }

    return 0;
}