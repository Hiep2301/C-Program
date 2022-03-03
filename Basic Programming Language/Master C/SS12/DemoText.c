#include<stdio.h>

int main(int argc, char const *argv[])
{
    //Khai báo con trỏ file
    
    // printf("Nhap chuoi bat ki: ");
    // char name[1000];
    // gets(name);
    // //Ghi dữ liệu vào file
    // //feof(pFile);
    // //fputs(name, pFile);
    // fprintf(pFile, "%s", name);
    // fclose(pFile);
    
    FILE *pFile;

    pFile = fopen("demo.txt", "r");
    char arr[1000];
    //fgets(arr, 100, pFile);
    while (!feof(pFile))
    {
        fgets(arr, 1000, (FILE *)pFile);
        printf("%s", arr);
    }
    fclose(pFile);

    return 0;
}
