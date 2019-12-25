#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree Node
struct BSTNode
{
    int data;
    struct BSTNode* leftChild;
    struct BSTNode* rightChild;
};

struct BSTNode* createNode(int num)
{
    struct BSTNode* node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    node->data = num;
    node->leftChild = node->rightChild = NULL;

    return node;
}

struct BSTNode* insertNode(struct BSTNode* root, int data)
{
    if(root == NULL)
    {
        root = createNode(data);
    }
    else
    {
        if(data > root->data)
        {
            root->rightChild = insertNode(root->rightChild, data);  
        }
        else
        {
            root->leftChild = insertNode(root->leftChild, data);
        }      
    }

    return root;
}   


int main()
{
    struct BSTNode* root1 = NULL;

    root1 = insertNode(root1, 5);
    root1 = insertNode(root1, 1);


    printf("%d\n", root1->data);

    printf("%d\n", root1->leftChild->data);

    return 0; 
}