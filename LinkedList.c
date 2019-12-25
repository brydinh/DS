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
        printf("EMPTY\n\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d", temp->data);
            
            if(temp->next != NULL)
            {
                printf("->");
            }
            temp = temp->next;
        }
        printf("\n\n");
    }   
}

void printMiddle(struct LinkedList* l)
{
    struct Node * temp = l->head;

    for(int x=0; x<count(l)/2; x++)
    {
        temp = temp->next;
    }

     printf("Middle: %d\n", temp->data);
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

struct LinkedList* reverseList(struct LinkedList* l)
{
    struct LinkedList* rl = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    
    struct Node* prev = NULL;
    struct Node* curr = l->head;
    struct Node * next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    rl->head = prev;
    
    return rl;
}
///////////////////////////////////////////////////
// CTCI Questions:
///////////////////////////////////////////////////

// 2.1
void removeDups(struct LinkedList* l)
{
    struct Node* n = l->head;
}

// 2.2
// Implement an algorithm to find the kth to last element of a singly linked list.
struct Node* returnKthToLast(struct LinkedList* l, int k)
{
    struct Node* temp = l->head;
    struct Node* temp2 = l->head;

    while(k > 0)
    {
        temp = temp->next;
        k--;
    }

    while(temp != NULL)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }

    return temp2;
}

// driver function for testing functions
int main()
{
    struct LinkedList* l = createLinkedList();
    insertNode(l, 1);
    insertNode(l, 3);
    insertNode(l, 2);
    printList(l);

    removeNode(l, 3);
    printList(l);

    removeNode(l, 2);
    printList(l);

    removeNode(l, 1);
    printList(l);

    insertNode(l, 100);
    insertNode(l, 200);
    insertNode(l, 300);
    insertNode(l, 400);
    printList(l);

    printMiddle(l);

    removeNode(l, 300);
    printList(l);
    printMiddle(l);

    struct LinkedList* rl = reverseList(l);
    printList(rl);

    struct Node* yo = returnKthToLast(rl, 2);
    printf("%d\n", yo->data);
    return 0; 
}