#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int findSeries(int *series, int iter, int printFlag);
void push(int *series, int data);
void pop(int *series);

int size;

int main()
{
    int iter;
    int series[100000] = {
        0,
    };

    scanf("%d", &iter);
    for (int k = 0; k < iter; k++)
    {
        scanf("%d", &series[k]); // series[k]는 series와 달리 주소가 아니라 값을 가지고 있으므로 & 사용해야 함
    }
    findSeries(series, iter, 1);
    return 0;
}

int findSeries(int *series, int iter, int printFlag)
{
    int digitSeries[100000] = {
        0,
    };

    int i = 0, j = 1;
    int max = 0;
    int temp = 0;
    size = 0;

    if (printFlag == 1) // 재귀 제한
    {
        if (!findSeries(series, iter, 0)) // Invalid할 때 작동, print문 사용제한, 딱 한 번만 재귀 실행
        {
            printf("NO\n");
            return 0; // Error detected
        }
    }

    while (iter--)
    {
        if (series[i] > max) // push -> pop 해야 하는 경우
        {
            temp = series[i] - max; // 단순 반복횟수
            max = series[i];
            while (temp--)
            {
                push(digitSeries, j);
                if (printFlag)
                {
                    printf("+\n");
                }
                j++;
            }
            pop(digitSeries);
            if (printFlag)
            {
                printf("-\n");
            }
            i++;
        }
        else if (series[i] == digitSeries[size - 1]) // 자연수 스택의 top에도 x, 스택 A에도 x인 경우: 바로 pop
        {
            pop(digitSeries);
            if (printFlag)
            {
                printf("-\n");
            }
            i++;
        }
        else
        {
            return 0; // Error detected
        }
    }
    return 1; // 정상처리
}

void push(int *series, int data)
{
    series[size] = data;
    size++;
}

void pop(int *series)
{
    series[size - 1] = 0;
    size--;
}

/*
Memo

규칙
1) 연속적인 push&pop은 오름차순으로만: 123 이면 구현 가능, 3,2,1이면 +++-
2) 연속적인 pop은 내림차순으로만: 12543은 구현 가능, 12534는 NO!!

Logic
1) 배열을 너무 많이 선언하는 것 같아 메모리가 걱정되어서.. 값을 배열에 저장하고 한 번에 flush하지 않고 먼저 validation 진행
    -> printFlag를 통해 오로지 validation만 하도록 설계
    -> 시간복잡도는 N -> 2N이므로 N: 동일
    -> 메모리 관리 면에서 더 우수

CAUTION
1) Stack 연산에서 size 관리에 유의
    -> size는 다음으로 저장할 인덱스를 의미하므로, 실제 인덱스 연산시에는 size - 1로 연산해줘야 함
2) 재귀함수 조건문 처리에 유의
    -> 잘못하면 무한 재귀!
*/