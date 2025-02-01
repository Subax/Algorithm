#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100001] = {
        0,
    };
    char temp[100001] = {
        0,
    };
    int len;
    int iter = 0;
    scanf("%[^\n]s", str);
    len = strlen(str);

    for (int i = 0; i < len;)
    {
        if (str[i] == '<')
        {
            while (str[i] != '>') // '>'전까지 계속 수행
            {
                printf("%c", str[i]); // 뒤집기 없이 수행
                i++;
            }
            printf("%c", str[i]); // '>' printed
            i++;
        }
        else // case where it does not start with '<' => make reverse by stack
        {
            if (isspace(str[i])) // i == ' '
            {
                printf("%c", str[i]);
                i++;
            }
            else
            {
                while (!isspace(str[i]) && i < len && str[i] != '<') // input until empty space, before len
                {
                    temp[iter] = str[i]; // char니까 이렇게 대입 가능 / strcmp는 *char에 사용하는 겨
                    iter++, i++;
                }
                while (iter--) // print stage -> 여기에서 iter가 다시 -1로 초기화 됨
                {
                    printf("%c", temp[iter]);
                }
                iter++; // 0으로 초기화
            }
        }
    }
    printf("\n");
    return 0;
}

/*
MEMO
1) 공백을 포함하며 문자를 입력받도록 [^\n]사용 : ^ = not, => \n이 아닌 문자들은 전부 입력(공백 포함)
*/