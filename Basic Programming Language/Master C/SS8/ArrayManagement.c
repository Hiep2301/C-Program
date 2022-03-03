#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int size = 0;
    int *pArr = NULL;

    while (1)
    {
        printf("\n-----Array Management System-----\n");
        printf("1. Create array\n");
        printf("2. Insert value's item\n");
        printf("3. Add new item to array\n");
        printf("4. Delete item in array\n");
        printf("5. Update value of item\n");
        printf("6. Display array.\n");
        printf("0. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter size of array you want to create: ");
            scanf("%d", &size);
            pArr = malloc(size * sizeof(int));
            break;
        case 2:
            if (pArr != NULL)
            {
                for (int i = 0; i < size; i++)
                {
                    printf("pArr[%d] = ", i);
                    scanf("%d", pArr + i);
                }
            }
            break;
        case 3:
            if (pArr != NULL)
            {
                pArr = realloc(pArr, sizeof(int));
                size++;
                printf("Enter value of new item: ");
                scanf("%d", (pArr + size - 1));
            }

            break;
        case 4:
            printf("Enter index of item you want to delete: ");
            int position;
            scanf("%d", &position);
            if (position < 0 && position >= size)
            {
                printf("Item doesn't exist in array!!!");
            }
            else
            {
                //Xóa phần tử khỏi mảng
                for (int i = position; i < size - 1; i++)
                {
                    pArr[i] = pArr[i + 1];
                }
                size--;
            }
            break;
        case 5:
            printf("Enter index of item you want to update: ");
            scanf("%d", &position);
            if (position < 0 && position >= size)
            {
                printf("Item doesn't exist in array!!!");
            }
            else
            {
                printf("pArr[%d] = ", position);
                scanf("%d", &pArr[position]);
            }
            break;
        case 6:
            printf("---------------------------------\n");
            printf("Array: \n");
            for (int i = 0; i < size; i++)
            {
                printf("%d\t", *(pArr + i));
            }

            break;
        case 0:
            exit(0);
            break;
        default:
            break;
        }
    }

    free(pArr);
    return 0;
}
