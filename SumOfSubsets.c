#include <stdio.h>
#include <stdlib.h>

int w[10], x[10], d;

int main()
{
    int n, i, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter elements in increasing order: ");

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        sum += w[i];
    }

    printf("\nEnter the subset max value: ");
    scanf("%d", &d);

    if (sum < d || w[1] > d)
    {
        printf("\nNo solutions");
        exit(0);
    }

    sum_subset(0, 1, sum);
    return 0;
}

void sum_subset(int s, int k, int r)
{
    int i;
    static int b = 1; // number of subsets
    x[k] = 1;

    if (s + w[k] == d)
    {
        printf("\nSubset %d: ", b++);
        for (i = 1; i <= k; i++)
        {
            if (x[i] == 1)
                printf("%d  ", w[i]);
        }
    }
    else if (s + w[k] + w[k + 1] <= d)
        sum_subset(s + w[k], k + 1, r - w[k]);

    if ((s + r - w[k] >= d) && (s + w[k + 1] <= d))
    {
        x[k] = 0;  // kth number can not be included
        sum_subset(s, k + 1, r - w[k]);
    }
}