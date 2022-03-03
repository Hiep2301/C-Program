#include<stdio.h>

int main(int argc, char const *argv[])
{
    double diemToan, diemTiengAnh;

    printf("Nhap diem toan: ");
    scanf("%lf", &diemToan);
    printf("Nhap diem tieng Anh: ");
    scanf("%lf", &diemTiengAnh);

    double diemTrungBinh = (diemToan + diemTiengAnh) / 2;

    if(diemTrungBinh >= 7)
    {
        if(diemToan >= 7)
        {
            printf("Nen thi khoi A");
        }
        else if (diemTiengAnh >= 7)
        {
            printf("Nen thi khoi D1");
        } 
    }
    else
    {
        printf("Nen...di ngu! :v");
    }
    
    return 0;
}
