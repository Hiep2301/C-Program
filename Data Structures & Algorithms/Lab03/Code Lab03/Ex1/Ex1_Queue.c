// Queue sử dụng con trỏ
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *data;
    int maxSize;
    int front;
    int rear;
} Queue;

int initQueue(Queue *queue, int maxSize); // Khai báo queue và gán số lượng tối đa các phần tử trong queue
int enqueue(Queue *queue, int rearValue);
int dequeue(Queue *queue, int *frontValue); // *frontValue để thay đổi front

int main(int argc, char const *argv[])
{
    Queue queue;
    initQueue(&queue, 3);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    int frontValue;
    printf("Dequeue frontValue: "); // Vào trước ra trước
    while (dequeue(&queue, &frontValue))// Truyền tham chiếu là địa chỉ của frontValue
    {
        printf("%d | ", frontValue); // In ra giá trị tại địa chỉ của phần tử front
    }
    return 0;
}

int initQueue(Queue *queue, int maxSize)
{
    queue->maxSize = maxSize;
    queue->data = (int *)malloc(maxSize * sizeof(int)); // Cấp phát vùng nhớ cho con trỏ data -> trở thành mảng
    queue->front = 0;
    queue->rear = -1;
    return 1;
}

int enqueue(Queue *queue, int rearValue)
{
    // Bước 1: Kiểm tra xem queue đã đầy chưa
    if (queue->rear == queue->maxSize - 1)
    {
        if (queue->front == 0)
        {
            // Bước 2: Nếu đã đầy thì dừng và thoát khỏi hàm
            return 0;
        }
        // Nếu rear là phần tử cuối nhưng front không phải phần tử đầu tiên (phần tử đầu tiên luôn có chỉ số là 0)
        else if (&queue->front > 0)
        {
            // Di chuyển dữ liệu lên đầu queue
            for (int i = 0, j = queue->front; j <= queue->rear; i++, j++)
            {
                queue->data[i] = queue->data[j];
            }
            queue->rear -= queue->front;
            queue->front = 0;
        }
    }
    // Bước 3: Nếu queue chưa đầy thì tăng con trỏ rear trỏ đến khoảng trống tiếp theo
    queue->rear += 1;
    // Bước 4: Thêm dữ liệu phần tử vào vị trí mà rear đang trỏ tới
    queue->data[queue->rear] = rearValue;
    // Bước 5: Thành công thì trả về 1
    return 1;
}

int dequeue(Queue *queue, int *frontValue)
{
    // Bước 1: Kiểm tra xem queue có rỗng không
    if (queue->front > queue->rear)
    {
        // Nếu queue rỗng thì dừng và thoát khỏi hàm
        return 0;
    }
    // Bước 3: Nếu queue không rỗng thì truy cập vào dữ liệu phần tử nơi front đang trỏ tới
    *frontValue = queue->data[queue->front]; 
    // Bước 4: Tăng con trỏ front vào phần từ kế tiếp (front lúc đầu đang ở phần tử chỉ số 0 sau khi tăng 1 đơn vị thì trỏ vào phần tử chỉ số 1)
    queue->front += 1;
    // Bước 5: Thành công thì trả về 1
    return 1;
}