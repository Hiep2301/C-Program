#include<stdio.h>

int main(int argc, char const *argv[])
{
    char str[] = "Dao Van Duc";
    char name[50];
    // printf("%s", str);
    printf("Nhap ten bat ki: ");
    // scanf("%[^\n]s", name);
    // printf("Xin chao %s", name);
    gets(name);
    printf("Xin chao %s", name);

    return 0;
}
