#include "menuItems.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST_NAME 7
#define MIDDLE_NAME 7
#define LAST_NAME 7
#define FULL_NAME 21
#define COMPANY_NAME 51
#define PHONE_NUMBER 11
#define EMAIL_ADDRESS 21
#define ADDRESS 51
#define BIRTHDAY_DAY 5
#define BIRTHDAY_MONTH 5
#define BIRTHDAY_YEAR 7
#define WEBSITE 21
#define NOTE 51

typedef struct Contacts
{
    int id;
    char firstName[FIRST_NAME];
    char middleName[MIDDLE_NAME];
    char lastName[LAST_NAME];
    char fullName[FULL_NAME];
    char companyName[COMPANY_NAME];
    char phoneNumber[PHONE_NUMBER];
    char emailAddress[EMAIL_ADDRESS];
    char address[ADDRESS];
    char birthday_Day[BIRTHDAY_DAY];
    char birthday_Month[BIRTHDAY_MONTH];
    char birthday_Year[BIRTHDAY_YEAR];
    char website[WEBSITE];
    char note[NOTE];
} Contacts;

typedef struct linkedList
{
    Contacts contact;
    struct linkedList *next;
} linkedList;

void getString(char *str, int length);
void clearKeyBoardBuffer();
void printLine();
void printTitle();
void waitForKeyboard(char *msg);
int count(linkedList *firstContact);
int mainMenu(const char *title, int numberItems, char *menuItems[]);
int subMenu(int numberItems, char *menuItems[]);
void title(const char *title);
int inputNewContact(linkedList *inputContact);
int addContactToList(linkedList **firstContact, linkedList *newContact);
void displayAllContactList(linkedList *firstContact);
void displayAllContactSearch(linkedList *firstContact);
linkedList *searchAllContact(linkedList *firstContact, char *name);
void displayDetailsContact(linkedList *firstContact, int noListContact);
int deleteContact(linkedList **firstContact, int choice);

int writeToFile(linkedList *firstContact);
int readFromFile(linkedList **firstContact);

int main(int argc, char const *argv[])
{
    int mainMenuChoice;
    int subMenuChoice;
    linkedList *firstContact = NULL; // khởi tạo node đầu tiên chưa có giá trị
    linkedList *nodeContact;
    char name[11];
    int choice;
    readFromFile(&firstContact);
    do
    {
        mainMenuChoice = mainMenu("--- VTC ACADEMY CONTACT MANAGEMENT ---", 5, mainMenuItems);
        clearKeyBoardBuffer();
        switch (mainMenuChoice)
        {
        case 1:
            title(" Search Contact");
            printf("Input Your Name Search: ");
            getString(name, 10);
            printf("\n");
            nodeContact = searchAllContact(firstContact, name);
            if (nodeContact == NULL)
            {
                printf("No Contact found\n");
                waitForKeyboard("Press any key to back main menu...");
                break;
            }
            printf("\n");
            printf("Input contact no to view details or input 0 to back main menu: ");
            scanf("%d", &choice);
            if (choice == 0)
            {
                break;
            }
            displayDetailsContact(firstContact, choice);
            subMenuChoice = subMenu(4, subMenuItems);
            clearKeyBoardBuffer();
            switch (subMenuChoice)
            {
            case 1:
                printf("Add Favourites\n");
                break;
            case 2:
                printf("Update\n");
                break;
            case 3:
                if (deleteContact(&firstContact, choice))
                {
                    printf("Delete complete!\n");
                }
                else
                {
                    printf("Delete fail!\n");
                }
                waitForKeyboard("Press any key to back main menu...");
                break;
            default:
                printf("Back to main menu\n");
                break;
            }
            break;

        case 2:
            title(" Create New Contact");
            nodeContact = (linkedList *)malloc(sizeof(linkedList));
            inputNewContact(nodeContact);
            printf("======================================\n\n");
            if (addContactToList(&firstContact, nodeContact))
            {
                printf("Create contact complete!\n\n");
            }
            else
            {
                printf("Create contact fail!\n\n");
            }
            waitForKeyboard("Press any key to back main menu...");
            break;

        case 3:
            title(" Contact Details");
            waitForKeyboard("Press any key to back main menu...");
            break;

        case 4:
            title(" List Contacts");
            printf("Number of contacts: %d\n", count(firstContact));
            if (firstContact != NULL)
            {
                displayAllContactList(firstContact);
            }
            else
            {
                printf("Empty list\n");
            }
            waitForKeyboard("Press any key to back main menu...");
            break;

        default:
            printf("Exit Application");
            break;
        }
    } while (mainMenuChoice != 5);
    writeToFile(firstContact);
    return 0;
}

int mainMenu(const char *title, int numberItems, char *menuItems[])
{
    system("cls");
    printf("======================================\n");
    printf("%s\n", title);
    printf("======================================\n");
    for (int i = 0; i < numberItems; i++)
    {
        printf("  %d. %s\n", i + 1, menuItems[i]);
    }
    printf("======================================\n");
    int choice;
    do
    {
        printf(" #Your choice: ");
        clearKeyBoardBuffer();
        scanf("%d", &choice);
    } while (choice <= 0 || choice > numberItems);
    printf("======================================\n");
    return choice;
}

void title(const char *title)
{
    system("cls");
    printf("======================================\n");
    printf("%s\n", title);
    printf("======================================\n");
}

int subMenu(int numberItems, char *menuItems[])
{
    printf("======================================\n");
    for (int i = 0; i < numberItems; i++)
    {
        printf("%d. %s\n", i + 1, menuItems[i]);
    }
    printf("======================================\n");
    int choice;
    do
    {
        printf(" #Your choice: ");
        clearKeyBoardBuffer();
        scanf("%d", &choice);
    } while (choice <= 0 || choice > numberItems);
}

int inputNewContact(linkedList *inputContact)
{
    clearKeyBoardBuffer();
    printf("Input ID: ");
    scanf("%d", &inputContact->contact.id);

    printf("Input First Name: ");
    getString(inputContact->contact.firstName, 6);

    printf("Input Middle Name: ");
    getString(inputContact->contact.middleName, 6);

    printf("Input Last Name: ");
    getString(inputContact->contact.lastName, 6);

    printf("Input Full Name: ");
    getString(inputContact->contact.fullName, 20);

    return 1;
}

void displayDetailsContact(linkedList *firstContact, int noListContact)
{
    title(" Contact Details");
    for (; firstContact != NULL; firstContact = firstContact->next)
    {
        if (firstContact->contact.id == noListContact)
        {
            printf("ID:          %d\n", firstContact->contact.id);
            printf("First Name:  %s\n", firstContact->contact.firstName);
            printf("Middle Name: %s\n", firstContact->contact.middleName);
            printf("Last Name:   %s\n", firstContact->contact.lastName);
        }
    }
}

linkedList *searchAllContact(linkedList *firstContact, char *name)
{
    linkedList *p = firstContact;
    int found = 0;
    if (p == NULL)
    {
        return NULL;
    }
    else
    {
        printTitle();
        while (p != NULL)
        {
            if (strcmp(name, p->contact.firstName) == 0)
            {
                found++;
                displayAllContactSearch(p);
            }
            p = p->next;
        }
        printLine();
        if (found == 0)
        {
            return NULL;
        }
    }
}

void displayAllContactSearch(linkedList *firstContact)
{
    printf("| %-5d | %-26s |\n", firstContact->contact.id, firstContact->contact.fullName);
}

void displayAllContactList(linkedList *firstContact)
{
    printTitle();
    for (; firstContact != NULL; firstContact = firstContact->next)
    {
        printf("| %-5d | %-26s |\n", firstContact->contact.id, firstContact->contact.fullName);
    }
    printLine();
}

int addContactToList(linkedList **firstContact, linkedList *newContact)
{
    if (firstContact == NULL)
    {
        return 0;
    }
    newContact->next = NULL;
    if (*firstContact == NULL) // khi node khởi tạo bằng NULL
    {
        *firstContact = newContact; // node mới bằng node đầu tiên (node khởi tạo và chưa có giá trị)
    }
    else
    {
        linkedList *tmpFirstContact = *firstContact; // tạo một biến tạm là node đầu tiên để trỏ đến các node khác
        while (tmpFirstContact->next != NULL)        // con trỏ của biến tạm trỏ đến NULL thì dừng
        {
            tmpFirstContact = tmpFirstContact->next;
        }
        tmpFirstContact->next = newContact; // nếu con trỏ của biến tạm trỏ đến NULL thì gán bằng node mới
    }
    return 1;
}

int deleteContact(linkedList **firstContact, int choice)
{
    linkedList *current = *firstContact;
    linkedList *previous = *firstContact;
    while (current != NULL)
    {
        if (current->contact.id == choice)
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
            *firstContact = current->next;
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

int count(linkedList *firstContact)
{
    linkedList *p = firstContact;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void printLine()
{
    printf("+-%-5s-+-%-26s-+\n", "-----", "--------------------------");
}

void printTitle()
{
    printLine();
    printf("| %-5s | %-26s |\n", "No.", "Full Name");
    printLine();
}

void getString(char *str, int length)
{
    clearKeyBoardBuffer();
    fgets(str, length, stdin);
    str[strlen(str) - 1] = '\0';
    clearKeyBoardBuffer();
}

void waitForKeyboard(char *msg)
{
    printf("%s", msg);
    clearKeyBoardBuffer();
    getchar();
}

void clearKeyBoardBuffer()
{
    fseek(stdin, 0, SEEK_END);
    fflush(stdin);
}

int writeToFile(linkedList *firstContact)
{
    if (firstContact == NULL)
    {
        return 0;
    }
    FILE *fp = fopen("contacts.dat", "wb");
    if (fp == NULL)
    {
        return 0;
    }
    linkedList *p = firstContact;
    while (p != NULL)
    {
        // Đọc đến node nào thì ghi node đó vào file
        fwrite(p, sizeof(linkedList), 1, fp);
        p = p->next;
    }
    fclose(fp);
    return 1;
}

int readFromFile(linkedList **firstContact)
{
    if (firstContact == NULL)
    {
        return 0;
    }
    FILE *fp = fopen("contacts.dat", "rb");
    if (fp == NULL)
    {
        return 0;
    }
    linkedList *p;
    while (!feof(fp)) // Đọc đến cuối file thì dừng
    {
        p = (linkedList *)malloc(sizeof(linkedList)); // Khởi tạo một node trong danh sách để có thể lưu trữ node lấy từ trong file
        if (fread(p, sizeof(linkedList), 1, fp) > 0)
        {
            addContactToList(firstContact, p); // Thêm node từ file vào danh sách
        }
    }
    fclose(fp);
    return 1;
}