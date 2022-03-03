#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("==========================\n");
    printf("Bookstore Demo\n");
    printf("==========================\n");
    printf("1. Insert Book\n");
    printf("2. Search Book By ISBN\n");
    printf("3. Delete Book By ISBN\n");
    printf("4. Sort Book List\n");
    printf("5. Display All Book\n");
    printf("6. Exit\n");
    printf("==========================\n");
    
    int choice;
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("1. Insert Book");
            break;
        case 2:
            printf("2. Search Book By ISBN");
            break;
        case 3:
            printf("3. Delete Book By ISBN");
            break;
        case 4:
            printf("4. Sort Book List");
            break;
        case 5:
            printf("5. Display All Book");
            break;
        case 6:
            printf("6. Exit");
            break;
        }
    } while (choice != 6);
    return 0;
}
