#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct BookStore
{
    char title[50];
    char author[50];
    double price;
    double isbn;
} Book;

Book InputBook();
void PrintBook(Book book[], int count);
void MenuBook();

int main(int argc, char const *argv[])
{
    int n;
    printf("Nhap so luong sach: ");
    scanf("%d", &n);
    Book book[n];
    for (int i = 0; i < n; i++)
    {
        printf("Thong tin sach thu %d\n", i + 1);
        book[i] = InputBook();
        printf("\n");
    }

    int key;
    while (1)
    {
        MenuBook();
    NhapLai:
        printf("Enter Choice: ");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            printf("1. Insert Book\n");
            break;

        case 2:
            printf("2. Search Book By ISBN\n");
            break;

        case 3:
            printf("3. Delete Book By ISBN\n");
            break;

        case 4:
            printf("4. Sort Book List\n");
            break;

        case 5:
            printf("5. Display All Book\n");
            printf("=====================\n");
            printf("Danh sach\n");
            printf("=====================\n");
            PrintBook(book, n);
            break;

        case 6:
            printf("6. Exit\n");
            return 0;

        default:
            printf("Re-entering\n");
            goto NhapLai;
            break;
        }
    }

    return 0;
}

Book InputBook()
{
    Book book;

    printf("Ten sach: ");
    fflush(stdin);
    scanf("%s", &book.title);

    printf("Ten tac gia: ");
    fflush(stdin);
    scanf("%s", &book.author);

    printf("Gia ban: ");
    scanf("%lf", &book.price);

    return book;
}

void PrintBook(Book book[], int count)
{
    srand(time(NULL));
    for (int i = 0; i < count; i++)
    {
        book[i].isbn = rand() % 100000;
    }
    for (int i = 0; i < count; i++)
    {
        printf("Thong tin sach thu %d\n", i + 1);
        printf("Ten sach: %s\n", book[i].title);
        printf("Ten tac gia: %s\n", book[i].author);
        printf("Ma ISBN: %.0lf\n", book[i].isbn);
        printf("Gia ban: %.0lf\n", book[i].price);
        printf("---------------------------\n");
    }
}

void MenuBook()
{
    printf("\n=========================\n");
    printf("Bookstore Demo\n");
    printf("=========================\n");
    printf("1. Insert Book\n");
    printf("2. Search Book By ISBN\n");
    printf("3. Delete Book By ISBN\n");
    printf("4. Sort Book List\n");
    printf("5. Display All Book\n");
    printf("6. Exit\n");
    printf("=========================\n");
}