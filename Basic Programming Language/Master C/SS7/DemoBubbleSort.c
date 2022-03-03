#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char const *argv[])
{
    int arr[100];
    srand(time(NULL));

    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 1001;
    }

    printf("Mang truoc khi sap xep: \n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n-----------------------------\n");

    //Sắp xếp
    int temp;

    for (int i = 0; i < 99; i++)
    {
        for (int j = 0; j < 99; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        
    }
    
    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
