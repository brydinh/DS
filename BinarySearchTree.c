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

struct BSTNode* minValueNode(struct BSTNode* node) 
{ 
    struct BSTNode* current = node; 
  
    /* loop to find the leftmost leaf */
    while (current && current->leftChild != NULL)
    {
        current = current->leftChild; 
    }
  
    return current; 
} 

struct BSTNode* deleteNode(struct BSTNode* root, int key) 
{ 
    if (root == NULL) return root; 
    if (key < root->data) root->leftChild = deleteNode(root->leftChild, key); 
    else if (key > root->data) root->rightChild = deleteNode(root->rightChild, key); 
    else // found node, delete this one
    {
        // case 1: node has no children
        if(root->leftChild == NULL && root->rightChild == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        // case 2: node has 1 children (left or right) 
        if (root->leftChild == NULL) 
        { 
            struct node *temp = root->rightChild; 
            free(root); 
            return temp; 
        } 
        else if (root->rightChild == NULL) 
        { 
            struct node *temp = root->leftChild; 
            free(root); 
            return temp; 
        } 
  
        // case 3: node has two children
        // retrieve inorder successor
        struct BSTNode* temp = minValueNode(root->rightChild); 
        root->data = temp->data; 
  
        // Delete the inorder successor 
        root->rightChild = deleteNode(root->rightChild, temp->data); 
    } 
    return root; 
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
    root1 = deleteNode(root1, 0);
    printf("After remove \n");

    printf("Preorder: ");
    PrintTreePreorder(root1);
    printf("\n");

    return 0; 
}