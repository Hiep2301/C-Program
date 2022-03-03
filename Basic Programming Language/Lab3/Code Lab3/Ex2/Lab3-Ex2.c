#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int x, y;
    printf("x = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);
    int exp = pow(x, 3) + 3*pow(x, 2) + 3*x*pow(y, 2) + pow(y, 3);
    // exp = x*x*x + 3*x*x + 3*x*y*y + y*y*y
    printf("exp = %d", exp);
    return 0;
}
