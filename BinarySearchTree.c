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

// Left, Root, Right
void PrintTreeInorder(struct BSTNode* root)
{
    if(root == NULL) return;
    
    PrintTreeInorder(root->leftChild); 
    printf("%d, \t", root->data); 
    PrintTreeInorder(root->rightChild); 
}

// Left, Right, Root
void PrintTreePostorder(struct BSTNode* root)
{
    if(root == NULL) return;

    PrintTreePostorder(root->leftChild); 
    PrintTreePostorder(root->rightChild); 
    printf("%d, \t", root->data);    
}

// Root, Left, Right
void PrintTreePreorder(struct BSTNode* root)
{
    if(root == NULL) return;
    
    printf("%d, \t", root->data); 
    PrintTreePreorder(root->leftChild); 
    PrintTreePreorder(root->rightChild);   
}

void isLeaf(struct BSTNode* root , int findThis)
{
    if(root == NULL) return;

    if(root->data == findThis)
    {
        if(root->leftChild == NULL && root->rightChild == NULL)
        {
            printf("is leaf!\n");
        }
        else
        {
            printf("is not leaf!\n");
        }      
    }
    isLeaf(root->leftChild, findThis);
    isLeaf(root->rightChild, findThis);
}


int main()
{
    struct BSTNode* root1 = NULL;

    root1 = insertNode(root1, 5);
    root1 = insertNode(root1, 1);
    root1 = insertNode(root1, 6);
    root1 = insertNode(root1, 0);
    root1 = insertNode(root1, 3);

    printf("Preorder: ");
    PrintTreePreorder(root1);
    printf("\n");
    printf("Inorder: ");
    PrintTreeInorder(root1);
    printf("\n");
    printf("Postorder: ");
    PrintTreePostorder(root1);
    printf("\n");

    isLeaf(root1, 1); // should be "is not leaf"
    isLeaf(root1, 0); // should be "is leaf"
    isLeaf(root1, 6); // should be "is leaf"

    return 0; 
}