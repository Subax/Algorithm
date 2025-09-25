#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int caseNum, resultM = 1, resultm = 0;
    scanf("%d", &caseNum);
    char str[100] = {
        '0',
    };

    int strI[100] = {
        0,
    };
    int isize = 0;

    for (int j = 0; j < caseNum; j++)
    {
        scanf("%s", str);
        int len = strlen(str);

        for (int i = 0; i < len; i++) // for max
        {
            int sum[5] = {
                0,
            };

            if (isdigit(str[i]))
            {
                if (isdigit(str[i + 1])) // 두자리 숫자인 경우 합침
                {
                    strI[isize] = (str[i] - 48) * 10 + (str[i + 1] - 48);
                    isize++, i++;
                }
                else
                {
                    strI[isize] = str[i] - 48;
                    isize++;
                }
                continue;
            }
            else if (str[i] == '*')
            {
                continue;
            }
            else //+인 경우 양쪽의 수를 더해서 넣음
            {
                int temp1;
                if (isdigit(str[i + 1]) && isdigit(str[i + 2])) // 다음수가 두자리인 경우
                {
                    temp1 = (str[i + 1] - 48) * 10 + (str[i + 2] - 48);
                    strI[isize - 1] += temp1;
                    i++;
                    i++;
                }
                else // 다음 수가 한자리수
                {
                    strI[isize - 1] += (str[i + 1] - 48);
                    i++;
                }
            }
        }
        for (int p = 0; p < isize; p++)
        {
            resultM *= strI[p];
        }

        //---------for min    //---------for min    //---------for min

        isize = 0;
        for (int i = 0; i < len; i++) // for min
        {
            int sum[5] = {
                0,
            };

            if (isdigit(str[i]))
            {
                if (isdigit(str[i + 1])) // 두자리 숫자인 경우 합침
                {
                    strI[isize] = (str[i] - 48) * 10 + (str[i + 1] - 48);
                    isize++, i++;
                }
                else
                {
                    strI[isize] = str[i] - 48;
                    isize++;
                }
                continue;
            }
            else if (str[i] == '+')
            {
                continue;
            }
            else //*인 경우 양쪽의 수를 곱해서 넣음
            {
                int temp1, temp2;
                if (isdigit(str[i + 1]) && isdigit(str[i + 2]))
                {
                    temp1 = (str[i + 1] - 48) * 10 + (str[i + 2] - 48);
                    strI[isize - 1] *= temp1;
                    i++;
                    i++;
                }
                else //* 다음 수가 한자리수
                {
                    strI[isize - 1] *= (str[i + 1] - 48);
                    i++;
                }
            }
        }
        for (int p = 0; p < isize; p++)
        {
            resultm += strI[p];
        }
        printf("The maximum and minimum are %d and %d.\n", resultM, resultm);
    }
    return 0;
}
