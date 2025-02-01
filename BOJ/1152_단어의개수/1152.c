#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int len, size = 0;
    char str[1000000];

    scanf("%[^\n]", str); //\n이 입력되기 전까지 입력받음 ^\n = not \n
    len = strlen(str);

    if (len == 1 && str[0] == ' ')
    {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i < len - 1; i++)
    {
        if (str[i] == ' ')
        {
            size++;
        }
    }

    printf("%d\n", size + 1);
    return 0;
}