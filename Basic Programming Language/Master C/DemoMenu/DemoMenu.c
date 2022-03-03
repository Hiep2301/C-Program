#include<stdio.h>

int main(int argc, char const *argv[])
{
    int choice;
    do
    {
        printf("1. Menu 1\n");
        printf("2. Menu 2\n");
        printf("3. Menu 3\n");
        printf("4. Menu 4\n");
        printf("5. Menu 5\n");
        printf("0. Exit\n");
        printf("==================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        
    } while (choice != 0);
    
    return 0;
}
