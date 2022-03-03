#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

struct user
{
    char pass[20];
    char username[20];
    char fname[20];
    char lname[20];
};

int verify();
int menu();
void createaccount();
int login();
// int createaccount();
FILE *fp;
struct user u, U;
int choice;
char fname[20], lname[20], uname[20], pss[20], C;

int main()
{
    while (1)
    {
        switch (menu())
        {
        case 1:
            createaccount();
            break;

        case 2:
            verify();
            break;

        case 3:
            login();
            break;

        case 4:
            exit(0);
        default:
            printf("Invalid Choice! ");
            break;
        }
    }

    return 0;
}
int menu()
{
    int ch;
    system("@cls||clear");
    printf("[1] : Create Account:  \n");
    printf("[2] : Verify Details:  \n");
    printf("[3] : Login:  \n");
    printf("[4] : Exit:  \n");
    printf("   Enter your choice :  ");
    scanf("%d", &ch);
    return ch;
}
int verify()
{
    FILE *fp;
    struct user u;
    system("cls");
    printf("    Your Details Are..\n\n");
    /// Reading from file
    fp = fopen("username.bin", "rb");
    if (fp == NULL)
    {
        printf("\"File not found\"");
        return 1;
    }
    while (fread(&u, sizeof(struct user), 1, fp))
    {
        printf("\n    Name: %s %s \n", u.fname, u.lname);
        printf("\n    Username: %s\n\n    Password = %s \n\n", u.username, u.pass);
        printf("-------------------------------\n");
    }
    fclose(fp);
    printf("Press any key to continue...");
    getch();
    system("cls");
}

void createaccount()
{
    struct user U;
    FILE *fp;
    system("cls");
    puts("<--<<Create Account>>-->");
    printf("\n\n");
    printf("    Enter First Name: ");
    fflush(stdin);
    gets(U.fname);
    printf("\n");
    printf("    Enter Last Name: ");
    gets(U.lname);
    printf("\n");
    printf("    Enter Username: ");
    scanf("%s", U.username);
    printf("\n");
    printf("    Enter Password: ");
    scanf("%s", U.pass);
    fp = fopen("username.bin", "ab+");
    if (fp == NULL)
    {
        printf("\nError opened file\n");
        exit(1);
    }
    fwrite(&U, sizeof(struct user), 1, fp);
    fclose(fp);
    system("cls");
    printf(" Account Created Successfully.");
    printf("Press any key to continue...");
    getch();
    system("cls");
}
int login()
{
    char uname[20], pss[20];
    FILE *fp;
    struct user u;
    system("cls");
    printf("<--<<LOGIN TO YOUR ACCOUNT>>->\n\n");
    printf(" Enter Username: ");
    scanf("%s", uname);
    printf("\n");
    printf(" Enter Password: ");
    scanf("%s", pss);
    /// Reading from file
    fp = fopen("username.bin", "rb");
    if (fp == NULL)
    {
        printf("\"File not found\"");
        return 1;
    }
    while (fread(&u, sizeof(u), 1, fp))
    {
        if (strcmp(uname, u.username) == 0 && strcmp(pss, u.pass) == 0)
        {
            printf("\n Username And Password is Correct.\n");
            printf(" Press any key to continue...");
            getch();
            printf("\nWelcome %s %s ", u.fname, u.lname);
            getch();
        }
        // else
        // {
        //     printf("\n Username And Password is Incorrect.\n\n");
        //     printf(" Press any key to continue...");
        //     getch();
        // }
    }
    fclose(fp);
    system("cls");
}
