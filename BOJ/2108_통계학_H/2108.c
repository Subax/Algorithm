#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// qsort를 위한 비교 함수
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int N;
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int) * N);

    int modeArr[8001]; // modeArr[0] = -4000, modeArr[4000] = 0, ...
    for (int i = 0; i < 8001; i++)
    {
        modeArr[i] = -1;
        // -1이 아니고 0으로 초기화하면 modeArr[i]가 한 개만 1이고 나머지는 모두 0인 경우에 대응할 수 없음:
        // modeArr[0] = 0이고 초기화 0으로 했으면 여기에서 바로 modeArr[0] == max로 인식함
    }
    int max = 0;

    int modeTemp[8001] = {0}; // to finding the secondary minimum value
    int pos = 0, flag = 0;

    long long mean = 0;
    long long median, mode, scope;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);

        mean += arr[i]; // 합 계산

        if (modeArr[arr[i] + 4000] == -1) // modeArr 배열이 초기상태인 경우
        {
            modeArr[arr[i] + 4000] += 2; // 빈도 저장
        }
        else // 초기상태가 아닌경우
        {
            modeArr[arr[i] + 4000] += 1; // 빈도 저장
        }
    }

    // qsort로 정렬
    qsort(arr, N, sizeof(int), compare); // nlogn보장

    median = arr[(N - 1) / 2];

    // mode 최빈값 찾기: 최빈값이 여러 개인 경우 수의 크기가 두 번째로 작은 수 선택해야 함
    // data에서 최빈값이 중복 발견 되는 경우가 있을 때, 그 뒤의 탐색에서 최빈값이 갱신된다면 modeTemp를 초기화해야함(ex. 1/2/3/4/4 -> 1,2,3이 빈도수 모두 동일하나 4에서 초기화)
    for (int i = 0; i < 8001; i++)
    {
        if (modeArr[i] > max)
        {
            pos = 0, flag = 0; // modeTemp 초기화!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! fuck
            max = modeArr[i];  // 최빈값 발견 횟수 저장
            mode = i - 4000;   // 최빈값 저장
        }
        else if (modeArr[i] == max) // 최빈값이 여러개
        {
            if (flag == 0) // 최빈값이 복수 발견된 초기 상황인 경우
            {
                modeTemp[pos++] = mode;
            }
            modeTemp[pos++] = i - 4000;
            flag = 1; // Cases where quick sort is needed
        }
    }

    if (flag == 1) // 앞에서 발견 횟수 1로 최빈값이 중복 발견되더라도, ***** 뒤에 더 큰 최빈값이 발견될 수 있음 ***** -> 그 경우에 flag / modeTemp 초기화 해줘야 함
    {
        qsort(modeTemp, pos, sizeof(int), compare); // modeTemp[1] = 두 번째로 작은 최빈값
        mode = modeTemp[1];
    }

    scope = arr[N - 1] - arr[0];

    // 출력**************************************************************************************
    if (mean < 0 && llabs(mean) < N) // -0이 출력되는 경우
    {
        mean = 0;
        printf("%lld\n", mean);
    }
    else
    {
        double temp = (double)mean / N; // mean을 먼저 double로 형변환해야 double로 저장됨: int + int를 double 자료형에 저장해도 int로 저장됨
        printf("%.0f\n", round(temp));
    }

    printf("%lld\n", median);
    printf("%lld\n", mode);
    printf("%lld\n", scope);

    free(arr);
    return 0;
}

/*
fuck!!!!!!!!!!!!!!!!!!!!!!!! moment
1) double a = int b+int c 하면 a에는 int형이 저장된다.
2) 중앙값은 ***증가하는 순서***로 나열해야 한다. 1, 1, 2, 4, 2, 5, 5인 경우 중앙값은 인덱스 중앙인 2가 아니라 1, 2, 5에서 중앙인 2이다. (이 경우엔 동일하지만 아닌 경우도 있다.)
*/