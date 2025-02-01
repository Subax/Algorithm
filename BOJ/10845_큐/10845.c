#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct
{
    int data[10000];
    int begin;
    int end;
} queue;

void push(queue *q, int N);
void pop(queue *q);
void size(queue *q);
int empty(queue *q);
void front(queue *q);
void back(queue *q);

int main()
{
    int N, temp = 0;
    char com[10];

    queue q = {{0}, 0, 0};
    scanf("%d", &N);

    while (N--)
    {
        scanf("%s", com);         // input command
        if (!strcmp("push", com)) // 같으면 0이니까 ! 붙이기
        {
            scanf("%d", &temp);
            push(&q, temp);
        }
        else if (!strcmp("pop", com))
        {
            pop(&q);
        }
        else if (!strcmp("size", com))
        {
            size(&q);
        }
        else if (!strcmp("empty", com))
        {
            printf("%d\n", empty(&q));
        }
        else if (!strcmp("front", com))
        {
            front(&q);
        }
        else if (!strcmp("back", com))
        {
            back(&q);
        }
    }
    return 0;
}

void push(queue *q, int N)
{
    q->data[q->end++] = N;
    return;
}

void pop(queue *q)
{
    if (empty(q))
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", q->data[q->begin++]);
    }
    return;
}

void size(queue *q)
{
    printf("%d\n", q->end - q->begin);
    return;
}

int empty(queue *q)
{
    if (q->begin == q->end)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void front(queue *q)
{
    if (empty(q))
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", q->data[q->begin]);
    }

    return;
}

void back(queue *q)
{
    if (empty(q))
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", q->data[q->end - 1]);
    }
    return;
}