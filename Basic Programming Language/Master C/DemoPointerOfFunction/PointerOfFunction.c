#include<stdio.h>

void Swap(int *a, int *b);
void Ascending(int *num1, int *num2);
void Descending(int *num1, int *num2);
void SortWithPointerOfFunction(int *arr, int size, void(*pCheck)(int *num1, int *num2));

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 2, 4, 5, 8, 10, 12, 9};

    SortWithPointerOfFunction(arr, 9, Descending);

    for (int i = 0; i < 9; i++)
    {
        printf("%d\t", arr[i]);
    }
    

    return 0;
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Ascending(int *num1, int *num2)
{
    if(*num1 > *num2)
    {
        Swap(num1, num2);
    }
}

void Descending(int *num1, int *num2)
{
    if(*num1 < *num2)
    {
        Swap(num1, num2);
    }
}

void SortWithPointerOfFunction(int *arr, int size, void(*pCheck)(int *num1, int *num2))
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            pCheck(&arr[i], &arr[j]);
        }
        
    }
    
}


