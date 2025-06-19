#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack{
    int top;
    int items[MAX];
};

struct Stack * createStack(){
    struct Stack *s = (struct Stack *)(malloc(sizeof(struct Stack)));
    s -> top = -1;
    return s;
}

int isFull(struct Stack *s){
    return (s -> top == MAX - 1);
}

int isEmpty(struct Stack *s){
    return (s -> top == - 1);
}

void Push(struct Stack *s, int items){
    if (isFull(s)){
        printf("Stack Overflow");
        return;
    }

    s -> items[++s -> top] = items;
}

int Pop(struct Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow");
        return -1;
    }

    return (s -> items[s -> top--]);
}

int main(){
    struct Stack *p = createStack();

    Push(p, 13);
    Push(p, 18);
    Push(p, 31);
    Push(p, 8);

    printf("The First Element of the stack is %d", Pop(p));
    printf("\nThe Second Element of the stack is %d", Pop(p));
}