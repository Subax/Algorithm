#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char input[101] = {'0'};
    int result[26];
    for (int i = 0; i < 26; i++)
    {
        result[i] = -1;
    }

    scanf("%s", input);
    int len = strlen(input);

    for (int i = 0; i < len; i++)
    {
        if (result[(int)input[i] - 97] == -1) // 한 번도 등장하지 않은 경우에만 location 값 저장
        {
            result[(int)input[i] - 97] = i;
        }
    }

    for (int i = 0; i < 25; i++)
    {
        printf("%d ", result[i]);
    }
    printf("%d\n", result[25]);
    return 0;
}