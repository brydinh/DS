#include <stdio.h>
#include <stdlib.h>

// Queue Node
struct QNode
{
    int data;
    struct QNode* next;
};

// Head (front) & tail (back) of Queue
struct Queue
{
    struct QNode* head;
    struct QNode* tail;
};

struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->head = q->tail = NULL;
    return q;
}

int empty(struct Queue* q)
{
    if(q->head == NULL) return 1; // 1 = true
    return 0; // false
}

int size(struct Queue* q)
{
    struct QNode* temp = q->head;
    int counter = 0;

    while(temp != NULL)
    {
        counter++;
        temp = temp->next;
    }

    return counter;
}

struct QNode* front(struct Queue* q)
{
    return q->head;
}

struct QNode* back(struct Queue* q)
{
    return q->tail;
}

void enqueue(struct Queue* q, int data)
{
    struct QNode* n = (struct QNode*)malloc(sizeof(struct QNode));
    n->data = data;
    n->next = NULL;
    
    if(empty(q) == 1) // queue is empty
    {
        q->head = q->tail = n;
    }
    else
    {
        struct QNode* temp = q->tail;
        temp->next = n;
        q->tail = n;
    }   
}

// FIFO
void dequeue(struct Queue* q)
{
    // remove head of queue, and move head to be next in list
    struct QNode* temp = q->head;

    if(temp != NULL)
    {
        q->head = q->head->next; // head is rewritten to be the next item in list
        free(temp);
    }
    else
    {
        q->head = q->tail = NULL;
    }
}

void printQueue(struct Queue* q)
{
    if(q->head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        struct QNode* temp = q->head;
        
        while(temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    struct Queue* q1 = createQueue();
    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);
    printQueue(q1); // 1 2 3 
    printf("Size: %d\n", size(q1)); // 3

    dequeue(q1);
    printQueue(q1); // 2, 3
    printf("Size: %d\n", size(q1)); // 2



    dequeue(q1);
    printQueue(q1); // 3
    printf("Size: %d\n", size(q1)); // 1


    dequeue(q1);
    printQueue(q1); // EMPTY
    printf("Size: %d\n", size(q1)); // 0


    enqueue(q1, 100);
    printQueue(q1); // 100
    printf("Size: %d\n", size(q1)); // 1

    return 0;
}