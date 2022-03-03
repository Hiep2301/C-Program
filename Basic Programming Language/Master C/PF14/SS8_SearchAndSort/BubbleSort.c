#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int arr[100];
    srand(time(NULL));

    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 1000;
    }

    printf("Mang 100 so nguyen khi chua sap xep:\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d   ", arr[i]);
    }

    //Bubble Sort
    for (int i = 0; i < 99; i++)
    {
        for (int j = 0; j < 99; j++)
        {
            //Sap xep tu be den lon
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }
    
    printf("\nMang sau khi dc sap xep tu be den lon: \n");
    
    for (int i = 0; i < 100; i++)
    {
        printf("%d   ", arr[i]);
    }
    
    return 0;
}

