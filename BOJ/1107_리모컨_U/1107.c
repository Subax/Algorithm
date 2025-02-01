#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int closestNumber(int N, int M, int *button);
int possible(int cnum, int M, int *button);
int main()
{
    int N, M;
    int *button = NULL;

    scanf("%d\n%d", &N, &M);

    if (M != 0)
    {
        button = (int *)malloc(sizeof(int) * M);
        for (int i = 0; i < M; i++)
        {
            scanf("%d", &button[i]);
        }
    }

    int min, mnum = 100; // moving number
    // An algorithm for moving to the closest number with N
    if (N >= 97 && N <= 103)
    {
        min = abs(N - mnum);
    }
    else
    {
        min = closestNumber(N, M, button);
    }

    printf("%d\n", min);
    if (button != NULL)
    {
        free(button);
    }
    return 0;
}

// 숫자를 눌러 가장 가까운 곳으로 가는 알고리즘, 불가능하거나 비효율적인 경우(abs(N-mnum)보다 큰 경우) -1 반환
// 가장 가까운 수가 cnum이고 i자리 수라면, (N-cnum) + i < efnum이여야 한다.
int closestNumber(int N, int M, int *button)
{
    int efnum = (int)abs(N - 100); // 얘보다 작아야 효율적
    int cnum, count, result, min = efnum;

    // 버튼 눌러서 이동하면 되는 경우
    if (M == 0)
    {
        if (N == 0) // log가 0인 경우 유의****************fuck
        {
            result = 1;
        }
        else
        {
            result = (int)log10(N) + 1;
        }
        return result;
    }

    // 어떻게 하면 가장 가까운 자리를 구할까? -> 다 해본다
    for (int i = 0; i < 1000000; i++)
    {
        cnum = i;
        if (possible(cnum, M, button) != 1) // 버튼이 고장나서 구현할 수 없는 수인 경우
        {
            continue;
        }

        if (cnum == 0)
        {
            count = 1; // log(0) = 1
        }
        else
        {
            count = (int)log10(cnum) + 1; // 자리수 계산
        }
        result = (int)abs(N - cnum) + count; // N-cnum: +/-로 이동하는 횟수, count: 번호 누르는 횟수

        if (result < min)
        {
            min = result;
        }
    }

    if (min < efnum)
    {
        return min;
    }
    return efnum;
}

// cnum이 고장난 리모컨으로 구현할 수 있는 수인지 확인하는 함수
int possible(int cnum, int M, int *button)
{
    char str[7]; // 최대 7자리수

    sprintf(str, "%d", cnum); // cnum을 한 개씩 쪼개기 위해 문자열로 변환
    int len = strlen(str);
    int temp;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < M; j++)
        {
            temp = (int)str[i] - '0';
            if (temp == button[j])
            {
                return 0; // 고장난 버튼을 사용해야 하는 경우 -> False 반환
            }
        }
    }
    return 1; // 검사 통과^^
}