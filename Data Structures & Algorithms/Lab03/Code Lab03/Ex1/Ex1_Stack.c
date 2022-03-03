// Stack sử dụng mảng
#include <stdio.h>
#define MAX 50

typedef struct Stack
{
    int data[MAX];
    int top;
} Stack;

int push(Stack *stack, int value);
int pop(Stack *stack, int *topValue);

int main(int argc, char const *argv[])
{
    Stack stack;
    stack.top = -1;

    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    printf("push: ");
    for (int i = 0; i <= stack.top; i++)
    {
        printf("%d | ", stack.data[i]);
    }
    printf("\n");
    printf("pop: ");
    int topValue;
    while (pop(&stack, &topValue)) // Truyền tham chiếu là địa chỉ của topValue
    {
        printf("%d | ", topValue); // In ra giá trị tại địa chỉ của phần tử trên top
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

int pop(Stack *stack, int *topValue)
{
    if (stack->top < 0)
    {
        return 0;
    }
    // Mảng là một con trỏ
    *topValue = stack->data[stack->top];  // Ở đây mảng trỏ đến phần tử trên top để gán cho con trỏ topValue (topValue có giá trị là địa chỉ của phần tử top)
    stack->top--;
    return 1;
}