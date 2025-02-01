#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isVPS(char *str, int loc);
int main()
{
    char str[100001] = {0};
    char temp[100001] = {0};
    int tempOPs[100001] = {0}; // tempOPs[0] = 첫 번째 ()안에 몇 개의 VPS가 있는지
                               // =>(tempOPs+1).sum() == answer
                               // => vps가 2개면 나눠지는 건 3개 -> +1 해준 것

    int loc = 0, len;                // for location
    int status = 0, statusCount = 0; // indicate temp's status
    int sep = 0;                     // separator
    int answer = 0;

    scanf("%s", str);
    len = strlen(str);

    while (loc < len) // 전부 순회할 때까지 반복
    {
        printf("loc: %d\n", loc);
        if (status == 0 && isVPS(str, loc)) // meaningless laser
        {
            loc += 2;
            printf("1\n");
        }
        else if (isVPS(str, loc)) // status isn't 0 => ex) '(()'
        {
            loc += 2;
            sep++;
            printf("2\n");
        }
        else if (str[loc] == '(') // ensure at least '(('
        {
            if (sep != 0) //(와 ( 사이에 VPS가 있는 경우
            {
                tempOPs[status] += sep;
                sep = 0;
            }
            temp[status] = str[loc]; // saved in stack
            status++, statusCount++, loc++;
            printf("3\n");
        }
        else if (str[loc] == ')') // must verifying temp[status] == '(' by status==0
        {
            printf("4\n");
            if (temp[status - 1] != '(')
            {
                printf("Error\n");
                return 0;
            }
            tempOPs[status] += sep;
            printf("temp: %d\n", tempOPs[status]);
            sep = 0;         // initialized
            if (status != 0) // status는 0이 되면 안됨
            {
                status--;
            }
            loc++;
        }
    }
    for (int i = 0; i < statusCount; i++)
    {
        for (int j = i + 1; j < statusCount; j++)
        {
            tempOPs[i] += tempOPs[j];
        }
    }
    printf("%d\n", answer);
    return 0;
}

int isVPS(char *str, int loc) //'(' 다음 바로 ')'인지 확인하는 함수
{
    if (str[loc] == '(' && str[loc + 1] == ')')
    {
        return 1; // True
    }
    else
    {
        return 0; // False
    }
}

/*
MEMO
1)'('로 열렸으면서 isVPS가 ')'이 아닐 때 status++
2) isVPS == 1 이면 sep+1
    => status += status*sep
    => 한 번 수행해도 status 0 이면 그냥 넘어감 (=의미없는 레이저)
3) status = 4에서 안에 있는 VPS가 3개, status = 3에서 계산된 VPS가 1개 => status = 3의 answer = (3 + 1) + 1
    => status가 큰 놈에서 작은 놈 방향으로 누적
*/