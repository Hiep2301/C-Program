#include<stdio.h>



int main(int argc, char const *argv[])
{
    //Khai báo con trỏ file.
    FILE *file;

    file = fopen("demo.txt", "a+");
    if(file != NULL)
    {
        // fprintf()
        fputs("Test", file);
    }
    fclose(file);

    file = fopen("demo.txt", "r");
    char buffer[250];

    if(file != NULL)
    {
        fgets(buffer, 250, file);
    }

    printf("Du lieu doc tu file: %s", buffer);
    return 0;
}
