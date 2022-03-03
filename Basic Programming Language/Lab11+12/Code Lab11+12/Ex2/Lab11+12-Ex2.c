#include <stdio.h>
#include <string.h>

struct Product
{
    char ProductName[50];
    char Quantity[15];
    double SellingPrice;
};

struct Product InputProduct();
void PrintProduct(struct Product product[]);

int main(int argc, char const *argv[])
{
    struct Product product[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Thong tin san pham thu %d\n", i + 1);
        product[i] = InputProduct();
        printf("\n");
    }
    printf("Danh sach san pham\n");
    PrintProduct(product);
    return 0;
}

struct Product InputProduct()
{
    struct Product product;

    printf("Ten san pham: ");
    fflush(stdin);
    scanf("%s", &product.ProductName);

    printf("Chat luong san pham: ");
    fflush(stdin);
    scanf("%s", &product.Quantity);

    printf("Gia ban: ");
    scanf("%lf", &product.SellingPrice);

    return product;
}

void PrintProduct(struct Product product[])
{
    printf("No.||  Ten SP                || Chat luong   ||  Gia ban\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d  ||  %-20s  ||  %-10s  ||  %0.1lf\n", i, product[i].ProductName, product[i].Quantity, product[i].SellingPrice);
    }
}
