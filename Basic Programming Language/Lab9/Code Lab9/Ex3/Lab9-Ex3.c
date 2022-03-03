#include <stdio.h>
#include <string.h>

// void SapXepTen(struct SinhVien SV[], int n);
// void ChuanHoa(struct SinhVien SV[], int n);
// void TimKiem(struct SinhVien SV[], int n);

int main()
{
    char ten[30][30];
    int n, key, id;
    printf("n = ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("sinh vien thu %d\n", i);
        for (int j = 1; j <= 1; j++)
        {
            fflush(stdin);
            printf("Ten: ");
            scanf("%s", ten[i][j]);
        }
    }
    printf("No");
    printf("       Name\n");
    printf("---------------\n");

    for (int i = 1; i <= n; i++)
    {
        printf("sinh vien thu %d\n", i);
        for (int j = 1; j <= 1; j++)
        {
            printf("%s", ten[j]);
        }
    }
    
    //     while (1)
    //     {
    //         printf("\n");
    //         printf("           MENU\n");
    //         printf("===========================\n");
    //         printf("1. Add Student Name\n");
    //         printf("2. Search Student Name\n");
    //         printf("3. Sort Student Names\n");
    //         printf("4. Normarlize Student Names\n"); // chuẩn hóa
    //         printf("5. Exit\n");
    //         printf("===========================\n");
    //     NhapLai:
    //         printf("Choose Option: ");
    //         scanf("%d", &key);
    //         switch (key)
    //         {
    //         case 1:
    //             printf("1. Add Student Name\n");
    //             break;

    //         case 2:
    //             printf("2. Search Student Name\n");
    //             break;

    //         case 3:
    //             printf("3. Sort Student Names\n");
    //             SapXepTen(SV, n);
    //             printf("Danh sach sinh vien\n");
    //             for (int i = 1; i <= n; i++)
    //             {

    //             }
    //             break;

    //         case 4:
    //             printf("4. Normarlize Student Names\n");
    //             break;

    //         case 5:
    //             printf("5. Exit\n");
    //             return 0;

    //         default:
    //             printf("Re-entering\n");
    //             goto NhapLai;
    //             break;
    //         }
    //     }
    //     return 0;
}

// void SapXepTen(struct SinhVien SV[], int n)
// {
//     char tenSV1[30];
//     char tenSV2[30];
//     for (int i = 0; i < n - 1; i++)
//     {
//         strcpy(tenSV1, SV[i].ten);
//         for (int j = i + 1; j < n; j++)
//         {
//             strcpy(tenSV2, SV[j].ten);
//             if (strcmp(strupr(tenSV1), strupr(tenSV2)) > 0)
//             {
//                 struct SinhVien temp = SV[i];
//                 SV[i] = SV[j];
//                 SV[j] = temp;
//             }
//         }
//     }
// }

// void ChuanHoa(struct SinhVien SV[], int n)
// {
//     n = strlen(SV);
//     for (int i = 0; i < n; i++)
//     {
//         // if (SV[i] == ' ' && SV[i + 1] == ' ')
//         {

//         }

//     }

// }