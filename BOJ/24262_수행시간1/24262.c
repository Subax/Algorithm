#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// O(N^3)
// 첫번째 반복문 : n-2번 반복
// 두번째 반복문 : 평균적으로 (n-1) / 2번 반복
// 세번째 반복문 : 평균적으로 (n-1) / 2번 반복
// 따라서 수행횟수 = (n-2)* (n-1) * (n-1) / 4
int main()
{
    long long n;
    scanf("%lld", &n);

    printf("%lld\n", (n - 2) * (n - 1) * n / 6);
    printf("3\n");

    return 0;
}