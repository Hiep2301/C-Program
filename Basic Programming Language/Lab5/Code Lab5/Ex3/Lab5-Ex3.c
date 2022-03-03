#include <stdio.h>
int main(int argc, char const *argv[])
{
    for (int i = 201; i < 300; i++)
    {
        if (i % 9 == 0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}
