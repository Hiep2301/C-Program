#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    int a;
    printf("Nhap mot so nguyen duong bat ki: ");
    scanf("%d", &a);
    //Biến đếm số ước số của a trong khoảng từ 2 -> sqrt(a)
    int count = 0;

    for(int i = 2; i <= sqrt(a); i++)
    {
        //Nếu a chia hết cho i thì tăng biến đếm count 
        if(a % i == 0)
        {
            count++;
        }
    }

    if(count != 0)
    {
        printf("%d khong phai la so nguyen to", a);
    }
    else
    {
        printf("%d la so nguyen to!", a);
    }
    
    return 0;
}
