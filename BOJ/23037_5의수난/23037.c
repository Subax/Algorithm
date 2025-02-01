#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char str[5];
    int sum = 0, temp;

    for (int i = 0; i < 5; i++)
    {
        scanf("%c", &str[i]);
        temp = (int)str[i] - '0';
        sum += temp * temp * temp * temp * temp;
    }

    printf("%d\n", sum);
    return 0;
}