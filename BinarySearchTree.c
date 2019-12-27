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

int count(struct BSTNode* root)
{
    if (root == NULL) return 0;
    
    return 1 + count(root->leftChild) + count(root->rightChild);
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
  
    // find the leftmost leaf
    while (current && current->leftChild != NULL)
    {
        current = current->leftChild; 
    }
  
    return current; 
} 

struct BSTNode* removeNode(struct BSTNode* root, int key) 
{ 
    if (root == NULL) return root;

    struct BSTNode* temp;

    if (key < root->data) root->leftChild = removeNode(root->leftChild, key); 
    else if (key > root->data) root->rightChild = removeNode(root->rightChild, key); 
    else // found node, remove this one
    {
        // case 1: node has 1 children (left or right) 
        if (root->leftChild == NULL) 
        { 
            temp = root->rightChild; 
            free(root);
            root = temp; 
        } 
        else if (root->rightChild == NULL) 
        { 
            temp = root->leftChild; 
            free(root); 
            root = temp;
        }
        else // case 2: node has 2 children (left & right)
        {
            // retrieve inorder successor
            temp = minValueNode(root->rightChild);
            root->data = temp->data;
            // remove inorder successor
            root->rightChild = removeNode(root->rightChild, temp->data);
        }
    } 
    return root; 
} 


///////////////////////////////////////////////////
// CTCI Questions:
///////////////////////////////////////////////////


// 4.2
// write an algorithm to create a BST w/ minimal height
struct BSTNode* minHeightConstruction(int* arr1, int size)
{
    // assume array is sorted in increasing order.
    // 1. get medium num of array (this will be the root)
    // 2. insert the rest of the array in the tree based on root

    struct BSTNode* root = NULL;

    root = insertNode(root, arr1[size/2]);

    for(int x=0; x<size; x++)
    {
        if(x != size/2)
        {
            root = insertNode(root, arr1[x]);
        }
    }
    
    return root;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    
    struct BSTNode* root1 = NULL;
    root1 = minHeightConstruction(arr1, 5);
    
    printf("Preorder: ");
    PrintTreePreorder(root1);
    printf("\n");

    struct BSTNode* root2 = NULL;
    root2 = insertNode(root2, 5);
    root2 = insertNode(root2, 1);
    root2 = insertNode(root2, 6);
    root2 = insertNode(root2, 0);
    root2 = insertNode(root2, 3);

    printf("Preorder: ");
    PrintTreePreorder(root2);
    printf("\n");
    printf("Inorder: ");
    PrintTreeInorder(root2);
    printf("\n");
    printf("Postorder: ");
    PrintTreePostorder(root2);
    printf("\n");

    printf("Is 1 a leaf? (0 = no, 1 = yes): %d\n", isLeaf(root2, 1)); // should be 0
    printf("Is 0 a leaf? (0 = no, 1 = yes): %d\n", isLeaf(root2, 0)); // should be 1
    printf("Is 6 a leaf? (0 = no, 1 = yes): %d\n", isLeaf(root2, 6)); // should be 1

    printf("Count: %d\n", count(root2)); // 5

    root2 = removeNode(root2, 6);

    printf("Preorder: ");
    PrintTreePreorder(root2);
    printf("\n");
    printf("Count: %d\n", count(root2)); // 4

    root2 = removeNode(root2, 5);

    printf("Preorder: ");
    PrintTreePreorder(root2);
    printf("\n");
    printf("Count: %d\n", count(root2)); // 3

    return 0; 
}