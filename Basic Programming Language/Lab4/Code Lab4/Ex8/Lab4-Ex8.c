#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num1, num2;
    printf("num1 = ");
	scanf("%d", &num1);
    printf("num2 = ");
	scanf("%d", &num2);

	fflush(stdin);
	char c;
	printf("Choose operator: ");
	scanf("%c", &c);
	switch (c) {
		case '+':
		printf("num1 + num2 = %d", num1 + num2);
		break;

		case '-':
		printf("num1 - num2 = %d", num1 - num2);
		break;

		case '*':
		printf("num1 * num2 = %d", num1 * num2);
		break;

		case '/':
		printf("num1 / num2 = %.2f", (float)num1 / num2);
		break;

		case '%':
		printf("num1 %% num2 = %d", num1 % num2);
		break;
	}
    return 0;
}
