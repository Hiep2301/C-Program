#include <stdio.h>
int main(int argc, char const *argv[])
{
    int kilometers, miles;
    printf("kilometers = ");
    scanf("%d", &kilometers);
    printf("miles = ");
    scanf("%d", &miles);
    double conversion_factor = 0.621371192;
    printf("%d kilometers to miles = %lf\n", kilometers, kilometers * conversion_factor);
    printf("%d miles to kilometers = %lf\n", miles, kilometers / conversion_factor);
    return 0;
}
