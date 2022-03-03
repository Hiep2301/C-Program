#include<stdio.h>

int main(int argc, char const *argv[])
{
    //Nested loop - Vòng lặp lồng nhau.
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
