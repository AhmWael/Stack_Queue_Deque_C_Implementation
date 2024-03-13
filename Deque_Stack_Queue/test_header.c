#include <stdio.h>
#include <stdlib.h>
#include "deque_stack_queue.c"

void main() 
{
    // Test deque
    printf("Testing deque:\n");
    deque *d = new_deque();
    insTail(d, 1);
    insTail(d, 2);
    insTail(d, 3);
    insTail(d, 4);
    printf("Deque: \n");
    printDeque(d);
    printf("\n");

    // Test stack
    printf("Testing stack:\n");
    stack *s = new_stack();
    push_stack(s, 10);
    push_stack(s, 20);
    push_stack(s, 30);
    printf("Stack: \n");
    displayStack(s);
    printf("\n");

    // Test queue
    printf("Testing queue:\n");
    queue *q = new_queue();
    enqueue(q, 100);
    enqueue(q, 200);
    enqueue(q, 300);
    printf("Queue: \n");
    displayQueue(q);
    printf("\n");
}