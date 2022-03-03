#include <stdio.h>

int main(int argc, char const *argv[])
{
    short int si;
    printf("Kich thuoc vung nho cua bien kieu short int la: %d bytes\n", sizeof(si));

    unsigned short int usi;
    printf("Kich thuoc vung nho cua bien kieu unsigned short int la: %d bytes\n", sizeof(usi));

    unsigned int ui;
    printf("Kich thuoc vung nho cua bien kieu unsigned int la: %d bytes\n", sizeof(ui));

    int i;
    printf("Kich thuoc vung nho cua bien kieu int la: %d bytes\n", sizeof(i));

    long int li;
    printf("Kich thuoc vung nho cua bien kieu long int la: %d bytes\n", sizeof(li));

    unsigned long int uli;
    printf("Kich thuoc vung nho cua bien kieu unsigned long int la: %d bytes\n", sizeof(uli));

    char c;
    printf("Kich thuoc vung nho cua bien kieu char la: %d bytes\n", sizeof(c));

    signed char sc;
    printf("Kich thuoc vung nho cua bien kieu signed char la: %d bytes\n", sizeof(sc));

    unsigned char uc;
    printf("Kich thuoc vung nho cua bien kieu unsigned char la: %d bytes\n", sizeof(uc));

    float f;
    printf("Kich thuoc vung nho cua bien kieu float la: %d bytes\n", sizeof(f));
    
    double d;
    printf("Kich thuoc vung nho cua bien kieu double la: %d bytes", sizeof(d));
    return 0;
}
