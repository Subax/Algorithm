#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char str[1001] = {'0'};
    char temp[1000] = {'0'};

    scanf("%s", str);

    int len = strlen(str);
    int pos = 0;

    char substr[1000][1001] = {'0'};

    for (int i = 0; i < len; i++) // making sub string
    {
        pos = 0;
        for (int j = i; j < len; j++)
        {
            substr[i][pos] = str[j];
            pos++;
        }
    } // 최대 문자열 크기가 1000이므로 시간초과 x

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (strcmp(substr[i], substr[j]) < 0) // 사전식 비교에서 substr[i]가 더 큰 경우 -> 유지
            {
                continue;
            }
            else if (strcmp(substr[i], substr[j]) > 0) // substr[j]가 더 큰 경우 -> interchange
            {
                strcpy(temp, substr[i]);
                strcpy(substr[i], substr[j]);
                strcpy(substr[j], temp);
            }
            else
            {
                return 0; // error detacted
            }
        }
    }

    for (int i = 0; i < len; i++)
    {
        printf("%s\n", substr[i]);
    }
    return 0;
}

/*
Memo
1) len만큼 0~len의 크기를 가지는 배열을 len개 만드는 것이 목표 -> 이중 배열 사용
2)
*/