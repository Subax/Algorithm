#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int begin;
    int end;
    int capacity;
} queue;

void josephus(int n, int k);
void push(queue *q, int N);
int pop(queue *q);
int empty(queue *q);
void resizeQ(queue *q);

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    josephus(n, k);
    return 0;
}

void josephus(int n, int k)
{
    queue q = {NULL, 0, 0, 5000};                     // 초기 용량은 5000으로 설정
    q.data = (int *)malloc(q.capacity * sizeof(int)); // 동적 메모리 할당

    int tempArr[5000] = {0};
    int arrIter = 0;

    // Insert 1 to N
    for (int i = 1; i <= n; i++)
    {
        push(&q, i); // queue에 1~n까지 차례대로 삽입
    }

    // josephus operation
    while (n--)
    {
        int iter = k - 1; // k=3이면 2번만 반복하고 Pop하면 된다
        while (iter--)
        {
            push(&q, pop(&q)); // 앞에서 빼서 끝에 넣음
        }
        tempArr[arrIter++] = pop(&q);
    }

    // print
    printf("<");
    for (int i = 0; i < arrIter; i++)
    {
        printf("%d", tempArr[i]);
        if (i != arrIter - 1) // 문자열의 끝이 아니라면
        {
            printf(", ");
        }
    }
    printf(">\n");
    free(q.data); // 동적 배열한 메모리 해제
    return;
}
void push(queue *q, int N)
{
    if (q->end >= q->capacity) // 더 이상 추가할 공간이 없는 경우
    {
        resizeQ(q);
    }
    q->data[q->end++] = N;
    return;
}
int pop(queue *q)
{
    if (empty(q))
    {
        printf("-1\n");
        exit(1); // error detected
    }
    else
    {
        return q->data[q->begin++];
    }
}
int empty(queue *q)
{
    return q->begin == q->end; // 비었으면 1, 아니면 0
}

void resizeQ(queue *q)
{
    q->capacity *= 2;
    q->data = (int *)realloc(q->data, q->capacity * sizeof(int));

    return;
}

/*
MEMO
1) *****realloc 중요!!! 동적할당한 배열의 공간이 부족한 경우 재할당 해줌*****
2) 시간 복잡도: O(nk)
*/