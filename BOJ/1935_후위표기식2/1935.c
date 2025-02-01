#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isOPs(char ch);
double Ops(char ch, double a, double b);
int main()
{
    char input[101] = {'0'};
    int intArr[101] = {0};      // array for transform alphabet to digit
    double opsStack[101] = {0}; // stack
    int iter, loc = 0;
    double answer = 0;

    scanf("%d", &iter);
    scanf("%s", input);
    int len = strlen(input);
    for (int i = 0; i < iter; i++) // input digits which are using in algorithm
    {
        scanf("%d", &intArr[i]);
    }

    for (int i = 0; i < len; i++) // main algorithm
    {
        if (isOPs(input[i]) && loc > 1) // loc must bigger than 1. if not, it will occur segmentation fault.
        {
            answer = Ops(input[i], opsStack[loc - 2], opsStack[loc - 1]);
            opsStack[loc - 2] = answer;
            loc--;
        }
        else // input[i] is character. then transform to digit and save.
        {
            opsStack[loc] = (double)intArr[(int)input[i] - 65];
            loc++;
        }
    }

    printf("%.2f\n", opsStack[0]);
}

int isOPs(char ch) // Return True if character is operator
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

double Ops(char ch, double a, float b)
{
    if (ch == '+')
    {
        return a + b;
    }
    else if (ch == '-')
    {
        return a - b;
    }
    else if (ch == '*')
    {
        return a * b;
    }
    else if (ch == '/')
    {
        return a / b;
    }
    else
    {
        return 0.0;
    }
}

/*
MEMO
1) postfix notation equation 식을 문자로 입력받으니까, 문자를 적절하게 숫자로 변환하는 알고리즘 필요
    -> ASCII Code 이용해보면 어떨까? (A:65, Z:90)
    -> 여기에 index 이용해서 해보자!!
        -> A~Z까지 필요한만큼 '순차적으로' 이용하는 게 규칙이니, A = intarr[0], B = intarr[1] ...임
        -> 그러면 65 = intarr[0], 66 = intarr[1]... 이니까
            opsStack[loc] = intarr[input[i] - 65]

*/