#include <stdio.h>
#include <stdlib.h>

// Stack Node
struct SNode
{
    int data;
    struct SNode* next;
};

struct Stack
{
    struct SNode* top;
};

struct Stack* createStack()
{
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = NULL;
    return s;
}

void pushNode(struct Stack* s, int data)
{
    struct SNode* insertNode = (struct SNode*)malloc(sizeof(struct SNode));
    insertNode->data = data;  
    insertNode->next = s->top; 
    s->top = insertNode;
}

// LIFO
void popNode(struct Stack* s)
{
    if(s->top != NULL)
    {
        struct SNode* temp = s->top;

        temp = s->top; 
        s->top = s->top->next; 
        temp->next = NULL; 

        free(temp);  
    }  
}

void printStack(struct Stack* s)
{
    if(s->top == NULL)
    {
        printf("EMPTY\n");
    }
    else
    {
       struct SNode* temp = s->top;
        while(temp != NULL)
        {   
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }   
}

int isEmpty(struct Stack* s) // 0 = false, 1 = true
{
    if(s->top == NULL) return 1;

    return 0;
}

struct SNode* top(struct Stack* s)
{
    return s->top;
}

int main()
{ 
    struct Stack* s1 = createStack();
    pushNode(s1, 1);
    pushNode(s1, 2);
    pushNode(s1, 3);
    printStack(s1); // 1 2 3

    popNode(s1);
    printStack(s1); // 1 2

    popNode(s1);
    printStack(s1); // 1
    
    popNode(s1);
    printStack(s1); // Empty

    popNode(s1);
    printStack(s1); // Empty


    return 0;
}