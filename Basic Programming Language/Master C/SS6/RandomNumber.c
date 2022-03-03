#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    //Khai báo mảng số nguyên có 1000 phần tử.
    int arr[1000];

    srand(time(NULL));

    for (int i = 0; i < 1000; i++)
    {
        arr[i] = rand() % 1501;
    }

    for (int i = 0; i < 1000; i++)
    {
        printf("%d\t", arr[i]);
    }
    
    
    return 0;
}
