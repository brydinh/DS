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

void insert(struct BinarySearchTree* b, int data)
{
    
}

struct BSTNode* createNode(int num)
{
    struct BSTNode* node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    
    BSTNode->data = num;
    BSTNode->leftChild = NULL;
    BSTNode->rightChild = NULL;

    return node;
}

int main()
{
    return 0; 
}