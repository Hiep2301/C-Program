#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    float a[3][6];
    srand(time(NULL));

    /* RANDOM ĐIỂM */
    for (int i = 0; i < 3; i++)
    {
        printf("The mark of student %d:\n", i + 1);
        for (int j = 0; j < 6; j++)
        {
            a[i][j] = rand() % 101;
        }
        printf("\n");
    }
    
    /* NHẬP ĐIỂM TỪ BÀN PHÍM */
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("The mark of student %d:\n", i + 1);
    //     for (int j = 0; j < 6; j++)
    //     {
    //         printf("a[%d][%d] = ", i, j);
    //         scanf("%f", &a[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("Student    |     CF    |    BPL    |    OOP    |    NPF    |   RDBMS   |    AVG   |  GRADE");
    printf("\n");
    printf("------------------------------------------------------------------------------------------");
    printf("\n");
    int sum = 0, count = 0;
    for (int i = 0; i < 3; i++)
    {
        printf("Student %d", i + 1);
        for (int j = 0; j < 6; j++)
        {
            printf("  |%7.1f  ", a[i][j]);
            count++;
            sum += a[i][j];
        }
        printf(" |");
        float TBC = (float)sum / count;
        if (TBC >= 90)
        {
            printf("    A");
        }
        else if (TBC >= 80)
        {
            printf("    B");
        }
        else if (TBC >= 65)
        {
            printf("    C");
        }
        else if (TBC >= 50)
        {
            printf("    D");
        }
        else
        {
            printf("    F");
        }
        printf("\n");
        sum = 0;
        count = 0;
    }
    return 0;
}
