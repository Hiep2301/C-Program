#include<stdio.h>

struct Queue
{
    int data[10];
    int maxIndex;
    int front;
    int rear;
};

//Them vao queue
int enqueue(int value, struct Queue *q);
//Lay gia tri ra khoi queue
int dequeue(int *value, struct Queue *q);

int main(int argc, char const *argv[])
{
    struct Queue myIntQueue;
    myIntQueue.maxIndex = 9;
    myIntQueue.front = 0;
    myIntQueue.rear = -1;


    enqueue(1, &myIntQueue);
    enqueue(2, &myIntQueue);
    enqueue(3, &myIntQueue);
    enqueue(4, &myIntQueue);
    enqueue(5, &myIntQueue);

    int frontValue;
    while (dequeue(&frontValue, &myIntQueue))
    {
        printf("%d | ", frontValue);
    }
    

    return 0;
}

int enqueue(int value, struct Queue *q)
{

    if(q->rear == q->maxIndex)
    {
        if (q->front == 0)
        {
            //Queue day, ko them dc nua
            return 0;
        }

        int newRear = q->rear - q->front;

        for (int i = 0; i < newRear; i++)
        {
            q->data[i] = q->data[i + q->front];
        }
        
        q->front = 0;
        q->rear = newRear;
    }

    q->rear += 1;

    q->data[q->rear] = value;

    return 1;
}

int dequeue(int *value, struct Queue *q)
{
    //Kiem tra xem queue trong hay ko
    if(q->front > q->rear)
    {
        //queue trong, ko lay ra dc.
        return 0;
    }

    *value = q->data[q->front];
    q->front += 1;

    return 1;    
}