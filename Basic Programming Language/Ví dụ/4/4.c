#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct web
{
    char name[30], pass[30];
} w;

int n;
int i;

void login(void);

void reg(void);

int main()
{
    system("@cls||clear");
    printf("\n\n\n\n\n\t\t\t\tWELCOME TO MY WEBSITE");
    printf("\n\t\t\t\t=====================");
    printf("\n\n\n\n\t\t\tPress Enter to proceed...!!");
    if (getch() == 13)
    {
        system("@cls||clear");
    }
XY:
    printf("\n\n\n\t\t\t1. LOGIN\t\t2. REGISTER");
    printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        system("@cls||clear");
        login();
        break;
    case 2:
        system("@cls||clear");
        reg();
        break;
    default:
        printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice");
        if (getch() == 13)
        {
            system("@cls||clear");
        }
        goto XY;
    }
    return 0;
}

void reg()
{
    FILE *fp;
    char c, checker[30];
    int z = 0;
    fp = fopen("Web_reg.bin", "ab+");
    printf("\n\n\t\t\t\tWELCOME TO REGISTER ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^");

    printf("\n\n\t\t\t\t  ENTER USERNAME: ");
    scanf("%s", checker);
    while (!feof(fp))
    {
        fread(&w, sizeof(struct web), 1, fp);
        if (strcmp(checker, w.name) == 0)
        {
            printf("\n\n\t\t\tUSERNAME ALREADY EXISTS");
            reg();
        }
        else
        {
            strcpy(w.name, checker);
            break;
        }
    }
    printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
    while ((c = getch()) != 13)
    {
        w.pass[z++] = c;
        printf("%c", '*');
    }
    fwrite(&w, sizeof(struct web), 1, fp);
    fclose(fp);
    printf("\n\n\tPress enter if you agree with Username and Password");
    if ((c = getch()) == 13)
    {
        system("@cls||clear");
        printf("\n\n\t\tYou are successfully registered");
        printf("\n\n\t\tTry login your account??\n\n\t\t  ");
        printf("&gt; PRESS 1 FOR YES\n\n\t\t  &gt; PRESS 2 FOR NO\n\n\t\t\t\t");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            system("@cls||clear");
            login();
            break;
        case 2:
            system("@cls||clear");
            printf("\n\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING");
            break;
        }
    }
    getch();
}

void login()
{
    FILE *fp;
    char c, name[30], pass[30];
    int z = 0;
    int checku, checkp;
    fp = fopen("Web_reg.bin", "rb");
    printf("\n\n\t\t\t\tWELCOME TO LOG IN ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");

    printf("\n\n\t\t\t\t  ENTER USERNAME: ");
    scanf("%s", name);
    printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
    while ((c = getch()) != 13)
    {
        pass[z++] = c;
        printf("%c", '*');
    }
    pass[z] = '\0';
    while (!feof(fp))
    {
        fread(&w, sizeof(struct web), 1, fp);
        checku = strcmp(name, w.name);
        checkp = strcmp(pass, w.pass);
        if (checku == 0 && checkp == 0)
        {
            system("@cls||clear");
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY");
            break;
        }
        else if (checku == 0 && checkp != 0)
        {
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??", name);
            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");
            if (getch() == 'y' || getch() == 'Y')
                login();
        }
        else if (checku != 0)
        {
            printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");
            if (getch() == 13)
            {
                system("@cls||clear");
            }
            reg();
        }
    }
    getch();
}