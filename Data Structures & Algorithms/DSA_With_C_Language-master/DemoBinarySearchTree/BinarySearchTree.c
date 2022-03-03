#include <stdio.h>
#include <stdlib.h>

//Cấu trúc node trong binary search tree

struct Node
{
    int data;           //Lưu dữ liệu
    struct Node *left;  //Trỏ sang node con bên trái
    struct Node *right; //Trỏ sang node con bên phải
};

//Các thao tác với binary search tree
int insert(struct Node **root, int newValue);
//Insert dùng đệ quy
int recursiveInsert(struct Node **root, int newValue);
struct Node *search(struct Node *root, int data);
struct Node *delete (struct Node *root, int deleteValue);
void printTree(struct Node *root);
//Tìm node có giá trị nhỏ nhất
struct Node *findMin(struct Node *root);

int main(int argc, char const *argv[])
{
    //Khoi tao tree
    struct Node *root;
    root = NULL;

    recursiveInsert(&root, 41);
    recursiveInsert(&root, 20);
    recursiveInsert(&root, 11);
    recursiveInsert(&root, 72);
    recursiveInsert(&root, 91);
    recursiveInsert(&root, 73);

    printTree(root);

    //Tìm kiếm
    struct Node *found;
    found = search(root, 91);

    if (found != NULL)
    {
        printf("\nTim thay %d\n", found->data);
    }
    else
    {
        printf("\nKhong tim thay!\n");
    }
    
    
    root = delete(root, 72);
    printf("Sau khi xoa: \n");
    printTree(root);

    return 0;
}

int insert(struct Node **root, int newValue)
{
    struct Node *newNode;     //Node sẽ thêm vào tree
    struct Node *currentNode; //Node dùng để duyệt tree
    struct Node *parentNode;  //Node cha của newNode

    newNode = malloc(sizeof(struct Node));
    newNode->data = newValue;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL)
    {
        //Nếu node gốc NULL thì newNode dc gán là node gốc
        *root = newNode;
    }
    else
    {
        //Chèn node mới vào bên trái hoặc bên phải
        currentNode = *root;
        parentNode = NULL;
        while (1)
        {
            parentNode = currentNode;
            if (newValue < parentNode->data)
            {
                //Rẽ trái
                if (currentNode->left == NULL)
                {
                    //Chèn newNode vào
                    parentNode->left = newNode;
                    break;
                }
                currentNode = currentNode->left;
            }
            else if (newValue > parentNode->data)
            {
                //Rẽ phải
                if (currentNode->right == NULL)
                {
                    //Chèn newNode vào
                    parentNode->right = newNode;
                    break;
                }
                currentNode = currentNode->right;
            }
        }
    }
    return 1;
}

int recursiveInsert(struct Node **root, int newValue)
{
    struct Node *newNode; //Node sẽ thêm vào tree

    newNode = malloc(sizeof(struct Node));
    newNode->data = newValue;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL)
    {
        //Nếu node gốc NULL thì newNode dc gán là node gốc
        *root = newNode;
    }
    else
    {
        if (newValue < (*root)->data)
        {
            recursiveInsert(&(*root)->left, newValue);
        }
        else if (newValue > (*root)->data)
        {
            recursiveInsert(&(*root)->right, newValue);
        }
    }
    return 1;
}

void printTree(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printTree(root->left);
    printf("value: %d\n", root->data);
    printTree(root->right);
}

struct Node *delete (struct Node *root, int deleteValue)
{
    struct Node *temp;

    if (root == NULL)
    {
        return NULL;
    }
    else if (deleteValue < root->data)
    {
        root->left = delete (root->left, deleteValue);
    }
    else if (deleteValue > root->data)
    {
        root->right = delete (root->right, deleteValue);
    }
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            root->right = NULL;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            root->left = NULL;
            free(root);
            return temp;
        }
        else
        {
            //Tìm node có giá trị nhỏ nhất ở cây con bên phải
            temp = findMin(root->right);
            root->data = temp->data;
            if(temp == root->right)
            {
                free(root->right);
                root->right = NULL;
            }
            else
            {
                struct Node *parentMin;
                parentMin = root->right;
                while (parentMin->left != temp)
                {
                    parentMin = parentMin->left;
                }
                parentMin->left = NULL;
                free(temp);             
            }
            
        }
        
    }

    return root;
}

struct Node *findMin(struct Node *root)
{
    if(root == NULL || root->left == NULL)
    {
        return root;
    }
    else
    {
        return(findMin(root->left));
    }
    
}

struct Node *search(struct Node *root, int data)
{
    struct Node *current = root;
    while (current != NULL && current->data != data)
    {
        //go to left tree
        if (current->data > data)
        {
            current = current->left;
        } //else go to right tree
        else
        {
            current = current->right;
        }
    }
    return current;
}