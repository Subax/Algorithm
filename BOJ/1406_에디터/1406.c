#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define npush(a, b) push(a, b, '\0') // data = NULL push (negative)
#define ppush(a, b) push(a, NULL, b) // data != NULL push (positive)

typedef struct
{
    char arr[600001];
    int size;
} series;

char pop(series *Series);
void push(series *mainSeries, series *subSeries, char data);
void reversePrint(series *mainSeries, series *subSeries);

int main()
{
    series mainArr = {{0}, 0};
    series subArr = {{0}, 0};
    subArr.size = 0;

    char temp;
    int iter;

    scanf("%s", mainArr.arr);
    scanf("%d", &iter);

    mainArr.size = strlen(mainArr.arr);

    while (iter--)
    {
        scanf(" %c", &temp); // 공백문자가 아닌 글자가 나올 때까지 읽고, 읽은 공백 문자는 바로 버림

        if (temp == 'L') // push mainArr -> subArr
        {
            if (mainArr.size == 0) // 커서가 문자의 맨 앞에 위치하는 경우
            {
                continue;
            }
            npush(&subArr, &mainArr);
        }
        else if (temp == 'D') // push subArr -> mainArr
        {
            if (subArr.size == 0)
            {
                continue;
            }
            npush(&mainArr, &subArr);
        }
        else if (temp == 'B') // pop mainArr
        {
            if (mainArr.size == 0)
            {
                continue;
            }
            pop(&mainArr);
        }
        else if (temp == 'P')
        {
            scanf(" %c", &temp);
            ppush(&mainArr, temp); // using define macro, != push()
        }
    }
    reversePrint(&mainArr, &subArr);
    return 0;
}

char pop(series *Series)
{
    if (Series->size == 0)
    {
        return '\0';
    }
    char temp1;
    temp1 = Series->arr[Series->size - 1];
    Series->arr[Series->size - 1] = '\0'; // '\0' == NULL

    Series->size--;

    return temp1;
}

void push(series *mainSeries, series *subSeries, char data)
{
    // push subSeries's element to mainSeries
    // subSeries -> mainSeries
    if (subSeries != NULL) // ppush에서 NULL을 인수로 반환하는 경우가 있으므로 NULL 검사해야함
    {
        if (subSeries->size != 0) // subSeries를 pop() 한 이후 main에 push
        {
            data = pop(subSeries);
        }
    }
    mainSeries->arr[mainSeries->size++] = data;
    return;
}
void reversePrint(series *mainSeries, series *subSeries)
{
    // subSeries는 바로 출력 (이미 뒤집혀져 있음)
    // mainSeries는 뒤집어서 출력
    char temp[600001] = {
        '0',
    };
    int main_len = mainSeries->size;
    int sub_len = subSeries->size;

    //*****mainSeries 출력***** ab|dc -> ba|dc
    for (int i = 0; i < main_len; i++)
    {
        temp[i] = pop(mainSeries); // 이미 mainSeries 자체로 ***주소***이므로 & 붙일 필요 없음
        // temp = capsized_mainSeries
    }
    for (int i = main_len - 1; i >= 0; i--) // ba -> "ab"로 출력
    {
        printf("%c", temp[i]);
    }
    //*****subSeries 출력*****
    for (int i = 0; i < sub_len; i++) // dc -> "cd"로 출력
    {
        printf("%c", pop(subSeries));
    }
    printf("\n"); //== "abcd\n";
    return;
}
/*
MEMO
1) 두 개의 스택으로 구성
2) BOJ 제출할 떈 항상 data크기 유의하자... 아무리 에러 나더라도 배열 size 변경하기만 하면 정상채점되는 경우였음
*/