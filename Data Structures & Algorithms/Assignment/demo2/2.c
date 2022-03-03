#include <stdio.h>
#include <stdlib.h>

// create a node - Tạo một node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// insert at the beginning - Chèn vào đầu danh sách
void insertatbeginning(Node **head_ref, int new_data)
{
    // allocate memory to a node - Cấp phát vùng nhớ cho node
    Node *new_node = (Node *)malloc(sizeof(Node));
    // insert the data - Chèn dữ liệu
    new_node->data = new_data;
    new_node->next = (*head_ref);
    // move head to new node - Di chuyển head đến node mới
    (*head_ref) = new_node;
}

// insert a node after a node - Chèn vào giữa danh sách
void insertafter(Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// insert at the end - Chèn vào cuối danh sách
void insertatend(Node **head_ref, int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    
    Node *last = *head_ref; 
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

// delete a node - Xóa một node
void delete(Node **head_ref, int key)
{
    Node *temp = *head_ref;
    Node *prev;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // find the key to be deleted - Tìm dữ liệu để có thể xóa được
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    // if the key is not present - nếu dữ liệu không có
    if (temp == NULL)
    {
        return;
    }
    // remove the node - Xóa node
    prev->next = temp->next;
    free(temp);
}

// search a node - Tìm kiếm node
int search(Node **head_ref, int key)
{
    Node *current = *head_ref;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// sort the linked list - Sắp xếp danh sách
void sort(Node **head_ref)
{
    Node *current = *head_ref;
    Node *index = NULL;
    int temp;
    if (head_ref == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            // index points to the node next to current -Số chỉ mục để node trỏ tới
            index = current->next;
            while (index != NULL)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

// display the linked list - Hiển thị danh sách
void display(Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main()
{
    Node *head = NULL;
    insertatend(&head, 10);
    insertatbeginning(&head, 20);
    insertatbeginning(&head, 30);
    insertatend(&head, 40);
    insertafter(head->next, 50);
    printf("Linked List: ");
    display(head);
    printf("\nAfter Deleting: ");
    delete(&head, 20);
    display(head);
    int item = 20;
    if (search(&head, item))
    {
        printf("\n%d is found", item);
    }
    else
    {
        printf("\n%d is not found", item);
    }
    sort(&head);
    printf("\nSorted List: ");
    display(head);
}