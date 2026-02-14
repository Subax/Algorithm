#include <stdio.h>

int main()
{
    char s[1001];
    int d;

    scanf("%s", s);
    scanf("%d", &d);

    printf("%c\n", s[d - 1]);

    return 0;
}