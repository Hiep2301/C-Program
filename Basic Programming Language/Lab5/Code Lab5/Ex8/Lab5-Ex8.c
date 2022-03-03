#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    for (int num = 1; num < n; num++)
    {
        int count = 0;
        for(int i = 2; i <= sqrt(num); i++){
            if(num % i == 0) {
                count++;
            }
        }
        if(count == 0 && num > 1) {
            printf("%d ", num);
        }
    }
    return 0;
}
