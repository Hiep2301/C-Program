#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    int num;
    printf("Nhap mot so nguyen duong lon hon 2: ");
    scanf("%d", &num);
    int count = 0; //Dem uoc cua num trong khoang tu 2 -> num

    for (int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            count++;
        }
    }

    if(count == 0)
    {
        printf("%d la so nguyen to", num);
    }
    else
    {
        printf("%d khong phai la so nguyen to", num);
    }
    
    
    return 0;
}
