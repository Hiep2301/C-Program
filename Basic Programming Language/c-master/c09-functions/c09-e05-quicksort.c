/* Quick sort example */
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main()
{
    int values[] = {2, 5, -10, 1000, 19, 32, 325, 2000, 0, 1};
    int n;

    qsort(values, 10, sizeof(int), compare);
    for (n = 0; n < 10; n++)
    {
        printf("%d ", values[n]);
    }
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
