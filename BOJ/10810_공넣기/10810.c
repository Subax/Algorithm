#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m;
    int i, j, k;
    scanf("%d %d", &n, &m);

    int *arr = (int *)malloc(sizeof(int) * n);
    for (int z = 0; z < n; z++)
    {
        arr[z] = 0; // Initializing
    }

    for (int x = 0; x < m; x++)
    {
        scanf("%d %d %d", &i, &j, &k); // 0 to N-1, But actually 1 to N
        for (int y = i - 1; y < j; y++)
        {
            arr[y] = k;
        }
    }

    for (int x = 0; x < (n - 1); x++)
    {
        printf("%d ", arr[x]);
    }
    printf("%d\n", arr[n - 1]);
    return 0;
}