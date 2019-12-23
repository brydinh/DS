#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct BTNode
{
    int data;
    struct BTNode* leftChild;
    struct BTNode* rightChild;
};

// Binary Tree Root
struct BinaryTree
{
    struct BTNode* root;
};


struct BTNode* createNode(int num)
{
    struct BTNode* node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    
    BTNode->data = num;
    BTNode->leftChild = NULL;
    BTNode->rightChild = NULL;

    return node;
}

int main()
{
    return 0; 
}