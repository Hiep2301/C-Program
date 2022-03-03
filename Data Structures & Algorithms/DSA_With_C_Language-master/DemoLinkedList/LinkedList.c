#include<stdio.h>
#include<stdlib.h>

// typedef struct 
// {
//     char id[10];
//     char name[50];
//     int age;
// } Student;

//Khai bao struct Node
struct Node
{
    //Student std;
    int data; //Luu du lieu
    struct Node *next; //Luu dia chi o nho cua node tiep theo
};

typedef struct Node intLinkedList;

//Khai bao nguyen mau ham
int insertToHead(int value, intLinkedList **head);
void display(intLinkedList *head);
void displayWithFor(intLinkedList *head);
int deleteFromHead(intLinkedList **head);
int deleteByValue(int value, intLinkedList **head);
int indexOf(int value, intLinkedList *head);
int insert(intLinkedList **head, int value, int atIndex);
int cout(intLinkedList *head); //Dem so phan tu cua Linked List
intLinkedList *getNodeAtIndex(intLinkedList *head, int index);


int main(int argc, char const *argv[])
{
    intLinkedList *head;
    head = NULL;

    insertToHead(1, &head);
    insertToHead(2, &head);
    insertToHead(3, &head);
    insertToHead(4, &head);
    insertToHead(5, &head);

    //displayWithFor(head);
    display(head);
    // printf("\nSo phan tu: %d", cout(head));

    // intLinkedList *node;
    // node = getNodeAtIndex(head, 1);
    // printf("\n%d", node->data);

    // insert(&head, 6, 2);
    // printf("\n");
    // display(head);
    //printf("\n%d", indexOf(4, head));

    printf("\nNhap vao gia tri can xoa: ");
    int a;
    scanf("%d", &a);

    int value = deleteByValue(a, &head);
    if(value == 1)
    {
        printf("Linked List sau khi xoa:\n");
        display(head);
    }
    else
    {
        printf("%d ko ton tai trong Linked List!", a);
    }
    
    return 0;
}

int insertToHead(int value, intLinkedList **head)
{
    //Tao node moi
    intLinkedList *newNode;

    //Cap phat bo nho cho node moi
    newNode = (intLinkedList *)malloc(sizeof(intLinkedList));

    //Gan gia tri cho data
    newNode->data = value;

    //Cho newNode tro den node head hien tai
    newNode->next = *head;

    //Tro head den newNode.
    *head = newNode;

    return 1;
}

void displayWithFor(intLinkedList *head)
{
    intLinkedList *iterator;
    for (iterator = head; iterator != NULL; iterator = iterator->next)
    {
        printf("%d -> ", iterator->data);
    }
    printf("NULL");
}

void display(intLinkedList *head)
{
    intLinkedList *iterator;
    iterator = head;
    while (iterator != NULL)
    {
        printf("%d -> ", iterator->data);
        iterator = iterator->next;
    }
    printf("NULL");
}

int indexOf(int value, intLinkedList *head)
{
    //
    intLinkedList *iterator;
    int i;
    for (iterator = head, i = 0; 
        iterator != NULL; 
        iterator = iterator->next, i++)
    {
        if(iterator->data == value)
        {
            return i;
        }
    }

    //Ko tim thay
    return -1;
}


int insert(intLinkedList **head, int value, int atIndex)
{
    //Tao node moi
    intLinkedList *newNode;

    //Cap phat bo nho cho node moi
    newNode = (intLinkedList *)malloc(sizeof(intLinkedList));

    //Gan gia tri cho data
    newNode->data = value;
    
    if(atIndex < 0 || atIndex >= cout(*head))
    {
        return 0;
    }

    if(atIndex == 0)
    {
        return insertToHead(value, head);
    }

    intLinkedList *current = getNodeAtIndex(*head, atIndex - 1);

    if(current != NULL)
    {
        //0, 1, 2, 3, 4
        //5, 4, 3, 2, 1
        //5, 4, 6, 3, 2, 1
        intLinkedList *nextNode = current->next;
        current->next = newNode;
        newNode->next = nextNode;
        return 1;
    }

    return 0;

}


int cout(intLinkedList *head)
{
    int i = 0;
    intLinkedList *iterator;
    iterator = head;
    while (iterator != NULL)
    {
        i++;
        iterator = iterator->next;
    }

    return i;
}

intLinkedList *getNodeAtIndex(intLinkedList *head, int index)
{
    intLinkedList *iterator;
    iterator = head;
    for(int i = 0; i < index; i++, iterator = iterator->next);

    return iterator;
}

int deleteByValue(int value, intLinkedList **head)
{
    intLinkedList *current = *head;
    intLinkedList *pre = *head;
    //Duyet Linked List de tim vi tri cua gia tri muon xoa
    while (current != NULL)
    {
        //Tim thay vi tri cua gia tri muon xoa thi thoat khoi vong lap
        if(current->data == value){
            break;
        }
        pre = current; // nếu node cần xóa ko phải thì gán node đó cho pre để nếu node sau là node cần xóa thì pre sẽ ở ngay trước node cần xóa đó
        current = current->next;
    }
    if(current != NULL)
    {
        //Gia tri can xoa nam o dau Linked List
        if (current == pre)
        {
            *head = current->next;
        }
        else //Gia tri can xoa nam o vi tri bat ki cua Linked List
        {
            pre->next = current->next;
        }
        free(current);
        return 1;
    }
    return 0;
}