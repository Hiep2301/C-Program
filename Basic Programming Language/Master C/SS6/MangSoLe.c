#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arrOdd[5];
    int i = 0;
    while (1)
    {
        printf("Nhap so nguyen duong bat ki: ");
        int num;
        scanf("%d", &num);
        
        if((num % 2) != 0)
        {
            arrOdd[i] = num;
            i++;
        }
        else
        {
            printf("Chi dc nhap so le! Yeu cau nhap lai!\n");
            continue;
        }

        if (i > 4)
        {
            break;
        }
        
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arrOdd[i]);
    }
    
    return 0;
}
