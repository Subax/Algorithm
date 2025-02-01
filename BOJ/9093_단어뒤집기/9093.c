#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int iter, len;
    char str[1000] = {
        0,
    };
    scanf("%d", &iter);

    while (iter--)
    {
        while (1)
        {
            scanf("%s", str);  // 빈칸 기준으로 입력받음
            len = strlen(str); // \0을 제외한 문자열의 길이 반환
            for (; len > 0; len--)
            {
                printf("%c", str[len - 1]); // str[0]부터 저장됨에 유의
                str[len - 1] = 1 '\0';      // NULL로 초기화
            }
            char c = getchar(); // buffer flush
            if (c != '\n')
            {
                printf(" ");
                ungetc(c, stdin);
            }
            else
            {
                break;
            }
        }
        printf("\n");
    }
}

/*
MEMO

1) 문자열의 끝이 \n인 것을 이용해서 \n일 때까지 입력 받는 것 불가 -> scanf는 ***공백, tap, \n***을 기준으로 입력받기 때문
    -> 개행문자 신경도 안씀... 처리를 안하고 buffer에 남겨둠
2) fgets 안쓰고 scanf로 어떻게 공백 포함 문자열의 끝을 인식할 것인가?
    -> buffer 분석을 통해 scanf를 수행하고 개행문자가 남은 경우를 인식
*/