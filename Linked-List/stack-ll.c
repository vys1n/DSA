#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *tos = NULL;

void Push(int x){
    Node *p = (Node *)malloc(sizeof(Node));
    
    if(p == NULL){
        printf("Memory Allocation failed");
        return;
    }

    p->data = x;
    p->next = tos;
    tos = p;
}

int Pop(){
    if(tos == NULL){
        printf("Empty");
        return -1;
    }

    else{
        int y = tos->data;
        Node *p = tos;
        tos = tos->next;
        free(p);
        return y;
    }
}

void Display(){
    Node *current = tos;
    while(current != NULL){
        printf("%d | ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    Push(10);
    Push(20);
    Push(30);

    printf("Stack: ");
    Display();

    int popped = Pop();
    printf("Popped element: %d\n", popped);

    printf("Stack after popping: ");
    Display();
    
    return 0;
}