#include "deque_stack_queue.h"
#include <stdio.h>
#include <stdlib.h>

node *new_node(TYPE data)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->next = n->prev = NULL;
    return n;
}

deque *new_deque()
{
    deque *d = malloc(sizeof(deque));
    if (d == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    d->head = d->tail = NULL;
    return d;
}

void distNode(node *n)
{
    free(n);
}

void insHead(deque *d, TYPE data)
{
    node *n = new_node(data);
    if (!d->head)
        d->head = d->tail = n;
    else
    {
        n->next = d->head;
        d->head->prev = n;
        d->head = n;
    }
}

void remHead(deque *d)
{
    if (d->head)
    {
        if (d->head == d->tail)
        {
            d->head = d->tail = NULL;
        }
        else
        {
            d->head = d->head->next;
            distNode(d->head->prev);
            d->head->prev = NULL;
        }
    }
}

void insTail(deque *d, TYPE data)
{
    node *n = new_node(data);
    if (!d->head)
        d->head = d->tail = n;
    else
    {
        d->tail->next = n;
        n->prev = d->tail;
        d->tail = n;
    }
}

void remTail(deque *d)
{
    if (d->tail)
    {
        if (d->head == d->tail)
        {
            d->head = d->tail = NULL;
        }
        else
        {
            d->tail = d->tail->prev;
            distNode(d->tail->next);
            d->tail->next = NULL;
        }
    }
}

void printDeque(deque *d)
{
    node *current = d->head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

/************** Stack Functions **************/
stack *new_stack()
{
    stack *s = malloc(sizeof(stack));
    if (s == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    s->deque = new_deque();
    return s;
}

void push_stack(stack *s, TYPE data)
{
    insHead(s->deque, data);
}

TYPE pop_stack(stack *s)
{
    if (!isEmptyStack(s))
    {
        TYPE data = s->deque->head->data;
        remHead(s->deque);
        return data;
    }
    else
        return -1;
}

TYPE peek_stack(stack *s)
{
    return !isEmptyStack(s) ? s->deque->head->data : -1;
}

int isEmptyStack(stack *s)
{
    return s->deque->head == NULL ? 1 : 0;
}

void displayStack(stack *s)
{
    node *temp = s->deque->head;
    while (temp->next != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
/*********************************************/
/************** Queue Functions **************/
queue *new_queue()
{
    queue *q = malloc(sizeof(queue));
    if (q == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    q->deque = new_deque();
    return q;
}

void enqueue(queue *q, TYPE data)
{
    insTail(q->deque, data);
}

TYPE dequeue(queue *q)
{
    if (!isEmptyQueue(q))
    {
        TYPE data = q->deque->head->data;
        remHead(q->deque);
        return data;
    }
    else
        return -1;
}

int isEmptyQueue(queue *q)
{
    return q->deque->head == NULL ? 1 : 0;
}

void displayQueue(queue *q)
{
    node *temp = q->deque->head;
    while (temp->next != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
/*********************************************/