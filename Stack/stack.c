#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int top;            // pointer in the stack
    int items[MAX];     // items to go in the stack
};

struct Stack * createStack() {
    
    // creating the stack pointer by getting the size of the stack, giving it a memory address
    // and giving it the same type as the stack
    struct Stack *s = (struct Stack *)(malloc(sizeof(struct Stack)));
    
    s -> top = -1;      // initializing the pointer by showing it as an empty stack
    return s;
}

int isFull(struct Stack *s) {
    return (s -> top == MAX - 1);   // the stack will be full if the top pointer is at the max item limit
}

int isEmpty(struct Stack *s) {
    return (s -> top == -1);    // the stack will be empty if the top pointer is pointing at the empty item
}

void Push(struct Stack *s, int items) {
    
    // first we will check if the stack is full before insert an item in the stack
    if (isFull(s)) {
        printf("Stack Overflow");
        return;
    }

    // ++s -> top implies we are first incrementing the top by 1 before inserting the element
    // s -> items[...] = items assigns the value at that top position
    s -> items[++s -> top] = items;
}

int Pop(struct Stack *s) {
    
    // first we will check if the stack is empty before deleting an item from the stack
    if (isEmpty(s)) {
        printf("Stack Underflow");
        return -1;
    }

    // s -> top-- we use it to first access the element at the top level and then we decrement the top by 1
    // s -> items retrieves the value from the current top position before the decrement
    // Since we post-decremented top, we are accessing the position before the decrement
    // effectively getting the element at the top of the stack
    return (s -> items[s -> top--]);
}

int main() {
    struct Stack *p = createStack();

    Push(p, 10);
    Push(p, 100);
    Push(p, 1000);

    printf("First element of Stack : %d", Pop(p));
    printf("\nSecond element of Stack : %d", Pop(p));

    free(p);

    return 0;
}
