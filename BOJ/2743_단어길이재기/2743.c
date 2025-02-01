#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char arr[101] = {
        '\0',
    };
    int size = 0;
    scanf("%s", arr);

    while (arr[size] != '\0')
    {
        size++;
    }
    printf("%d\n", size);
    return 0;
}