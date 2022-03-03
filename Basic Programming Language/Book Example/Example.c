#include <stdio.h>
#include <string.h>

typedef struct
{
    char isbn[15];
    char title[51];
    char author[51];
    float price;
} Books;

void printBook(Books book);
Books getBook();
void getString(char *str, int length);
void printLine();
void printTitle();
// Hàm để đọc mảng Books từ file
int readBooksFromFile(Books *lstBooks, int *pCount, const char *fileName);
// Hàm để viết mảng Books vào file
int writeBooksToFile(Books *lstBooks, int count, const char *fileName);

int main(int argc, char const *argv[])
{
    Books books[100];
    int i, count = 0;

    //Đọc dữ liệu từ file
    readBooksFromFile(books, &count, "books.dat");

    printf("Input book %d: \n", count + 1);
    books[count] = getBook();
    count++;

    printTitle();
    for (i = 0; i < count; i++)
    {
        printBook(books[i]);
    }
    printLine();

    //Viết dữ liệu vào file
    writeBooksToFile(books, count, "books.dat");
    
    return 0;
}

Books getBook()
{
    Books book;
    printf("Input Book ISBN: ");
    getString(book.isbn, 14);
    printf("Input Book title: ");
    getString(book.title, 50);
    printf("Input Book author: ");
    getString(book.author, 50);
    printf("Input Book price: ");
    scanf("%f", &book.price);
    return book;
}

void printBook(Books book)
{
    printf("| %-14s | %-26s | %-20s | %6.2f |\n", book.isbn, book.title, book.author, book.price);
}

void printLine()
{
    printf("+-%-14s-+-%-26s-+-%-20s-+-%-6s-+\n", "--------------", "--------------------------", "--------------------", "------");
}

void printTitle()
{
    printLine();
    printf("| %-14s | %-26s | %-20s | %-6s |\n", "ISBN", "Title", "Author", "Price");
    printLine();
}

void getString(char *str, int length)
{
    // clear keyboard buffer on UNIX
    fseek(stdin, 0, SEEK_END);
    // clear keyboard buffer on Windows
    fflush(stdin);
    // Input String
    fgets(str, length, stdin);
    str[strlen(str) - 1] = '\0';
    // clear keyboard buffer on UNIX
    fseek(stdin, 0, SEEK_END);
    // clear keyboard buffer on Windows
    fflush(stdin);
}

int readBooksFromFile(Books *lstBooks, int *pCount, const char *fileName)
{
    FILE *f = fopen(fileName, "rb");
    int result = 0;
    if (f != NULL)
    {
        fread(pCount, sizeof(int), 1, f);
        if (*pCount > 0)
        {
            fread(lstBooks, sizeof(Books), *pCount, f);
            result = 1;
        }
        fclose(f);
    }
    return result;
}

int writeBooksToFile(Books *lstBooks, int count, const char *fileName)
{
    FILE *f = fopen(fileName, "wb");
    int result = 0;
    if (f != NULL)
    {
        //Viết count vào file
        fwrite(&count, sizeof(int), 1, f);
        //Viết lstBooks vào file
        fwrite(lstBooks, sizeof(Books), count, f);
        fclose(f);
        result = 1;
    }
    return result;
}
