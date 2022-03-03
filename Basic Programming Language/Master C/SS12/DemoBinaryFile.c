#include<stdio.h>

typedef struct
{
    char name[50];
    int age;
}Student;

int writeStudentToFile(Student *std, int count, char *fileName);
int main(int argc, char const *argv[])
{

    Student std1[5] = 
    {
        {"Dao Van Duc", 28},
        {"Dao Van Duc", 28},
        {"Dao Van Duc", 28},
        {"Dao Van Duc", 28},
        {"Dao Van Duc", 28},
    };

    

    /* code */
    return 0;
}

int writeStudentToFile(Student *std, int count, char *fileName){
    //std đại diện cho mảng các Student
    //count là số lượng phần tử của mảng
    //fileName là tên file mà dữ liệu sẽ dc ghi vào!
    FILE *pFile;

    int result = 0;

    pFile = fopen(fileName, "a+b");
    //Ghi số lượng phần tử của mảng vào đầu file
    fwrite(&count, sizeof(int), 1, pFile);

    //Ghi toàn bộ mảng vào file
    fwrite(std, sizeof(Student), count, pFile);

    fclose(pFile);

    result = 1;
    return result;
}
