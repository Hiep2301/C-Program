#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    //Sinh so ngau nhien tu 0 den 2.
    int computerChoice = rand() % 3;

    // 0 la Bua
    // 1 la Keo
    // 2 la Bao

    int humanChoice;
    printf("Nhap 0 or 1 or 2: ");
    scanf("%d", &humanChoice);

    printf("May tinh chon: %d\n", computerChoice);
    printf("Ban chon     : %d\n", humanChoice);
    printf("-------------------------------------\n");

    if(computerChoice == humanChoice)
    {
        printf("Hoa!!!");
    }
    else
    {
        if (humanChoice == 0) //Bua
        {
            if(computerChoice == 1) //Keo
            {
                printf("Ban thang");
            }
            else if(computerChoice == 2) //Bao
            {
                printf("May tinh thang!");
            }
        }
        else if (humanChoice == 1) //Keo
        {
            if(computerChoice == 0) //Bua
            {
                printf("May tinh thang");
            }
            else if(computerChoice == 2) //Bao
            {
                printf("Ban thang!");
            }
        }
        else if (humanChoice == 2) //Bao
        {
            if(computerChoice == 0) //Bua
            {
                printf("Ban thang");
            }
            else if(computerChoice == 1) //Keo
            {
                printf("May tinh thang!");
            }
        }
        
    }
    
    return 0;
}
