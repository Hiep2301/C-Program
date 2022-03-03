#include<stdio.h>

// struct HocSinh
// {
//     char tenHocSinh[100];
// };


struct LopHoc
{
    char name[20];
    union 
    {
        char tenSinhVien[100];
    };
    
};


int main(int argc, char const *argv[])
{
    struct LopHoc PF14;
    // PF14.
    return 0;
}
