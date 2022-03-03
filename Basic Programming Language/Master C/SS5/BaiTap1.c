#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    while (1)
    {
        int n;
        printf("---------------------------------------------------\n");
        printf("Nhap mot so nguyen duong bat ki:\n");
        printf("n = ");
        scanf("%d", &n);

        printf("--------------------------------------------------\n");
        printf("1. Tong cac so chan trong khoang 1 -> n: \n");
        printf("2. Tong cac so nguyen to trong khoang 1 -> n: \n");
        printf("3. Ket thuc\n");
        printf("--------------------------------------------------\n");
        int choice;
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        int tongSoChan = 0;
        int tongSoNguyenTo = 0;
        switch (choice)
        {
        case 1:
            for (int i = 1; i <= n; i++)
            {
                if (i % 2 == 0)
                {
                    tongSoChan += i; //Tuong duong tongSoChan = tongSoChan + n
                }
            }
            printf("Tong so chan trong khoang tu 1 -> %d = %d\n", n, tongSoChan);
            break;
        case 2:

            for (int i = 2; i <= n; i++)
            {
                int count = 0;
                //Vòng lặp kiểm tra xem i có phải là số nguyên tố hay ko
                for (int j = 2; j <= sqrt(i); j++)
                {
                    if (i % j == 0)
                    {
                        count++;
                    }
                }

                //Nếu i là số nguyên tố thì cộng i vào tongSoNguyenTo
                if (count == 0)
                {
                    //printf("%d\t", i);
                    tongSoNguyenTo += i;
                }
            }

            printf("tongSoNguyenTo = %d\n", tongSoNguyenTo + 1);
            break;
        case 3:
            printf("Byby!! :v ");
            exit(0); //Thoát chương trình
            break;
        }
    }

    return 0;
}
