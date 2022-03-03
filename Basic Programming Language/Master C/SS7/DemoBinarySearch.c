#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[100];
    int fNumber;

    for (int i = 0; i < 100; i++)
    {
        arr[i] = i + 3;
    }

    printf("Mang so nguyen: \n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d\t", arr[i]);
    }
    
    printf("\n---------------------------\n");
    printf("Nhap so can tim trong mang: ");
    scanf("%d", &fNumber);

    int fIndex = -1;
    int low = 0, hi = 99, mid;

    while (low <= hi)
    {
        if(arr[low] == fNumber)
        {
            fIndex = low;
            break;
        }

        if(arr[hi] == fNumber)
        {
            fIndex = hi;
            break;
        }

        mid = (hi + low) / 2;
        if(arr[mid] == fNumber)
        {
            fIndex = mid;
            break;
        }
        else if (arr[mid] > fNumber)
        {
            hi = mid - 1;
        }
        else
        {
            low = mid + 1;
        } 
    }
    
    if(fIndex != -1)
    {
        printf("Tim thay %d tai vi tri %d trong mang arr!", fNumber, fIndex);
    }
    else
    {
        printf("%d khong ton tai trong mang arr", fNumber);
    }
    
    return 0;
}
