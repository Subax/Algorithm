#define _CRT_SECURE_NO_WARNIGNS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);
    int *NGE = (int *)malloc(sizeof(int) * size);
    int *temp = (int *)malloc(sizeof(int) * size);
    int loc = 0;
    for (int i = 0; i < size; i++) // save in arr
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++) // arr to NGE -> 여기 안에 for문 또 쓰면 시간초과: O(n^2)
    {
        // arr[i]의 NGE를 찾는 알고리즘이니 여기서의 비교대상은 arr[i+1]

        if (arr[i + 1] > arr[i]) // arr[i+1]이 arr[i]의 NGE인 경우
        {
            NGE[i] = arr[i + 1];
        }
        else
        {
            temp[loc] = i; // 배열에 NGE 못 찾은 원소의 인덱스 저장 -> 자기가 제일 커서 저장된 애들이니까 배열 특성상 pop하면 내림차순
            loc++;
        }

        if (loc != 0)
        {
            while (arr[i + 1] > arr[temp[loc - 1]]) // arr[i+1]보다 큰 애가 없을 때까지 반복 -> 시간 복잡도에 영향 거의 없음
            {
                NGE[temp[loc - 1]] = arr[i + 1]; // pop
                loc--;                           // pop
                if (loc == 0)
                {
                    break;
                }
            }
        }
    }

    while (loc--) // NGE 못찾은 애들 처리
    {
        NGE[temp[loc]] = -1;
    }

    for (int i = 0; i < size - 1; i++) // print NGE
    {
        printf("%d ", NGE[i]);
    }
    printf("%d\n", NGE[size - 1]);
    return 0;
}

/*
MEMO
1) Ai보다 크기만 하면 되고, 그 중 가장 왼쪽에 있는 수니까, i+1부터 순회하다가 Ai 보다 큰 수 만나면 바로 NGE에 저장하면 되지 않을까?
    -> 이게 왜 골드문제?
    -> 시간초과~~!!
    -> 지금 for(for)문 형태니까 시간복잡도 = o(n^2) => 무조건 시간 초과
    -> o(n)으로 줄여야 한다....
2) 큐를 이용해보자
    -> 큐를 이용하면 다른 애들과 비교하려는 '기준'을 잡아야 함 -> for 문 안쓸 수가 없음
3) for문을 두 번 중복 사용할 수 없으니, 바로 옆에 애들끼리 비교해야 함
    -> 바로 옆이 NGE가 아닌 경우 문제 발생
    -> stack에 인덱스를 저장시켜 두었다가 나중에 재사용 해야할듯
*/