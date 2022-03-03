#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num;

    printf("Nhap mot so nguyen bat ki: ");
    scanf("%d", &num);

    if ((num % 2) == 0)
    {
        printf("%d la so chan!", num);
    }    
    else
    {
        printf("%d la so le!", num);
    }

    return 0;
}

/*
    if(biểu_thức_điều_kiện)
	{
		//Thực hiện khi biểu thức đk trả về true
	}
	else
	{
		//Thực hiện khi biểu thức đk trả về false
	} 
*/
