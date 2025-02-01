#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int go(char arr[50][50], int N);
int main()
{
    int N, max = 1, temp_max_col, temp_max_row;
    char temp;
    char arr[50][50]; // max size

    scanf("%d", &N);

    // 만약 N==5이면 arr[4][4]까지 저장
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf(" %c", &arr[i][j]); // 개행 문자나 공백 무시하여 입력받음
        }
    }

    // 행 기준으로 변경
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (arr[i][j] != arr[i][j + 1])
            {
                temp = arr[i][j];
                arr[i][j] = arr[i][j + 1];
                arr[i][j + 1] = temp;

                temp_max_row = go(arr, N);
                if (temp_max_row > max)
                {
                    max = temp_max_row;
                }

                // restoring
                temp = arr[i][j];
                arr[i][j] = arr[i][j + 1];
                arr[i][j + 1] = temp;
            }
        }
    }

    // 열 기준으로 변경
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (arr[j][i] != arr[j + 1][i])
            {
                temp = arr[j][i];
                arr[j][i] = arr[j + 1][i];
                arr[j + 1][i] = temp;

                temp_max_col = go(arr, N);
                if (temp_max_col > max)
                {
                    max = temp_max_col;
                }

                // restoring
                temp = arr[j][i];
                arr[j][i] = arr[j + 1][i];
                arr[j + 1][i] = temp;
            }
        }
    }

    printf("%d\n", max);
    return 0;
}

int go(char arr[50][50], int N)
{
    int max_row = 1, max_col = 1;
    int temp_row = 1, temp_col = 1;

    for (int i = 0; i < N; i++) // i는 N-1까지 검사해야함
    {
        for (int j = 0; j < N - 1; j++) // j는 인덱스에서 +1하기 때문에 N-2까지 반복문 돌려도 N-1까지 검사됨
        {
            if (arr[i][j] == arr[i][j + 1])
            {
                temp_row++;
            }
            else // 같지 않은 경우 -> temp_row가 2 이상(=유의미한 값)이면 max_row에 저장
            {
                if (temp_row > max_row)
                {
                    max_row = temp_row;
                }
                temp_row = 1; // reset
            }

            if (temp_row > max_row) // 마지막에 else에 걸리지 않고 종료한 경우(cpccc, ccccc 등) -> max_row 업데이트 해줘야 함
            {
                max_row = temp_row;
            }

            //------열 기준 계산-----------------------------------------------------
            if (arr[j][i] == arr[j + 1][i])
            {
                temp_col++;
            }
            else // 같지 않은 경우 -> temp_row가 2 이상(=유의미한 값)이면 max_row에 저장
            {
                if (temp_col > max_col)
                {
                    max_col = temp_col;
                }
                temp_col = 1; // reset
            }

            if (temp_col > max_col) // 마지막에 else에 걸리지 않고 종료한 경우 -> max_col 업데이트 해줘야 함
            {
                max_col = temp_col;
            }
        }
        temp_row = 1, temp_col = 1;
    }

    int result = max_col > max_row ? max_col : max_row; // 행 기준 값과 열 기준 값중 최댓값을 반환
    return result;
}