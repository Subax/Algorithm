#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char psa[50];
    int len;
} ps;

void findVPS(ps *ps);

int main()
{
    ps ps;
    int iter;

    scanf("%d", &iter);
    while (iter--)
    {
        scanf("%s", ps.psa);
        ps.len = strlen(ps.psa);
        findVPS(&ps); // ps의 주소를 넘겨줌
    };
    return 0;
}

void findVPS(ps *ps)
{
    char temp[50] = {
        0,
    };
    int j = 0; // key for문이 다 돌고 j==0이면 VPS
    int length = ps->len;

    for (int i = 0; i < length; i++)
    {
        if (ps->psa[i] == '(')
        {
            temp[j] = ps->psa[i]; // = '('
            j++;
        }
        else //')'가 들어온 경우
        {
            if (temp[j - 1] == '(' || j - 1 >= 0)
            {
                temp[--j] = '0'; // Push!!
            }
            else // error
            {
                j = -1; // 오류를 의미하는 값
                break;
            }
        }
    }
    if (j == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
