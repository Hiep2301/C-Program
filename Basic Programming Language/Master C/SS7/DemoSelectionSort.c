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
    int temp, iMin;
    for (int i = 0; i < 99; i++)
    {
        //Gán index của phần tử nhỏ nhất = i
        iMin = i;
        //So sánh giá trị tại iMin với các phần tử còn lại trong mảng
        for (int j = i + 1; j < 100; j++)
        {
            //Nếu arr[j] < arr[iMin] thì gán iMin = j
            if(arr[j] < arr[iMin])
            {
                iMin = j;
            }
        }

        //Nếu iMin khác i thì tiến hành hoán vị.
        if(iMin != i)
        {
            temp = arr[i];
            arr[i] = arr[iMin];
            arr[iMin] = temp;
        }    
    }
    
    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d\t", arr[i]);
    }

    
    
    return 0;
}
