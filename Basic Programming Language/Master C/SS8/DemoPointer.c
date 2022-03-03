#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num, num2;
    //Khai báo biến con trỏ pNum.
    int *pNum;

    //&num lấy ra địa chỉ vùng nhớ của biến num
    //Lấy địa chỉ này gán cho biến pNum
    //Lúc này, ta gọi pNum là con trỏ của num
    pNum = &num;

    printf("num = ");
    scanf("%d", pNum);

    //In ra giá trị của biến num
    printf("num = %d\n", num);
    printf("num = %d\n", *pNum);
    
    printf("--------------------\n");

    //In ra địa chỉ vùng nhớ của biến num
    printf("Dia chi vung nho cua bien num: %x\n", &num);
    printf("Dia chi vung nho cua bien num: %x\n", pNum);
    printf("Dia chi vung nho cua bien num: %x\n", &num2);
    
    pNum++;

    printf("pNum = %x\n", pNum);

    
    return 0;
}
