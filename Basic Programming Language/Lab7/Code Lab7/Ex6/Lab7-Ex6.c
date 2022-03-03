#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[20];
    int a = 0, b = 1;
    printf("%d %d ", a, b);
    for (int i = 3; i < 20; i++)
    {
        arr[i] = a + b;
        a = b;
        b = arr[i];
        printf("%d ", arr[i]);
    }
    
    return 0;
}
