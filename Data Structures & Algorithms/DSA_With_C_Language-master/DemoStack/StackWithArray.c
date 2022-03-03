#include<stdio.h>

struct Stack
{
    int data[10];
    int maxIndex;
    int topIndex;
};
//Them phan tu vao dinh stack
int push(int value, struct Stack *s);
//Lay phan tu ra khoi dinh stack
int pop(int *topValue, struct Stack *s);

int main(int argc, char const *argv[])
{
    //Khoi tao stack
    struct Stack myIntStack;
    myIntStack.maxIndex = 9;
    myIntStack.topIndex = -1;

    //Them phan tu vao stack
    push(1, &myIntStack);
    push(2, &myIntStack);
    push(3, &myIntStack);
    push(4, &myIntStack);
    push(5, &myIntStack);
    push(6, &myIntStack);

    //Lay va in gia tri cua cac phan tu trong stack
    int topValue;
    while (pop(&topValue, &myIntStack))
    {
        printf("%d | ", topValue);
    }
    
    return 0;
}

int push(int value, struct Stack *s)
{
    //B1: Kiem tra xem stack no full chua
    if(s->topIndex == s->maxIndex)
    {
        //Full roi thi ko them vao dc
        return 0;
    }

    //Tang topIndex len 1 don vi
    s->topIndex += 1;

    //Gan gia tri vao vi tri topIndex cua mang
    s->data[s->topIndex] = value;

    //Them thanh cong, return 1
    return 1;
}


int pop(int *topValue, struct Stack *s)
{
    //Kiem tra xem stack rong hay ko
    if(s->topIndex == -1)
    {
        //stack rong, ko lay ra dc.
        return 0;
    }

    //Lay gia tri o dinh stack
    *topValue = s->data[s->topIndex];
    //Giam topIndex di 1 don vi
    s->topIndex -= 1;

    //Pop thanh cong, return 1
    return 1;
}