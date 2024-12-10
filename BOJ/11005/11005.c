#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main()
{
    int N, B, i = 0;
    char arr[32];

    scanf("%d %d", &N, &B);
    while (N != 0) // 몫이 0이 될 때까지 반복: N이 0이 되면 몫이 0이 되는 마지막 계산 끝난 것
    {
        int remainder = N % B;
        if (remainder >= 10) // 문자로 변환해야 하는 경우
        {
            arr[i] = remainder + 55; // ASCII로 변환: 'A' = 65
        }
        else // 0 - 9
        {
            arr[i] = remainder + 48; // ASCII로 변환: '0' = 48
        }
        N = N / B; // Next step
        if (N != 0) //N이 0이 되는 순간에도 i++한다면 인덱스 오류나 segmentation fault 발생할 가능성 높음 -> 틈틈히 예외처리 하기
        {
            i++;
        }
        // i-1번째 배열까지 값이 저장되고 for문 종료
    }

    for (; i >= 0; i--)
    {
        printf("%c", arr[i - 1]);
    }
    printf("\n");
    return 0;
}

/*
Memo
1) 10진수를 B진법으로 변환하기 위해서는 10진수로 표현된 임의의 수 N을 B로 계속 나눠주면서 나머지값을 역순으로 저장하면 된다.
    -> for문으로 나머지 연산(%) 계속 돌리면 되지 않을까!
2) 0의 아스키값 48, A의 아스키값 65
3) 어차피 char형 배열에 저장하니 저장 전에 (char)로 강제 형변환 시킬 필요 없음!!
4) 몫이 0이 될 때까지 연산하고 나머지만 저장하면 됨!!
*/