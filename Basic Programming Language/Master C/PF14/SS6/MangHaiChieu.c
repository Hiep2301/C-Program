#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[3][4] = 
    {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%-5d", arr[i][j]);
        }
        
    }
    

    return 0;
}
