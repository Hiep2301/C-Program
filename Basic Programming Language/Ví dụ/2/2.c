#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Nguyên mẫu hàm
void checkbalance(char *);
void transfermoney();
void display(char *);
void person(char *);
void login();
void loginSuccess();
void account();
void accountcreated();
void afterlogin();
void logout();

// Creating a structure to store data of the user
struct pass
{
    char username[50];
    char fname[20];
    char lname[20];
};

// Structure to keep track of amount transfer
struct money
{
    char userpersonfrom[50];
    char usernameto[50];
    long int money1;
};

struct userpass
{
    char password[50];
};

// Driver Code
int main()
{
    int i, a, b, choice;
    int passwordlength;

    // Creating a Main menu for the user
    system("cls");
    printf("WELCOME TO BANK ACCOUNT SYSTEM\n");
    printf("*********************************\n");
    printf("1. CREATE A BANK ACCOUNT\n");
    printf("2. ALREADY A USER? SIGN IN\n");
    printf("3. EXIT\n");
    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        account();
        break;
    case 2:
        login();
        break;
    case 3:
        exit(0);
        break;

        getch();
    }
}

// Function to create accounts of users
void account()
{
    char password[20];
    char ch;
    FILE *fp;
    struct pass u1;

    // Opening file to write data of a user
    fp = fopen("username.txt", "ab");

    // Inputs
    system("cls");
    printf("\n!!!!!CREATE ACCOUNT!!!!!");

    printf("\nFIRST NAME: ");
    scanf("%s", &u1.fname);

    printf("\nLAST NAME: ");
    scanf("%s", &u1.lname);

    printf("\n\nUSERNAME: ");
    scanf("%s", &u1.username);

    printf("\n\nPASSWORD: ");
    // Taking password in the form of stars
    for (int i = 0; i < 50; i++)
    {
        ch = getch();
        if (ch != 13)
        {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }

    // Writing to the file
    fwrite(&u1, sizeof(u1), 1, fp);

    // Closing file
    fclose(fp);

    // Calling another function after successful creation of account
    accountcreated();
}

// Successful account creation
void accountcreated()
{
    system("cls");
    printf("PLEASE WAIT....\nYOUR DATA IS PROCESSING....");
    for (int i = 0; i < 200000000; i++)
    {
        i++;
        i--;
    }
    printf("\nACCOUNT CREATED SUCCESSFULLY....");
    printf("\nPress enter to login");
    getch();
    login();
}

// Login function to check the username of the user
void login()
{
    char username[50];
    char password[50];
    char ch;
    FILE *fp;
    struct pass u1;

    system("cls");
    // Opening file of user data
    fp = fopen("username.txt", "rb");
    if (fp == NULL)
    {
        printf("ERROR IN OPENING FILE");
    }

    printf("\nACCOUNT LOGIN ");
    printf("\n==== LOG IN ====");

    // Take input
    printf("\nUSERNAME: ");
    scanf("%s", &username);

    printf("\nPASSWORD: ");
    // Input the password
    for (int i = 0; i < 50; i++)
    {
        ch = getch();
        if (ch != 13)
        {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }

    // Checking if username exists in the file or not
    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if (strcmp(username, u1.username) == 0)
        {
            loginSuccess();
            display(username);
        }
    }

    // Closing the file
    fclose(fp);
}

// Redirect after successful login
void loginSuccess()
{
    system("cls");
    printf("\nFetching account details.....\n");
    for (int i = 0; i < 20000; i++)
    {
        i++;
        i--;
    }
    printf("\nLOGIN SUCCESSFUL....");
    printf("\nPress enter to continue");
    getch();
}

// Display function to show the data of the user on screen
void display(char username1[])
{
    system("cls");
    FILE *fp;
    int choice, i;
    fp = fopen("username.txt", "rb");
    struct pass u1;

    if (fp == NULL)
    {
        printf("error in opening file");
    }

    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if (strcmp(username1, u1.username) == 0)
        {
            printf("\nWELCOME, %s %s", u1.fname, u1.lname);
            printf("\n..........................");
            printf("\n==== YOUR ACCOUNT INFO ====");
            printf("\n***************************");
            printf("\nNAME..%s %s", u1.fname, u1.lname);
        }
    }

    fclose(fp);

    // Menu to perform different actions by user
    printf("\n1. CHECK BALANCE");
    printf("\n2. TRANSFER MONEY");
    printf("\n3. LOG OUT");
    printf("\n4. EXIT");
    printf("\nENTER YOUR CHOICES: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        checkbalance(username1);
        break;

    case 2:
        transfermoney();
        break;

    case 3:
        logout();
        login();
        break;

    case 4:
        exit(0);
        break;
    }
}

// Function to transfer money from one user to another
void transfermoney()
{
    int i, j;
    FILE *fm, *fp;
    struct pass u1;
    struct money m1;
    char usernamet[20];
    char usernamep[20];
    system("cls");

    // Opening file in read mode to read user's username
    fp = fopen("username.txt", "rb");

    // Creating a another file to write amount along with username to which amount is going to be transfered
    fm = fopen("money.txt", "ab");

    printf("\n---- TRANSFER MONEY ----");
    printf("\n========================");

    printf("\nFROM (your username).. ");
    scanf("%s", &usernamet);

    printf("\nTO (username of person)..");
    scanf("%s", &usernamep);

    // Checking for username if it is present in file or not
    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if (strcmp(usernamep, u1.username) == 0)
        {
            strcpy(m1.usernameto, u1.username);
            strcpy(m1.userpersonfrom, usernamet);
        }
    }

    // Taking amount input
    printf("\nENTER THE AMOUNT TO BE TRANSFERED..");
    scanf("%d", &m1.money1);

    // Writing to the file
    fwrite(&m1, sizeof(m1), 1, fm);
    printf("\n--------------------------------------------------"
           "--------------------------------------------");
    printf("\n--------------------------------------------------"
           "--------------------------------------------");
    printf("\ntransfering amount, Please wait..\n");

    for (i = 0; i < 70; i++)
    {
        for (j = 0; j < 1200000; j++)
        {
            j++;
            j--;
        }
        printf("*");
    }

    printf("\nAMOUNT SUCCESSFULLY TRANSFERED....");
    getch();

    // Close the files
    fclose(fp);
    fclose(fm);

    // Function to return to the home screen
    display(usernamet);
}

// Function to check balance in users account
void checkbalance(char username2[])
{
    system("cls");
    FILE *fm;
    struct money m1;
    char ch;
    int i = 1, summoney = 0;

    // Opening amount file record
    fm = fopen("money.txt", "rb");

    int k = 5, l = 10;
    int m = 30, n = 10;
    int u = 60, v = 10;

    printf("\n==== BALANCE DASHBOARD ====");
    printf("\n***************************");

    // Reading username to fetch the correct record
    while (fread(&m1, sizeof(m1), 1, fm))
    {
        if (strcmp(username2, m1.usernameto) == 0)
        {
            printf("\n%d. %s - %d", i, m1.userpersonfrom, m1.money1);
            i++;
            // Adding and finding total money
            summoney = summoney + m1.money1;
        }
    }

    printf("\nTOTAL AMOUNT: %d$", summoney);
    getch();

    // Closing file after reading it
    fclose(fm);
    display(username2);
}

// Logout function to bring user to the login screen
void logout()
{
    int i, j;
    system("cls");
    printf("please wait, logging out");

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 25000000; j++)
        {
            i++;
            i--;
        }
        printf(".");
    }

    printf("\nSign out successfully..\n");

    printf("\npress any key to continue..");

    getch();
}
