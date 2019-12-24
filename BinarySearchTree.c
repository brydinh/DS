#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree Node
struct BSTNode
{
    int data;
    struct BSTNode* leftChild;
    struct BSTNode* rightChild;
};

// Binary Search Tree Root
struct BinarySearchTree
{
    struct BSTNode* root;
};

struct BSTNode* createNode(int num)
{
    struct BSTNode* node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    
    node->data = num;
    node->leftChild = NULL;
    node->rightChild = NULL;

    return node;
}

void insertNode(struct BSTNode* root, int data)
{
    printf("in inserNode");
    if(root == NULL)
    {
        struct BSTNode* insertThis = createNode(data);
        root = insertThis;
    }
    else
    {
        if(root->data >= data)
        {
            insertNode(root->rightChild, data);
        }
        else
        {
            insertNode(root->leftChild, data);
        }  
    }
}   

struct BinarySearchTree* createRoot()
{
    struct BinarySearchTree* b = (struct BinarySearchTree*)malloc(sizeof(struct BinarySearchTree));
    b->root = NULL;
    return b;
}


int main()
{
    struct BinarySearchTree* b = createRoot();

    insertNode(b->root, 5);
    //insertNode(b->root, 2);

    printf("%d\n", b->root->data);

   // printf("%d\n", b->root->leftChild->data);

    return 0; 
}