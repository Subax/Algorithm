#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isVPS(char *str, int loc);
int main()
{
    char str[1000001] = {0};
    char temp[100001] = {0};
    int loc = 0, size = 0;
    int answer = 0;

    scanf("%s", str);
    int len = strlen(str);
    while (loc < len)
    {
        if (str[loc] == '(')
        {
            temp[size] = str[loc];
            loc++, size++;
        }
        else if (str[loc] == ')')
        {
            if (isVPS(str, loc)) // laser인 경우 -> 이전에 추가된 size++ 무시해야함
            {
                answer += (size - 1);
                loc++, size--;
            }
            else //(x)이 끝남 -> 해당 괄호의 마지막 연산이니 answer += 1 꼭 해주기
            {
                answer += 1;
                loc++, size--;
            }
        }
    }
    printf("%d\n", answer);
}

/*
MEMO
1) 내가 생각했던 것보단 매우매우매우매~우 쉽게 풀린당 ㅎㅎ (f***)
2) isVPS() 개념은 똑같이 가져가되, 레이저가 하나 나올 때 마다 answer에 얼마를 더해줘야 하는지 생각해보자
    -> 레이저 앞에 있는 '('의 개수로 파악할 수 있지 않을까?
    -> ')'이 나올 떄 마다 +1: 레이저로 하나를 자르면 2개로 나뉘기 때문
*/

int isVPS(char *str, int loc) //')'이 감지될 때마다 수행
{
    if (str[loc - 1] == '(' && str[loc] == ')')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}