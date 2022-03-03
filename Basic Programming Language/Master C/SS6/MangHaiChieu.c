#include <stdio.h>

int main(int argc, char const *argv[])
{
    //Khai báo và gán giá trị cho mảng 2 chiều
    //Mảng này có 3 hàng và 4 cột.
    //Tức là nó là tập hợp của 3 mảng 1 chiều, mỗi mảng có 4 phần tử
    int ary[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    //Dùng vòng lặp for lồng nhau để duyệt mảng 2 chiều
    //Vòng for ngoài duyệt từng hàng
    for (int i = 0; i < 3; i++)
    {
        //Vòng for duyệt từng cột
        for (int j = 0; j < 4; j++)
        {
            printf("ary[%d][%d] = %d\n", i, j, ary[i][j]);
        }   
    }
    return 0;
}
