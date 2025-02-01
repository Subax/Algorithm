#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, sum = 0;
    scanf("%d", &N);

    char *arr = (char *)malloc(sizeof(char) * N);
    scanf("%s", arr);
    for (int i = 0; i < N; i++)
    {
        sum += (int)arr[i] - '0';
    }

    printf("%d\n", sum);
    return 0;
}