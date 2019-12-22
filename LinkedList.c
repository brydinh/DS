#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Head of LinkedList
struct Node * head = NULL;

void insertNode(int num)
{
    // create new node.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;

    // case 1: head is NULL.
    if(head == NULL)
    {
        head = newNode; 
    }
    // case 2: traverse to the end of list and insert.
    else
    {
        struct Node * temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void printList()
{
    struct Node * temp = head;

    while (temp != NULL)
    {
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }
}

void removeNode()
{

}

struct Node* peek()
{

}


// driver function for testing these functions
int main()
{
    insertNode(1);
    insertNode(3);
    insertNode(2);
    printList();
    return 0; 

}