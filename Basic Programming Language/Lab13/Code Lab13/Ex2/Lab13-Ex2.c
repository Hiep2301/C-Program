#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *test = fopen("test.txt", "w+");
    if (test == NULL)
    {
        printf("Error opened file");
    }

    char content[100];
    printf("Input contents: ");
    fflush(stdin);
    gets(content);
    strupr(content);
    fprintf(test, "%s", content);
    fclose(test);

    fscanf(test, "%s", content);
    printf("Content after upper: %s", content);

    return 0;
}
