#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int a[10];
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        a[i] = rand() % 11;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    //MAX
    int max = a[0], count_max = 0;
    for (int i = 0; i < 10; i++)
    {
        if(a[i] > max) {
            max = a[i];
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if(a[i] == max) {
            count_max++;
        }
    }
    printf("%d la max co %d lan xuat hien", max, count_max);
    printf("\n");
    //MIN
    int min = a[0], count_min = 0;
    for (int i = 0; i < 10; i++)
    {
        if(a[i] < min) {
            min = a[i];
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if(a[i] == min) {
            count_min++;
        }
    }
    printf("%d la min co %d lan xuat hien", min, count_min);
    return 0;
}
