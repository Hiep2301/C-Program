#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char name[50];
    printf("Nhap ten: ");
    gets(name);

    for (int i = 0; i < strlen(name); i++)
    {
        if(name[i] >= 'a' && name[i] <= 'z')
        {
            name[i] = name[i] - 32;
        }
    }
    
    printf("Upper case name: %s", name);

    for (int i = 0; i < strlen(name); i++)
    {
        if(name[i] != ' ')
        {
            name[i] = name[i] + 32;
        }
    }

    printf("\nLower case name: %s", name);
    return 0;
}
