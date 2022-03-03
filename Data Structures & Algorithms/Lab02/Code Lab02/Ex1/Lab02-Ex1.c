#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Khai báo danh sách liên kết đơn
Node *initial();
// Tạo và thêm Node mới
int addNewNode(Node **head, int value);
// Hiển thị các Node
void displayNode(Node *head);

int main(int argc, char const *argv[])
{
    Node *head;
    head = initial();

    addNewNode(&head, 1);
    addNewNode(&head, 2);
    addNewNode(&head, 3);

    displayNode(head);
    return 0;
}

Node *initial()
{
    Node *head;
    head = NULL;
    return head;
}

int addNewNode(Node **head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    return 1;
}

void displayNode(Node *head)
{
    for (Node *p = head; p != NULL; p = p->next)
    {
        printf("%d -> ", p->data);
    }
    printf("NULL");
}