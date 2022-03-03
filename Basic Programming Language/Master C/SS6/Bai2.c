#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[10];
    double arrDouble[5];

    printf("Nhap gia tri cho cac phan tu cua mang so thuc: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("arrDouble[%d] = ", i);
        scanf("%lf", &arrDouble[i]);
    }

    //arr[0] = 0;
    arr[1] = arrDouble[0];
    //arr[2] = 0;
    arr[3] = arrDouble[1];
    //arr[4] = 0;
    arr[5] = arrDouble[2];
    //arr[6] = 0;
    arr[7] = arrDouble[3];
    //arr[8] = 0;
    arr[9] = arrDouble[4];


    
    printf("\nMang so nguyen:");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n");
    printf("Mang so thuc: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%lf", arrDouble[i]);
    }
    
    
    
    return 0;
}
