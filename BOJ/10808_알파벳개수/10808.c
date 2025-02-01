#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int str[26] = {0};
    char input[101] = {0};

    scanf("%s", input);
    int len = strlen(input);

    for (int i = 0; i < len; i++)
    {
        str[(int)input[i] - 97] += 1;
    }

    for (int i = 0; i < 25; i++)
    {
        printf("%d ", str[i]);
    }
    printf("%d\n", str[25]);
    return 0;
}