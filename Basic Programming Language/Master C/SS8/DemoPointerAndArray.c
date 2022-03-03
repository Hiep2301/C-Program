#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[5];

    for (int i = 0; i < 5; i++)
    {
        printf("%x\n", arr + i);
    }
    
    
    return 0;
}
