#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);
    int *NGF = (int *)malloc(sizeof(int) * size);
    int *temp = (int *)malloc(sizeof(int) * size);
    int iter[1000001] = {0}; // counting each cell
    int loc = 0;             // indexation for temp

    for (int i = 0; i < size; i++) // input value + counting quantity of value
    {
        scanf("%d", &arr[i]);
        iter[arr[i]]++;
    }

    for (int i = 0; i < size; i++) // main algorithm: arr to NGF
    {
        if (iter[arr[i + 1]] > iter[arr[i]]) // this is a NGF
        {
            NGF[i] = arr[i + 1];
        }
        else
        {
            temp[loc] = i;
            loc++;
        }

        if (loc != 0)
        {
            while (iter[arr[i + 1]] > iter[arr[temp[loc - 1]]]) // this is a NGF
            {
                NGF[temp[--loc]] = arr[i + 1];
                if (loc == 0)
                {
                    break;
                }
            }
        }
    }

    for (int i = loc - 1; i >= 0; i--) // NGF가 없는 원소들 -1 채우기
    {
        NGF[temp[i]] = -1;
    }

    for (int i = 0; i < size - 1; i++) // print
    {
        printf("%d ", NGF[i]);
    }
    printf("%d\n", NGF[size - 1]);
    free(arr), free(NGF), free(temp);
    return 0;
}

/*
MEMO
1) 얘도 마찬가지로 반복문을 중복해서 사용하면 시간 초과 발생하니 그렇게 하면 안되고, 바로 옆 원소와 비교하는 알고리즘 써야함
2) arr와 동일한 사이즈의 배열을 하나 만들어서 [1]: 1이 arr에 등장한 횟수를 저장하면 어떨까?
    -> 그래서 일단 arr[i+1] > arr[i]를 만족하는지 확인 (오큰수 알고리즘 사용)
    -> 그 다음 새로운 반복문에서 iter[i+1] > iter[i]인지 확인하는 방식
        => O(2n)이므로 시간복잡도는 O(n)으로 동일함

    -> 이렇게 하면 문제가 arr = [a, b, c]라고 했을 때 b와 c 모두 a의 오큰수이지만 b는 오등큰수가 아니고 c는 오등큰수인 경우에 해결할 수 없음
        -> 그러면 iter을 먼저 검사해볼까?
            -> 큰 의미 없을 듯. 검사 순서가 중요한 게 아님 원소 등장은 많으나 오큰수가 아닌 경우 지금의 문제와 동일한 문제가 발생함
        -> a의 오큰수들을 전부 저장해두는 알고리즘은?
            -> 큰 의미 없을 듯. 그러면 뭐 내 생일까지 저장할래?
        => 처음에 scanf 받을 때 counting 해버리자!!!!!
            -> 그러면 main 반복문에서 바로 오등큰수인지도 계산 같이 가능
3) 어.. 문제를 잘못 읽었다 ㅋㅋㅋㅋㅋ
    -> 오큰수 개념 빼고, 그냥 counting만 하면 된대...
    -> 그냥.. 오큰수랑 비슷하네...
*/