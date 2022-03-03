#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int a[5], *ptr;
    srand(time(NULL));
    ptr = a; // gán địa chỉ vùng nhớ đầu tiên của mảng a cho ptr = &a[0]

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("a[%d] = ", i);
    //     scanf("%d", &a[i]); // (ptr + i) <=> &a[i]
    // }

    for (int i = 0; i < 5; i++)
    {
        // cách 1
        a[i] = rand() % 101;
    }
    // for (int i = 0; i < 5; i++)
    // {
    //     //cách2
    //     *(ptr + i) = rand() % 101;
    // }

    for (int i = 0; i < 5; i++)
    {
        //*(ptr + i) <=> a[i]
        printf("a[%d] = %d\n", i, *(ptr + i));
    }
    return 0;
}
