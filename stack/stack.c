#include "stack.h"

// also empties the stack
Stack* initialize(Stack* s)
{
    s->top = NULL;

    return s;
}

bool empty(Stack* s)
{
    if(s->top == NULL)
        return true;
    else
        return false;
}

int size(Stack* s)
{
    if(!empty(s))
    {
        Node* n = s->top;

        int size = 1;
        while(n->next != NULL)
        {
            n = n->next;
            size++;
        }
        return size;
    }
    else
        return 0;
}

int top(Stack* s)
{
    if(!empty(s))
        return s->top->data;
}

void push(Stack* s, int value)
{
    Node* q = malloc(sizeof(Node));
    q->data = value;
    q->next = s->top;
    s->top = q;
    free(q);
}

int pop(Stack* s)
{
    if(!empty(s))
    {
        Node* q = malloc(sizeof(Node));
        q = s->top;
        int key = q->data;
        s->top = s->top->next;
        free(q);

        return key;
    }
}

int elementAt(Stack* s, int pos)
{
    Node* n = s->top;

    int count = 0;
    while(count < pos-1)
    {
        n = n->next;
        count++;
    }
    
    return n->data;
}

Stack* copy(Stack* s)
{
    Node* aux = s->top;
    Stack* s2 = initialize(s2);
    while (aux->next != NULL)
    {
        push(s2, aux->data);
        aux = aux->next;
    }

    push(s2, aux->data);
    
    return s2;
}