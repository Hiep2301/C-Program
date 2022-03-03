#include <stdio.h>
#include <conio.h>
#include <time.h>
int main()
{
    time_t t; // time_t là kiểu dữ liệu trong thư viện <time.h>
    t = time(NULL);
    struct tm tm = *localtime(&t);
    /*
        localtime trả về thời gian cục bộ của hệ thống đượcc định nghĩa ở thư viện <time.h>. Nó chấp nhận một tham số đại diện cho con trỏ đến đối tượng time_t và trả về một con trỏ đến một đối tượng struct tm
    */
    printf("Current Date: %d-%d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("Current Time: %d:%d:%d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
    return 0;
}