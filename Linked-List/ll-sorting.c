#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

int Display(struct node *first){
    struct node *p;
    p = first;
    while(p->link != NULL){
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("%d\n", p->data);
    return 0;
}

struct node *GetList(){
    struct node *first;
    first = (struct node *)malloc(sizeof(struct node));
    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
    struct node *third;
    third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth;
    fourth = (struct node *)malloc(sizeof(struct node));

    first->data = 20;
    first->link = second;
    second->data = 30;
    second->link = third;
    third->data = 11;
    third->link = fourth;
    fourth->data = 33;
    fourth->link = NULL;
    
    return first;
}

void SelectionSort(struct node *first){
    struct node *p = first, *q;
    int temp;

    while(p){
        for(q = p->link; q; q = q->link){
            if(p->data >= q->data){
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
        p = p->link;
    }
}

int main(){
    struct node *p = GetList();
    Display(p);

    SelectionSort(p);
    Display(p);

    return 0;
}
