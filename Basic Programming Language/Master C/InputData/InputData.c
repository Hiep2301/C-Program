#include<stdio.h>

int inputIntData()
{
    int number;
    while (1)
    {
        printf("Nhap du lieu kieu int: ");
        scanf("%d", &number);
    }
    
}
int main(int argc, char const *argv[])
{
    int a = inputIntData();
    return 0;
}
