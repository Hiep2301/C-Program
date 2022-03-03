#include<stdio.h>

int main(int argc, char const *argv[])
{
    /* break and continue */
    for (int i = 0; i < 10; i++)
    {
        if(i == 5)
        {
            continue;
        }
        printf("%d\t", i);
    }
    
    return 0;
}
