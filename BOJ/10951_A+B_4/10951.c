#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) == 2)
    {
        printf("%d\n", a + b);
    }
    return 0;
}

/*
Memo

Objective: Unknown number of test case -> find and conquer
    -> input if there is no more input
    -> *****scanf(%d %d) != 2 -> state that there is no more input*****

Time Complexity: O(N) -> quantity of input
*/