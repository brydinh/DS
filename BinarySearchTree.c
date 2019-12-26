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

int isLeaf(struct BSTNode* root , int findThis)
{
    while(root != NULL)
    {
        if(findThis > root->data)
        {
            root = root->rightChild;
        }
        else if (findThis < root->data)
        {
            root = root->leftChild;
        }
        else
        {
            if(root->leftChild == NULL && root->rightChild == NULL)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            
        }
    }
}

struct BSTNode* retrieveNode(struct BSTNode* root, int findThis)
{
    while(root != NULL)
    {
        if(findThis > root->data)
        {
            root = root->rightChild;
        }
        else if (findThis < root->data)
        {
            root = root->leftChild;
        }
        else
        {
            return root;
        }
    }
}

void removeNode(struct BSTNode* root, int findThis)
{
    struct BSTNode* removeThis = retrieveNode(root, findThis);

    // // traverse to find parent
    // while(root != NULL)
    // {
    //     if(findThis >  )
    // }

    if(removeThis->leftChild == NULL && removeThis->rightChild == NULL)
    {
        free(removeThis);
    }

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

    printf("%d\n", isLeaf(root1, 1)); // should be 0
    printf("%d\n", isLeaf(root1, 0)); // should be 1
    printf("%d\n", isLeaf(root1, 6)); // should be 1

    printf("Before remove \n");
    removeNode(root1, 0);
    printf("After remove \n");

    printf("Preorder: ");
    PrintTreePreorder(root1);
    printf("\n");

    return 0; 
}