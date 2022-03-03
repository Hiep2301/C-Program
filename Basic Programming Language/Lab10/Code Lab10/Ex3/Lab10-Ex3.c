#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int a[5], b[5], *pa, *pb;
    pa = a; // gán địa chỉ vùng nhớ đầu tiên của mảng a cho pa = &a[0]
    pb = b; // gán địa chỉ vùng nhớ đầu tiên của mảng  bcho pb = &b[0]
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        //*(pa + i) <=> a[i]
        *(pa + i) = rand() % 101;
    }
    for (int i = 0; i < 5; i++)
    {
        //*(pb + i) <=> a[i]
        *(pb + i) = rand() % 101;
    }
    printf("Mang a:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, *(pa + i));
    }
    printf("\nMang b:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("b[%d] = %d\n", i, *(pb + i));
    }

    int c[5], *pc;
    pc = c;
    printf("\nMang c:\n");
    for (int i = 0; i < 5; i++)
    {
        *(pc + i) = *(pa + i) + *(pb + i);
        printf("c[%d] = %d + %d = %d\n", i, *(pa + i), *(pb + i), *(pc + i));
    }
    int sum = 0;
    printf("\nTong cac phan tu mang c:\n");
    for (int i = 0; i < 5; i++)
    {
        sum += *(pc + i);
    }
    printf("sum = %d", sum);
    return 0;
}
