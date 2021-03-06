#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int value;
    struct stack *next;
};

typedef struct stack Stack;

// function declaration
int push(Stack **first, int newValue);
int pop(Stack **first);
Stack *convertToBinary(int decimalNumber);
void printAndRemoveStack(Stack *binaryStack);

int main(int count, const char *args[])
{
    int decimal;
    printf("Input an integer number: ");
    scanf("%d", &decimal);
    Stack *binaryStack = convertToBinary(decimal);
    printAndRemoveStack(binaryStack);
    return 0;
}

Stack *convertToBinary(int decimalNumber)
{
    Stack *stack = NULL;
    while (decimalNumber > 0)
    {
        push(&stack, decimalNumber % 2);
        decimalNumber /= 2; // lấy nguyên
    }
    return stack;
}

void printAndRemoveStack(Stack *binaryStack)
{
    printf("Binary number: ");
    int i = 1;
    while (binaryStack != NULL)
    {
        if (i % 4 == 0)
        {
            printf(" ");
        }
        printf("%d", pop(&binaryStack));
        i++;
    }
    printf("\n");
}

int push(Stack **first, int newValue) // Thêm vào đầu
{
    if (first == NULL && *first == NULL)
    {
        return 0;
    }
    Stack *newElement = (Stack *)malloc(sizeof(Stack));
    newElement->value = newValue;
    newElement->next = *first;
    *first = newElement;
    return 1;
}

int pop(Stack **first) // Xóa phần tử đầu Stack
{
    Stack *firstElement = *first;
    *first = firstElement->next; // Gán phần tử sau nó cho first
    int iValue = firstElement->value;
    free(firstElement);
    firstElement = NULL;
    return iValue;
}

/*
    Ví dụ:
        Decimal: 19
                    nguyên      dư
        (19)/2	    9	        1
        (9)/2	    4	        1
        (4)/2	    2	        0
        (2)/2	    1	        0
        (1)/2	    0	        1
        = 10011 (lấy dư từ dưới lên cũng như pop ra từ trên xuống)
                                
                               (Start)    
        push: 1 -> 0 -> 0 -> 1 -> 1 -> NULL (Thêm vào đầu)

        pop : 1 -> 0 -> 0 -> 1 -> 1 -> NULL (Xóa từ đầu đến cuối)
*/
