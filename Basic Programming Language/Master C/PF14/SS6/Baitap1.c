#include<stdio.h>
#include<math.h>
int main(int argc, char const *argv[])
{
    int arrPrime[5];

    int count = 0;

    while (count != 5)
    {
        int input;
        printf("Nhap mot so nguyen to: ");
        scanf("%d", &input);
        int soUoc = 0;
        for (int i = 2; i <= sqrt(input); i++)
        {
            if(input % i == 0)
            {
                soUoc++;
            }
        }

        if(soUoc == 0)
        {
            arrPrime[count] = input;
            count++;
        }
        else
        {
            printf("So ban vua nhap ko phai la so nguyen to.\nMoi nhap lai!\n");
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arrPrime[i]);
    }
    
    
    return 0;
}
