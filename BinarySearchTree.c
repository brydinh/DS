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

    printf("Is 1 a leaf? (0 = no, 1 = yes): %d\n", isLeaf(root1, 1)); // should be 0
    printf("Is 0 a leaf? (0 = no, 1 = yes): %d\n", isLeaf(root1, 0)); // should be 1
    printf("Is 6 a leaf? (0 = no, 1 = yes): %d\n", isLeaf(root1, 6)); // should be 1

    printf("Count: %d\n", count(root1)); // 5

    root1 = removeNode(root1, 6);

    printf("Preorder: ");
    PrintTreePreorder(root1);
    printf("\n");
    printf("Count: %d\n", count(root1)); // 4

    root1 = removeNode(root1, 5);

    printf("Preorder: ");
    PrintTreePreorder(root1);
    printf("\n");
    printf("Count: %d\n", count(root1)); // 3

    return 0; 
}