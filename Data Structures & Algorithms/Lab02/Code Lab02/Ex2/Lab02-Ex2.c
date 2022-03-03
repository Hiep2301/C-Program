#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book
{
    char isbn[15];
    char title[51];
} Books;

typedef struct Node
{
    Books book;
    struct Node *next;
} Node;

void getString(char *str, int length);
void clearKeyBoardBuffer();
void waitEnterPressed(char *msg);
void printTitle();
void printLine();
int menu(const char *title, int menuItemCount, char *menuItem[]);
int inputListBook(Node *listBook);
int addToFirst(Node **firstElement, Node *newBook);
int addToLast(Node **firstElement, Node *newBook);
void displayListBook(Node *firstElement);
void displayBook(Books book);
Node *searchBook(Node *firstElement, char *isbn);
int deleteBook(Node **firstElement, char *isbn);

int main(int argc, char const *argv[])
{
    char *mainMenu[] = {"Insert Book", "Search Book By ISBN", "Delete Book by ISBN", "Display All Books", "Exit"};
    Node *firstElement = NULL;
    Node *nodeBook;
    char isbn[15];
    int mainChoice;
    do
    {
        mainChoice = menu("Bookstore Demo", 5, mainMenu);
        clearKeyBoardBuffer();
        switch (mainChoice)
        {
        case 1:
            nodeBook = (Node *)malloc(sizeof(Node));
            inputListBook(nodeBook);
            // addToFirst(&firstElement, nodeBook);
            addToLast(&firstElement, nodeBook);
            waitEnterPressed("Press Enter to go main menu...");
            break;
        case 2:
            printf("Input ISBN: ");
            getString(isbn, 14);
            nodeBook = searchBook(firstElement, isbn);
            if (nodeBook == NULL)
            {
                printf("No book found\n");
                waitEnterPressed("Press Enter to go main menu...");
            }
            else
            {
                printTitle();
                displayBook(nodeBook->book);
                printLine();
                waitEnterPressed("Press Enter to go main menu...");
            }
            break;
        case 3:
            printf("Input ISBN: ");
            getString(isbn, 14);
            if (deleteBook(&firstElement, isbn))
            {
                printf("Delete book with isbn: %s complete!\n", isbn);
            }
            else
            {
                printf("Not found book with isbn: %s\n", isbn);
            }
            waitEnterPressed("Press Enter to go main menu...");
            break;
        case 4:
            displayListBook(firstElement);
            waitEnterPressed("Press Enter to go main menu...");
            break;
        default:
            printf("Exit\n");
            break;
        }
    } while (mainChoice != 5);

    return 0;
}

int inputListBook(Node *listBook)
{
    clearKeyBoardBuffer();
    printf("Input Book isbn: ");
    getString(listBook->book.isbn, 14);
    printf("Input Book title: ");
    getString(listBook->book.title, 50);
    return 1; // trả về 1 là tạo thành công
}

int addToFirst(Node **firstElement, Node *newBook)
{
    if (firstElement == NULL)
    {
        return 0;
    }
    newBook->next = *firstElement;
    *firstElement = newBook;
    return 1;
}

int addToLast(Node **firstElement, Node *newBook)
{
    // Node đầu tiên không có giá trị thì trả về 0 và đóng hàm
    if (firstElement == NULL)
    {
        return 0;
    }
    newBook->next = NULL; // Cho một node mới có con trỏ trỏ đến NULL
    if (*firstElement == NULL) 
    {
        *firstElement = newBook; // Nếu                      
    }
    else
    {
        Node *tmpFirstElement = *firstElement;
        while (tmpFirstElement->next != NULL) // Lặp đến khi con trỏ trỏ đến NULL
        {
            tmpFirstElement = tmpFirstElement->next;
        }
        tmpFirstElement->next = newBook;
    }
    return 1;
}

void displayListBook(Node *firstElement)
{
    Node *current = firstElement;
    printTitle();
    while (current != NULL)
    {
        displayBook(current->book);
        current = current->next;
    }
    printLine();
}

void displayBook(Books book)
{
    printf("| %-14s | %-26s |\n", book.isbn, book.title);
}

void printLine()
{
    printf("+-%-14s-+-%-26s-+\n", "--------------", "--------------------------");
}

void printTitle()
{
    printLine();
    printf("| %-14s | %-26s |\n", "ISBN", "Title");
    printLine();
}

Node *searchBook(Node *firstElement, char *isbn)
{
    Node *p = firstElement;
    for (; p != NULL; p = p->next)
    {
        if (strcmp(p->book.isbn, isbn) == 0)
        {
            break;
        }
    }
    return p;
}

int deleteBook(Node **firstElement, char *isbn)
{
    Node *current = *firstElement;
    Node *previous = *firstElement;
    while (current != NULL)
    {
        if (strcmp(current->book.isbn, isbn) == 0)
        {
            break;
        }
        previous = current;
        current = current->next;
    }
    if (current != NULL)
    {
        if (current == previous)
        {
            *firstElement = current->next;
        }
        else
        {
            previous->next = current->next;
        }
        free(current);
        return 1;
    }
    return 0;
}

void getString(char *str, int length)
{
    clearKeyBoardBuffer();
    fgets(str, length, stdin);
    str[strlen(str) - 1] = '\0';
    clearKeyBoardBuffer();
}

void waitEnterPressed(char *msg)
{
    printf("%s", msg);
    clearKeyBoardBuffer();
    getchar();
}

int menu(const char *title, int menuItemCount, char *menuItem[])
{
    int choice;
    system("cls");
    printf("==============================\n");
    printf("%s\n", title);
    printf("==============================\n");
    for (int i = 0; i < menuItemCount; i++)
    {
        printf("%d. %s\n", i + 1, menuItem[i]);
    }
    printf("==============================\n");
    do
    {
        printf("Your choice: ");
        clearKeyBoardBuffer();
        scanf("%d", &choice);
    } while (choice <= 0 || choice > menuItemCount);
    return choice;
}

void clearKeyBoardBuffer()
{
    // clear keyboard buffer on UNIX
    fseek(stdin, 0, SEEK_END);
    // clear keyboard buffer on Windows
    fflush(stdin);
}