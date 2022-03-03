#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char str1[] = "Dao";
    char str2[] = "Duc";
    char str3[20];
    //Hàm nối chuỗi str2 vào cuối chuỗi str1
    strcat(str1, str2);
    printf("%s\n", str1);

    //Hàm so sánh chuỗi
    // int result = strcmp(str1, str2);
    // printf("result = %d\n", result);

    //Hàm copy chuỗi str1 vào chuỗi str3
    strcpy(str3, str1);
    printf("str3: %s\n", str3);

    //Trả về độ dài của 1 chuỗi.
    char xxx[] = "Thay Duc dep trai vo doi!!!";
    printf("Do dai cua chuoi xxx la: %d\n", strlen(xxx));

    //Trả về vị trí của 1 kí tự trong chuỗi
    char *pa = strchr(str1, 'x');

    if(pa == NULL)
    {
        printf("Deu co!");
    }
    else
    {
        /* code */
    }
    
    return 0;
}
