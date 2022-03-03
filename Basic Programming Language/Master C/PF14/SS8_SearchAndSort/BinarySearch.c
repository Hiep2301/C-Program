#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[1000];

    for (int i = 0; i < 1000; i++)
    {
        arr[i] = i + 3;
    }

    for (int i = 0; i < 1000; i++)
    {
        printf("%5d\t", arr[i]);
    }
    
    printf("\nNhap so can tim: ");
    int num;
    scanf("%d", &num);

    int low = 0; //index của phần tử đầu
    int hight = 999; //index của phần tử cuối
    int mid; //index của phần tử ở giữa
    int fIndex = -1; //Index của giá trị cần tìm trong mảng
    int step = 0; //Đếm số bước thực hiện tìm kiếm
    while (low <= hight)
    {
        step++;
        //Nếu num = giá trị tại vị trí low thì gán fIndex = low
        //và thoát vòng lặp, kết thúc tìm kiếm
        if(arr[low] == num)
        {
            fIndex = low;
            break;
        }
        //Nếu num = giá trị tại vị trí hight thì gán fIndex = low
        //và thoát vòng lặp, kết thúc tìm kiếm
        if(arr[hight] == num)
        {
            fIndex = hight;
            break;
        }

        mid = (hight + low) / 2;

        if(num == arr[mid])
        {
            fIndex = mid;
            break;
        }
        else if (num > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            hight = mid - 1;
        }
    }
    
    if (fIndex != -1)
    {
        printf("Tim thay %d tai vi tri %d trong mang sau %d buoc.", num, fIndex, step);
    }
    else
    {
        printf("So ban vua nhap khong ton tai trong mang");
    }
    
    
    return 0;
}
