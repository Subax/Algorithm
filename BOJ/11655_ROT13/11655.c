#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[101] = {
        '\0',
    };
    scanf("%[^\n]", str);
    int len = strlen(str);
    int temp;

    for (int i = 0; i < len; i++)
    {
        if (isupper(str[i]))
        {
            str[i] = (str[i] - 'A' + 13) % 26 + 'A';
        }
        else if (islower(str[i]))
        {
            str[i] = (str[i] - 'a' + 13) % 26 + 'a';
        }
        else if (isdigit(str[i]) || isspace(str[i]))
        {
            continue;
        }
    }
    printf("%s\n", str);
    return 0;
}

/*
MEMO
1) 'A' = 65, 'Z' = 90
2) 'a' = 97, 'z' = 122
    -> 대문자는 대문자끼리, 소문자는 소문자끼리
*/