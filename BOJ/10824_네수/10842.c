#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b);
int main()
{
    int a, b, c, d;
    char cha[1000001], chb[1000001], chc[1000001], chd[1000001];
    long long result;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    sprintf(cha, "%d", a);
    sprintf(chb, "%d", b);
    sprintf(chc, "%d", c);
    sprintf(chd, "%d", d);

    strcat(cha, chb);
    strcat(chc, chd);

    result = atoll(cha) + atoll(chc);
    printf("%lld\n", result);
    return 0;
}