#include <stdio.h>
char upper(char kiTu);

char upper(char kiTu)
{
    char chuHoa = kiTu - 32;
    return chuHoa;
}

int main(int argc, char const *argv[])
{
    char c[10];
    for (int i = 0; i < 10; i++)
    {
        fflush(stdin);
        printf("c[%d] = ", i);
        scanf("%c", &c[i]);
        upper(c[i]);
        printf("%c -> %c\n", c[i], upper(c[i]));
    }

    return 0;
}
