#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void push(int *arr, int value, int *size)
{
    arr[*size] = value;
    (*size)++;
}

void pop(int *arr, int *size)
{
    if (*size == 0)
    {
        printf("-1\n");
        return;
    }

    int temp = arr[--(*size)];
    printf("%d\n", temp);
}

void empty(int size)
{
    printf("%d\n", size == 0 ? 1 : 0);
}

void top(int *arr, int size)
{
    if (size > 0)
    {
        printf("%d\n", arr[size - 1]);
    }
    else
    {
        printf("-1\n");
    }
}

int main()
{
    char command[10]; // 명령어 저장용 배열
    int num, size = 0;
    int iter;
    int arr[10000] = {0};

    scanf("%d", &iter);

    while (iter--)
    {
        scanf("%s", command); // 명령어 입력

        if (strcmp(command, "push") == 0)
        {
            scanf("%d", &num); // 숫자 입력
            push(arr, num, &size);
        }
        else if (strcmp(command, "pop") == 0)
        {
            pop(arr, &size);
        }
        else if (strcmp(command, "empty") == 0)
        {
            empty(size);
        }
        else if (strcmp(command, "top") == 0)
        {
            top(arr, size);
        }
        else if (strcmp(command, "size") == 0)
        {
            printf("%d\n", size);
        }
    }
    return 0;
}