#include "menuItems.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST_NAME 11
#define MIDDLE_NAME 11
#define LAST_NAME 11
#define FULL_NAME 21
#define COMPANY_NAME 51
#define PHONE_NUMBER 21
#define EMAIL_ADDRESS 41
#define ADDRESS 51
#define BIRTHDAY_DAY 5
#define BIRTHDAY_MONTH 5
#define BIRTHDAY_YEAR 7
#define WEBSITE 21
#define NOTE 51

typedef struct Contact
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
} Contact;

void getString(char *str, int length);
void waitForKeyBoard(char *msg);
void clearKeyboardBuffer();
void title(const char *title);
void printTitle();
void printLine();
int mainMenu(const char *title, int numberItem, char *menuItems[]);
int subMenu(int numberItem, char *menuItems[]);
int inputNewContact(Contact *contact);
int displayAllContact();
void displayDetailsContact(Contact contact);
int displayFavouriteContact();
int searchAndDisplayDetailsContact(char *name, int choice);
int searchAllContact(char *name);
int updateContact(char *name, int choice);
int deleteContact(char *name, int choice);
int addFavouriteList(char *name, int choice);

int main(int argc, char const *argv[])
{
    int mainChoice;
    int subChoice;
    char name[FIRST_NAME];
    int choice;
    int checkSuccess;
    Contact *contact;
    do
    {
        mainChoice = mainMenu("--- VTC ACADEMY CONTACT MANAGEMENT ---", 5, mainMenuItems);
        switch (mainChoice)
        {
        case 1:
            title(" Search Contact");
            printf("Input Your Name Search: ");
            getString(name, 10);
            if (searchAllContact(name) == 0)
            {
                title(" Search Contact");
                printf("No contact found!\n");
                waitForKeyBoard("Press Any key to back main menu...");
                break;
            }
        re_no:
            printf("Input contact no to view details or input 0 to back main menu: ");
            scanf("%d", &choice);
            if (choice == 0)
            {
                break;
            }
            do
            {
                if (searchAndDisplayDetailsContact(name, choice) == 1)
                {
                    subChoice = subMenu(4, subMenuItems);
                    switch (subChoice)
                    {
                    case 1:
                        if (addFavouriteList(name, choice))
                        {
                            printf("Add Contact To Favourite List Complete!\n");
                        }
                        else
                        {
                            printf("Contact Already Exist In Favourite List!\n");
                        }
                        waitForKeyBoard("Press Any key to back sub menu...");
                        break;

                    case 2:
                        updateContact(name, choice);
                        waitForKeyBoard("Press Any key to back main menu...");
                        goto _break;
                        break;

                    case 3:
                        if (deleteContact(name, choice))
                        {
                            printf("Delete Contact Complete!\n");
                            waitForKeyBoard("Press Any key to back main menu...");
                            goto _break;
                        }
                        else
                        {
                            printf("Delete Contact Fail!\n");
                            waitForKeyBoard("Press Any key to back main menu...");
                            goto _break;
                        }
                        break;
                    }
                }
                else
                {
                    printf("No of contact is incorrect, please try again!\n");
                    goto re_no;
                    break;
                }
            } while (subChoice != 4);
        _break:
            break;

        case 2:
            title(" Create New Contact");
            contact = (Contact *)malloc(sizeof(Contact));
            if (inputNewContact(contact))
            {
                printf("======================================\n");
                printf("Create Contact Complete!\n");
            }
            else
            {
                printf("======================================\n");
                printf("Create Contact Fail!\n");
            }
            waitForKeyBoard("Press Any key to back main menu...");
            break;

        case 3:
            title(" Favourites Contact");
            displayFavouriteContact();
            waitForKeyBoard("Press Any key to back main menu...");
            break;

        case 4:
            title(" List Contact");
            displayAllContact();
            waitForKeyBoard("Press Any key to back main menu...");
            break;

        default:
            printf("Exit Application\n");
            break;
        }
    } while (mainChoice != 5);

    return 0;
}

int inputNewContact(Contact *contact)
{
    FILE *fp = fopen("contacts.dat", "ab+");
    if (fp == NULL)
    {
        printf("Error opened file\n");
        fclose(fp);
        return 0;
    }

    clearKeyboardBuffer();
    printf("Input ID: ");
    scanf("%d", &contact->id);

    printf("Input First Name: ");
    getString(contact->firstName, 10);

    printf("Input Middle Name: ");
    getString(contact->middleName, 10);

    printf("Input Last Name: ");
    getString(contact->lastName, 10);

    printf("Input Full Name: ");
    getString(contact->fullName, 20);

    // printf("Input Company: ");
    // getString(contact->companyName, 50);

    // printf("Input Phone: ");
    // getString(contact->phoneNumber, 20);

    // printf("Input Email: ");
    // getString(contact->emailAddress, 40);

    // printf("Input Address: ");
    // getString(contact->address, 50);

    // printf("Input Date Of Birth: ");
    // getString(contact->birthday_Day, 4);

    // printf("Input Month Of Birth: ");
    // getString(contact->birthday_Month, 4);

    // printf("Input Year Of Birth: ");
    // getString(contact->birthday_Year, 6);

    // printf("Input Company Website: ");
    // getString(contact->website, 20);

    // printf("Input Note: ");
    // getString(contact->note, 50);

    fwrite(contact, sizeof(Contact), 1, fp);

    fclose(fp);
    return 1;
}

int searchAllContact(char *name)
{
    FILE *fp = fopen("contacts.dat", "rb");
    if (fp == NULL)
    {
        printf("Error opened file\n");
        fclose(fp);
        return 0;
    }
    Contact contact;
    int found = 0;
    printTitle();
    while (fread(&contact, sizeof(Contact), 1, fp))
    {
        if (strcmp(contact.firstName, name) == 0)
        {
            found = 1;
            printf("| %-5d | %-26s |\n", contact.id, contact.fullName);
        }
    }
    printLine();
    fclose(fp);
    if (found == 0)
    {
        return 0;
    }
    return found;
}

int displayAllContact()
{
    FILE *fp = fopen("contacts.dat", "rb");
    if (fp == NULL)
    {
        printf("Empty list!\n");
        fclose(fp);
        return 0;
    }

    Contact contact;
    printTitle();
    while (fread(&contact, sizeof(Contact), 1, fp))
    {
        printf("| %-5d | %-26s |\n", contact.id, contact.fullName);
    }
    printLine();
    fclose(fp);
}

int searchAndDisplayDetailsContact(char *name, int choice)
{
    FILE *fp = fopen("contacts.dat", "rb");
    if (fp == NULL)
    {
        printf("Error opened file\n");
        fclose(fp);
        return 0;
    }

    Contact contact;
    while (fread(&contact, sizeof(Contact), 1, fp))
    {
        if (contact.id == choice && strcmp(contact.firstName, name) == 0)
        {
            title(" Contact Details");
            displayDetailsContact(contact);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int displayFavouriteContact()
{
    FILE *fp_1 = fopen("favourite-contacts.dat", "rb");
    if (fp_1 == NULL)
    {
        printf("Empty list!\n");
        fclose(fp_1);
        return 0;
    }
    Contact contact;
    printTitle();
    while (fread(&contact, sizeof(Contact), 1, fp_1))
    {
        printf("| %-5d | %-26s |\n", contact.id, contact.fullName);
    }
    printLine();
    fclose(fp_1);
}

int updateContact(char *name, int choice)
{
    FILE *fp = fopen("contacts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    FILE *fp_1 = fopen("favourite-contacts.dat", "rb");
    FILE *temp_1 = fopen("favourite-temp.dat", "wb");

    if (fp == NULL)
    {
        printf("Error opened file\n");
        fclose(fp);
        fclose(temp);
        fclose(fp_1);
        fclose(temp_1);
        return 0;
    }
    Contact contact;
    int found = 0;
    while (fread(&contact, sizeof(Contact), 1, fp))
    {
        if (strcmp(contact.firstName, name) == 0 && contact.id == choice)
        {
            clearKeyboardBuffer();
            printf("Input ID: ");
            scanf("%d", &contact.id);

            printf("Input First Name: ");
            getString(contact.firstName, 10);

            printf("Input Middle Name: ");
            getString(contact.middleName, 10);

            printf("Input Last Name: ");
            getString(contact.lastName, 10);

            printf("Input Full Name: ");
            getString(contact.fullName, 20);

            // printf("Input Company: ");
            // getString(contact.companyName, 50);

            // printf("Input Phone: ");
            // getString(contact.phoneNumber, 20);

            // printf("Input Email: ");
            // getString(contact.emailAddress, 40);

            // printf("Input Address: ");
            // getString(contact.address, 50);

            // printf("Input Date Of Birth: ");
            // getString(contact.birthday_Day, 4);

            // printf("Input Month Of Birth: ");
            // getString(contact.birthday_Month, 4);

            // printf("Input Year Of Birth: ");
            // getString(contact.birthday_Year, 6);

            // printf("Input Company Website: ");
            // getString(contact.website, 20);

            // printf("Input Note: ");
            // getString(contact.note, 50);

            fwrite(&contact, sizeof(Contact), 1, temp);
            fwrite(&contact, sizeof(Contact), 1, temp_1);
        }
        else
        {
            fwrite(&contact, sizeof(Contact), 1, temp);
        }
    }

    while (fread(&contact, sizeof(Contact), 1, fp_1))
    {
        if (strcmp(contact.firstName, name) == 0 && contact.id == choice)
        {
            found = 1;
        }
        else
        {
            fwrite(&contact, sizeof(Contact), 1, temp_1);
        }
    }

    fclose(fp);
    fclose(temp);
    fclose(fp_1);
    fclose(temp_1);

    remove("contacts.dat");
    rename("temp.dat", "contacts.dat");

    if (found == 1)
    {
        remove("favourite-contacts.dat");
        rename("favourite-temp.dat", "favourite-contacts.dat");
    }
    else
    {
        remove("favourite-temp.dat");
    }
    return 1;
}

int addFavouriteList(char *name, int choice)
{
    FILE *fp = fopen("contacts.dat", "rb");
    FILE *fp_1 = fopen("favourite-contacts.dat", "ab+");
    if (fp == NULL)
    {
        printf("Error opened file\n");
        fclose(fp);
        fclose(fp_1);
        return 0;
    }
    Contact contact;
    int found = 0;

    while (fread(&contact, sizeof(Contact), 1, fp_1))
    {
        if (strcmp(contact.firstName, name) == 0 && contact.id == choice)
        {
            found = 1;
        }
    }
    if (found == 1)
    {
        // Nếu contact cần add đã tồn tại trong favourite list
        fclose(fp);
        fclose(fp_1);
        return 0;
    }
    while (fread(&contact, sizeof(Contact), 1, fp))
    {
        if (strcmp(contact.firstName, name) == 0 && contact.id == choice)
        {
            fwrite(&contact, sizeof(Contact), 1, fp_1);
        }
    }
    fclose(fp);
    fclose(fp_1);
    return 1;
}

int deleteContact(char *name, int choice)
{
    FILE *fp = fopen("contacts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    FILE *fp_1 = fopen("favourite-contacts.dat", "rb");
    FILE *temp_1 = fopen("favourite-temp.dat", "wb");

    if (fp == NULL)
    {
        printf("Error opened file\n");
        fclose(fp);
        fclose(fp_1);
        fclose(temp);
        fclose(temp_1);
        return 0;
    }
    Contact contact;
    int found = 0, found_1 = 0;

    // Xóa khỏi list chính
    while (fread(&contact, sizeof(Contact), 1, fp))
    {
        if (strcmp(contact.firstName, name) == 0 && contact.id == choice)
        {
            found = 1;
        }
        else
        {
            fwrite(&contact, sizeof(Contact), 1, temp);
        }
    }

    // Xóa khỏi list favourite
    while (fread(&contact, sizeof(Contact), 1, fp_1))
    {
        if (strcmp(contact.firstName, name) == 0 && contact.id == choice)
        {
            found_1 = 1;
        }
        else
        {
            fwrite(&contact, sizeof(Contact), 1, temp_1);
        }
    }
    fclose(fp);
    fclose(fp_1);
    fclose(temp);
    fclose(temp_1);

    if (found == 1 && found_1 == 1) // Nếu contact có cả trong file lưu dữ liệu và file favourite
    {
        remove("contacts.dat");
        rename("temp.dat", "contacts.dat");

        remove("favourite-contacts.dat");
        rename("favourite-temp.dat", "favourite-contacts.dat");
        return 1;
    }
    else if (found == 1 && found_1 == 0) // Nếu contact có trong file lưu dữ liệu và không có trong file favourite
    {
        remove("contacts.dat");
        rename("temp.dat", "contacts.dat");

        remove("favourite-contacts.dat");
        rename("favourite-temp.dat", "favourite-contacts.dat");
        return 1;
    }
    else // Nếu contact không có trong file lưu dữ liệu và không có trong file favourite
    {
        remove("temp.dat");
        remove("favourite-temp.dat");
        return 0;
    }
}

void displayDetailsContact(Contact contact)
{
    printf("ID:          %d\n", contact.id);
    printf("First Name:  %s\n", contact.firstName);
    printf("Middle Name: %s\n", contact.middleName);
    printf("Last Name:   %s\n", contact.lastName);
    // printf("Company:     %s\n", contact.companyName);
    // printf("Phone:       %s\n", contact.phoneNumber);
    // printf("Email:       %s\n", contact.emailAddress);
    // printf("Address:     %s\n", contact.address);
    // printf("Birthday:    %s/%s/%s\n", contact.birthday_Day, contact.birthday_Month, contact.birthday_Year);
    // printf("Website:     %s\n", contact.website);
    // printf("Note:        %s\n", contact.note);
}

int mainMenu(const char *title, int numberItem, char *menuItems[])
{
    system("cls");
    printf("======================================\n");
    printf("%s\n", title);
    printf("======================================\n");
    for (int i = 0; i < numberItem; i++)
    {
        printf("%d. %s\n", i + 1, menuItems[i]);
    }
    printf("======================================\n");
    int choice;
    do
    {
        printf(" #Your choice: ");
        scanf("%d", &choice);
        printf("======================================\n");
    } while (choice <= 0 || choice > numberItem);
    return choice;
}

int subMenu(int numberItem, char *menuItems[])
{
    printf("======================================\n");
    for (int i = 0; i < numberItem; i++)
    {
        printf("%d. %s\n", i + 1, menuItems[i]);
    }
    printf("======================================\n");
    int choice;
    do
    {
        printf(" #Your choice: ");
        scanf("%d", &choice);
        printf("======================================\n");
    } while (choice <= 0 || choice > numberItem);
    return choice;
}

void getString(char *str, int length)
{
    clearKeyboardBuffer();
    fgets(str, length, stdin);
    str[strlen(str) - 1] = '\0';
    clearKeyboardBuffer();
}

void waitForKeyBoard(char *msg)
{
    printf("%s", msg);
    clearKeyboardBuffer();
    getchar();
}

void clearKeyboardBuffer()
{
    fseek(stdin, 0, SEEK_END);
    fflush(stdin);
}

void title(const char *title)
{
    system("cls");
    printf("======================================\n");
    printf("%s\n", title);
    printf("======================================\n");
}

void printTitle()
{
    printLine();
    printf("| %-5s | %-26s |\n", "No.", "Full Name");
    printLine();
}

void printLine()
{
    printf("+-%-5s-+-%-26s-+\n", "-----", "--------------------------");
}
