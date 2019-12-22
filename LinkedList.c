#include <stdio.h>
#include <stdlib.h>

// LinkedList Node
struct Node
{
    int data;
    struct Node* next;
};

// Head (front) of LinkedList
struct LinkedList
{
    struct Node* head;
};

struct LinkedList* createLinkedList()
{
    struct LinkedList* l = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    l->head = NULL;
    return l;
}

int count(struct LinkedList* l)
{
    int count = 0;
    struct Node * temp = l->head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertNode(struct LinkedList* l, int num)
{
    // create new node.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;

    // case 1: head is NULL.
    if(l->head == NULL)
    {
        l->head = newNode; 
    }
    // case 2: traverse to the end of list and insert.
    else
    {
        struct Node * temp = l->head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct LinkedList* l)
{
    struct Node * temp = l->head;

    if(temp == NULL)
    {
        printf("LinkedList is currently empty\n\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("Data: %d\t", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }   
}

// remove node based on its data
void removeNode(struct LinkedList* l, int num)
{ 
    // if there is only one node in the LL, make that node NULL.
    if(count(l) == 1)
    {
        l->head = NULL; 
    }
    else
    {
        struct Node* removeThis = l->head;
        struct Node* newHead;
        
        while(removeThis != NULL)
        {
            if(removeThis->next->data == num)
            {
                newHead = removeThis;
                removeThis = removeThis->next;
                break;
            }
            removeThis = removeThis->next;
        }

        newHead->next = removeThis->next;
        free(removeThis);
    }     
}

struct Node* peek()
{
}

// driver function for testing functions
int main()
{
    struct LinkedList* hi = createLinkedList();
    insertNode(hi, 1);
    insertNode(hi, 3);
    insertNode(hi, 2);
    printList(hi);

    removeNode(hi, 3);
    printList(hi);

    removeNode(hi, 2);
    printList(hi);

    removeNode(hi, 1);
    printList(hi);

    insertNode(hi, 100);
    printList(hi);
    return 0; 
}