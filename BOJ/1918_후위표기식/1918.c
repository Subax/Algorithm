#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int makeInfixToPostfix(char *ch, int len);
int checkPriority(char ch1, char ch2);
int main()
{
    char input[101] = {'0'};

    scanf("%s", input);
    int len = strlen(input);

    if (makeInfixToPostfix(input, len))
    {
        return 0;
    }
    else
    {
        return 0;
    }
}

int makeInfixToPostfix(char *input, int len)
{
    char opsArr[101] = {'0'};
    char result[101] = {'0'};
    int opsLoc = 0, resultLoc = 0;
    int status = 0; // check '()'

    for (int i = 0; i < len; i++)
    {
        if (isalpha(input[i])) // if input[i] is alphabet, push it immediately!
        {
            result[resultLoc++] = input[i];
        }
        else if (opsLoc == 0) // Initial status -> push it!
        {
            opsArr[opsLoc++] = input[i];
        }
        else if (opsLoc != 0)
        {
            if (input[i] == '(') // push
            {
                opsArr[opsLoc++] = input[i];
            }
            else if (input[i] == ')') // pop until '('
            {
                while (opsArr[opsLoc - 1] != '(')
                {
                    result[resultLoc++] = opsArr[--opsLoc];
                }
                if (opsLoc != 0)
                {
                    opsLoc--; // push '('
                }
            }
            else if (checkPriority(opsArr[opsLoc - 1], input[i])) // the case that we should push input[i] to opsArr
            {
                opsArr[opsLoc++] = input[i];
            }
            else if (!checkPriority(opsArr[opsLoc - 1], input[i])) // the case that we should pop opsArr to result & push input[i]
            {
                result[resultLoc++] = opsArr[--opsLoc]; // pop
                while (opsLoc != 0)
                {
                    if (!checkPriority(opsArr[opsLoc - 1], input[i])) // pop until checkPriority is 1
                    {
                        result[resultLoc++] = opsArr[--opsLoc];
                    }
                    else
                    {
                        break;
                    }
                }
                opsArr[opsLoc++] = input[i];
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }

    while (opsLoc--)
    {
        result[resultLoc++] = opsArr[opsLoc];
    }

    printf("%s\n", result);
    return 1;
}

int checkPriority(char ch1, char ch2) // if priority of ch2 is bigger than ch1, return 1 (ch2 > ch1)
{
    if (((ch1 == '+' || ch1 == '-') && (ch2 == '*' || ch2 == '/')) || ch1 == '(')
    {
        return 1; // It means push ch2 to opsArr
    }
    return 0; // It means pop ch1 from opsArr, and then push ch2 to opsArr
}

/*
MEMO
1) 새로 들어올 연산자의 우선순위가 연산자 스택의 가장 위에 위치한 연산자의 우선순위보다 작거나 같으면 스택에서 result로 pop
    = 새로 들어올 연산자의 우선순위가 더 크면 push
        -> + 있을 떄 *이나 /은 ok, 하지만 +이나 - 들어오면 스택에 있는 애는 pop, 그 다음 push
2) 괄호가 포함된 식의 경우 여는 괄호는 연산자 스택에 넣고, 닫는 괄호가 나오면 여는 괄호가 나올 때까지 연산자 스택 pop
*/