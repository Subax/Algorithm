#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc의 헤더파일

int main()
{
    int count = 0;

    scanf("%d", &count);

    int *arr = (int *)malloc(sizeof(int) * count * 3); // 배열 동적 할당 -> 1항 + 2항 = 결과값까지 해서 count 하나 당 배열 3칸 차지

    for (int i = 0; i < count * 3;) // 1항 + 2항 = 3결과값 순으로 배열에 저장
    {
        scanf("%d %d", &arr[i], &arr[i + 1]);
        arr[i + 2] = arr[i] + arr[i + 1];
        i += 3;
    }

    for (int j = 0; j < count * 3;)
    {
        printf("Case #%d: %d + %d = %d\n", j / 3 + 1, arr[j], arr[j + 1], arr[j + 2]);
        j += 3;
    }
    return 0;
}

/*
Memo
1. 변수 저장을 얼마나 효율적으로 하는지가 관건 -> using array
2. 변수의 저장에 사용되는 인덱스로 어떻게 번호 표시할건지 -> 3으로 나눈 뒤 1더해서 해결
3. malloc 좀 외워라
*/