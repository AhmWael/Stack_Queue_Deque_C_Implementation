#ifndef DEQUE_STACK_QUEUE_H
#define DEQUE_STACK_QUEUE_H

typedef int TYPE;

typedef struct node
{
    TYPE data;
    struct node *next;
    struct node *prev;
} node;

typedef struct
{
    node *head;
    node *tail;
} deque;

typedef struct
{
    deque *deque;
} stack;

typedef struct
{
    deque *deque;
} queue;

// Primary functions for deque
node *new_node(TYPE data);
deque *new_deque();
void distNode(node *n);
void insHead(deque *d, TYPE data);
void remHead(deque *d);
void insTail(deque *d, TYPE data);
void remTail(deque *d);
void printDeque(deque *d);

// Stack functions
stack *new_stack();
// void dist_stack(stack *s);
void push_stack(stack *s, TYPE data);
TYPE pop_stack(stack *s);
TYPE peek_stack(stack *s);
int isEmptyStack(stack *s);
void displayStack(stack *s);

// Queue functions
queue *new_queue();
// void dist_queue(queue *q);
void enqueue(queue *q, TYPE data);
TYPE dequeue(queue *q);
int isEmptyQueue(queue *q);
void displayQueue(queue *q);

#endif /* DEQUE_STACK_QUEUE_H */