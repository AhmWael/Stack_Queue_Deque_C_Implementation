#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TYPE;

typedef struct{
    int front, rear, capacity, size;
    TYPE *items;
} queue;

queue *new_queue(int capacity);
void dist_queue(queue *q);
void enqueue(queue *q, int item);
TYPE dequeue(queue *q);
int isFullQueue(queue *q);
int isEmptyQueue(queue *q);
int count_Even_Queue(queue *q);

queue *new_queue(int capacity){
    queue *q = malloc(sizeof(queue));
    q->items = malloc(sizeof(TYPE) * capacity);
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    return q;
}

void dist_queue(queue *q){
    free(q->items);
    free(q);
}

void enqueue(queue *q, TYPE item){
    if(!isFullQueue(q)){
        q->items[q->rear] = item;
        q->rear = (q->rear + 1) % q->capacity;
        q->size++;
    }
}

TYPE dequeue(queue *q){
    if(!isEmptyQueue(q)){
        TYPE item = q->items[q->front];
        q->front = (q->front + 1) % q->capacity;
        q->size--;
        return item;
    }
    else 
        return -1;
}

int isFullQueue(queue *q){
    return q->size == q->capacity ? 1 : 0;
}

int isEmptyQueue(queue *q){
    return q->size == 0 ? 1 : 0;
}

int count_Even_Queue(queue *q){
    int count = 0, q_size = q->size;
    for(int i = 0;i < q_size;i++){
        int item = dequeue(q);
        if(item % 2 == 0)
            count++;
        enqueue(q, item);
    }
    return count;
}

void main(){
    queue *q = new_queue(5);
    int x;
    printf("Enter numbers in queue: \n");
    for(int i = 0;i<5;i++){
        scanf("%d", &x);
        enqueue(q, x);
    }
    printf("Number of even: %d", count_Even_Queue(q));

}
