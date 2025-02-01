#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main()
{
    char N[30];     // 문자열로 인식, 최대 10억이므로 가장 작은 2진수 경우에 30자리수로 표현되므로 N[30]으로 할당
    int B;          // 진수 인식
    int result = 0; // 10진수 변환
    int k = 0;      // 제곱수
    scanf("%s %d", N, &B);

    for (int i = strlen(N) - 1; i >= 0; i--) // N[i]부터 연산 = 첫번째 자리수부터 연산
    {
        if (N[i] == '\0') // 빈 문자열이 입력된 경우
        {
            return 0;
        }

        if (isdigit(N[i])) // N[i]의 ASCII Code가 '0'-'9'에 있는 경우
        {
            result += ((int)N[i] - 48) * (int)pow(B, k); // pow(B, k) = B^k, '0'의 ASCII값이 48임에 유의
        }
        else // N[i]가 문자인 경우
        {
            int temp = (int)N[i] - 55; //'A'의 ASCII값이 55임에 유의
            result += temp * pow(B, k);
        }
        k++; // 제곱수 증가
    }
    printf("%d\n", result);

    return 0;
}

/*
Memo
1. 예를 들면 2진법인 숫자 N이 주어졌을 때 10진법으로 변환하는 것
2. 이 문제에서 36진법까지 제한해뒀고, 35를 한자리에 표현하려면 Z를 사용하면 된다.
그래서 36진법에서 ZZ를 10진법으로 변환하면 36^2 * 35 + 36^1 * 35가 되는 것!!

=> 여기에서 문자를 숫자로 변환할 때, 배열에 하나하나 다 넣어두기 귀찮으니 아스키 코드를 이용해보면 어떨까? 대문자 A를 10으로 조정해서!
    ->A = 65, Z = 90이니 각 값에서 55를 뺀 값으로 변환하면 됨

**************WARNING***************
1. 처음 입력 받을 때 char*로 입력 받았으니 당연히 배열 한 칸의 자료형은 char임!!!!!!!!! 숫자인 경우 반드시 int로 형 변환 후 사용해야 함
2. (int)'0' = 0이 아니고 48!!!!!!! '0'을 문자 0으로 인식해서 아스키값에 맞게 48로 변환함
*/