#include <stdio.h>
#define MAX 100

typedef struct Stack
{
    int data[MAX];
    int top;
} Stack;

int push(Stack *stack, int value);
int pop(Stack *stack);

int main(int argc, char const *argv[])
{
    Stack stack;
    stack.top = -1;
    int num;
    printf("Input a decimal number: ");
    scanf("%d", &num);
    while (num != 0)
    {
        push(&stack, num % 2);
        num /= 2;
    }
    printf("Binary number: ");
    while (stack.top >= 0)
    {
        printf("%d", pop(&stack));
    }

    return 0;
}

int push(Stack *stack, int value)
{
    if (stack->top == MAX - 1)
    {
        return 0;
    }
    stack->data[stack->top += 1] = value;
    return 1;
}

int pop(Stack *stack)
{
    int topValue;
    topValue = stack->data[stack->top];
    stack->top--;
    return topValue;
}
