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
    
    //Selection sort.
    int iMin, step = 1;

    for (int i = 0; i < 99; i++)
    {
        iMin = i;
        for (int j = i + 1; j < 100; j++, step++)
        {
            if(arr[j] < arr[iMin])
            {
                iMin = j;
            }
        }

        if (iMin != i) //Tim thay so nho hon arr[iMin] 
        {
            //Tien hanh hoan vi
            int temp = arr[i];
            arr[i] = arr[iMin];
            arr[iMin] = temp;
        }
        
    }
    
    printf("\nMang sau khi dc sap xep tu be den lon: \n");
    
    for (int i = 0; i < 100; i++)
    {
        printf("%d   ", arr[i]);
    }
    return 0;
}
