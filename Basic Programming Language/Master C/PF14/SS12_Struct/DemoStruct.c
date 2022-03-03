#include<stdio.h>
#include<stdlib.h>

//Khai báo struct
typedef struct 
{
    char first_name[20];
    char middle_name[20];
    char last_name[20];
    char company[50];
    char phone[15];
    char email[30];
    char address[100];
    char birth_day[15];
    char website[100];
    char note[150];
}Contact;

Contact CreateNewContact();
void PrintContactInfo(Contact aContact);

int main(int argc, char const *argv[])
{
    //Khai báo biến, sử dụng struct đã định nghĩa ở trên
    // struct Contact ct1, *pCt1;
    // pCt1 = &ct1;
    // struct Contact ct2;

    // ct1 = CreateNewContact();

    // printf("Full name: %s %s %s\n", pCt1->first_name, pCt1->middle_name, pCt1->last_name);
    
    // printf("\nContact: \n");
    // PrintContactInfo(ct1);

    //Mảng các contact
    // struct Contact listContacts[2];

    // for (int i = 0; i < 2; i++)
    // {
    //     listContacts[i] = CreateNewContact();
    // }

    // for (int i = 0; i < 2; i++)
    // {
    //     PrintContactInfo(listContacts[i]);
    // }
    
    //Demo cấp phát động với con trỏ struct

    Contact *pContact;

    pContact = malloc(sizeof(Contact));


    printf("First name: ");
    gets(pContact->first_name);

    printf("FirstName: %s", pContact->first_name);

    return 0;
}

Contact CreateNewContact()
{
    Contact newContact;

    printf("First name   : ");
    gets(newContact.first_name);
    printf("Middle name  : ");
    gets(newContact.middle_name);
    printf("Last name    : ");
    gets(newContact.last_name);
    printf("Company      : ");
    gets(newContact.company);
    printf("Phone        : ");
    gets(newContact.phone);
    printf("Email        : ");
    gets(newContact.email);
    printf("Address      : ");
    gets(newContact.address);
    printf("Birth day    : ");
    gets(newContact.birth_day);
    printf("Website      : ");
    gets(newContact.website);
    printf("Note         : ");
    gets(newContact.note);

    return newContact;
}

void PrintContactInfo(Contact aContact)
{
    printf("Full name: %s %s %s\n", aContact.first_name, aContact.middle_name, aContact.last_name);
}