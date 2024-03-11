#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TYPE;

typedef struct{
    int top, capacity;
    TYPE *items;
} stack;

stack *new_stack(int capacity);
void dist_stack(stack *s);
void push_stack(stack *s, int item);
TYPE pop_stack(stack *s);
TYPE peek_stack(stack *s);
int isFullStack(stack *s);
int isEmptyStack(stack *s);
void print_Stack(stack *s);

int count_Even_stack(stack *s);


stack *new_stack(int capacity){
    stack *s = malloc(sizeof(stack));
    s->items = malloc(sizeof(TYPE) * capacity);
    s->capacity = capacity;
    s->top = 0;
    return s;
}

void dist_stack(stack *s){
    free(s->items);
    free(s);
}

void push_stack(stack *s, TYPE item){
    if(!isFullStack(s)){
        s->items[s->top] = item;
        s->top++;
    }
}

TYPE pop_stack(stack *s){
    if(!isEmptyStack(s)){
        s->top--;
        return s->items[s->top];
    }
    else 
        return -1;
}

TYPE peek_stack(stack *s){
    return !isEmptyStack(s) ? s->items[s->top-1] : -1;
}

int isFullStack(stack *s){
    return s->top == s->capacity ? 1 : 0;
}

int isEmptyStack(stack *s){
    return s->top == 0 ? 1 : 0;
}

int count_Even_stack(stack *s){
    int count = 0;
    stack *temp = new_stack(s->capacity);
    while(!isEmptyStack(s)){
        int item = pop_stack(s);
        if(item % 2 == 0)
            count++;
        push_stack(temp, item);
    }
    while(!isFullStack(s)){
        push_stack(s, pop_stack(temp));
    }
    return count;
}

void print_Stack(stack *s)
{
    stack *temp = new_stack(s->capacity);
    while (!isEmptyStack(s))
    {
        push_stack(temp, pop_stack(s));
    }
    while (!isEmptyStack(temp))
    {
        int item = pop_stack(temp);
        printf("\n%d", item);
        push_stack(s, item);
    }
    dist_stack(temp);
}

void main(){
    stack *s = new_stack(5);
    int x;
    printf("Enter numbers in stack: \n");
    for(int i = 0;i<5;i++){
        scanf("%d", &x);
        push_stack(s, x);
    }
    printf("Number of even: %d", count_Even_stack(s));

}
