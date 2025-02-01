#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[101] = {0};
    while (scanf("%[^\n]", input) == 1) // ==1 붙으면 되고 안붙으면 틀린다.. 나중에 다시보자^^
    {
        int result[4] = {0};
        int len = strlen(input);
        if (len == 0)
        {
            break;
        }
        for (int i = 0; i < len; i++)
        {
            if (islower(input[i]))
            {
                result[0] += 1;
            }
            else if (isupper(input[i]))
            {
                result[1] += 1;
            }
            else if (isdigit(input[i]))
            {
                result[2] += 1;
            }
            else // isspace
            {
                result[3] += 1;
            }
        }
        printf("%d %d %d %d\n", result[0], result[1], result[2], result[3]);
        scanf("%*c"); // buffer에서 \n 비우기
    }
    return 0;
}