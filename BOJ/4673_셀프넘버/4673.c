#define _CRT_SECURE_NO_WARNIGNS
#include <stdio.h>
#include <string.h>

int main()
{
    int len, sum;
    int result[10001] = {0}; // 연산 후에도 값이 0인 배열은 셀프넘버인 배열, 1 to 10000, result[0]은 사용안함
    char chDigit[10];        // 최대  다섯자리인 저웃 저장
    for (int i = 1; i < 10001; i++)
    {
        sum = 0;
        sprintf(chDigit, "%d", i);
        len = strlen(chDigit);
        for (int j = 0; j < len; j++)
        {
            sum += chDigit[j] - '0';
        }
        sum += i;
        if (sum > 10001)
        {
            continue;
        }
        result[sum] = 1;
    }

    for (int i = 1; i <= 10001; i++)
    {
        if (result[i] == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}

/*Memo
1) 전부 계산한 후 없는 숫자들을 빼주기
*/