#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* Vòng lặp for lồng nhau */
    int a, b;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);

    //In ra a dòng các dấu *
    for (int i = 0; i < a; i++)
    {
        //In dòng đầu và dòng cuối
        if (i == 0 || i == a - 1)
        {
            //In ra 1 dòng các dấu *
            for (int i = 0; i < b; i++)
            {
                printf("*");
            }
        }
        else
        {
            for (int i = 0; i < b; i++)
            {
                if(i == 0 || i == b - 1)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
                
            }
        }
        printf("\n");
        
    }

    return 0;
}
