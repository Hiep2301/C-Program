#include<stdio.h>

int main(int argc, char const *argv[])
{
    /* Vòng lặp for */
    printf("So chan trong khoang 1 - 10:\n");
    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\t", i);
        }
        
    }
        
    return 0;
}
