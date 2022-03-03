#include <stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    //Khai báo mảng có kích thước là 100 phần tử.
    int arr[100];
    //Biến đếm count để đếm số phần tử trong mảng.
    int count = 0;
    //Biến lưu vị trí của phần tử
    int position;

    int choice;

    while (1)
    {
        printf("\n---------------------------\n");
        printf("Working with array\n");
        printf("1. Add\n");
        printf("2. Update\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            //Thêm phần tử vào mảng.
            printf("Them phan tu tai arr[%d] = ", count);
            scanf("%d", &arr[count]);
            count++;
            break;
        case 2:
            //Sửa giá trị của phần tử.
            printf("Nhap vi tri cua phan tu can sua: ");
            scanf("%d", &position);
            if (position < 0 && position >= count)
            {
                printf("Vi tri nay khong co trong mang");
            }
            else
            {
                printf("arr[%d] = ", position);
                scanf("%d", &arr[position]);
            }
            break;
        case 3:
            //Chèn phần tử vào mảng.
            printf("Nhap vi tri cua phan tu can chen: ");
            scanf("%d", &position);
            //Mang day roi, ko chen them dc nua
            if (count == 100)
            {
                printf("Mang day roi, ko chen dc nua!");
            }

            //Nếu position < 0 thì chèn vào đầu mảng
            if (position < 0)
            {
                position = 0;
            }
            //Nếu position >= count thì chèn vào cuối mảng.
            else if (position >= count)
            {
                position = count;
            }

            //Dịch chuyển mảng, tạo khoảng trống để chèn phần tử.
            for (int i = count; i > position; i--)
            {
                arr[i] = arr[i - 1];
            }

            //Chèn phần tử vào mảng.
            printf("Nhap gia tri muon chen vao mang: ");
            scanf("%d", &arr[position]);

            //Tăng số phần tử trong mảng.
            ++count;

            break;
        case 4:
            //Xóa phần tử trong mảng.
            printf("Nhap vi tri cua phan tu can xoa: ");
            scanf("%d", &position);
            if (position < 0 && position >= count)
            {
                printf("Vi tri nay khong co trong mang");
            }
            else
            {
                //Xóa phần tử khỏi mảng
                for (int i = position; i < count - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                count--;
            }
            break;
        case 5:
            //Hiển thị mảng.
            printf("Cac phan tu cua mang arr:\n");
            for (int i = 0; i < count; i++)
            {
                printf("%d\t", arr[i]);
            }
            
            break;
        case 0:
            exit(0);
        break;
        default:
            printf("Nhap sai! Moi nhap lai!!!");
            break;
        }
    }

    return 0;
}
