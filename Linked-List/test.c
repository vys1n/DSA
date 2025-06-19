#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * link;
};

struct node *getNode(int x){
    struct node *p = (struct node *)malloc(sizeof(struct node));

    if(p == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }

    p->data = x;
    p->link = NULL;
    return p;
}

void Display(struct node *first){
    struct node *head = first;
    while(head->link != NULL){
        printf("%d -> ", head->data);
        head = head->link;
    }
    printf("%d\n", head->data);
}

void DeleteAtEnd(struct node *first){
    struct node *p, *r;
    r = p = first;
    while(p->link != NULL){
        r = p;
        p = p->link;
    }
    r->link = NULL;
    free(p);
}

struct node *Delete(struct node *first, int x) {
    struct node *p = first, *q = NULL;

    // If the list is empty
    if (p == NULL) {
        printf("No nodes in linked list.\n");
        return NULL;
    }

    // If the node to be deleted is the first node
    if (p->data == x) {
        first = first->link;
        free(p);
        return first;
    }

    // Traverse the list to find the node to delete
    while (p != NULL && p->data != x) {
        q = p;
        p = p->link;
    }

    // If the node was not found
    if (p == NULL) {
        printf("Element %d not found in the linked list.\n", x);
        return first;
    }

    // Unlink the node and free the memory
    q->link = p->link;
    free(p);

    return first;
}

int main(){
    struct node *first = getNode(10);   // creating a head node
	
	struct node *second = getNode(20);  // creating another node
	first->link = second;               // linking this node to the first node

	struct node *third = getNode(30);
	second->link = third;

    struct node *fourth = getNode(40);
	third->link = fourth;

    struct node *fifth = getNode(50);
	fourth->link = fifth;

    struct node *sixth = getNode(60);
	fifth->link = sixth;

    printf("Linked List: ");
	Display(first);

    DeleteAtEnd(first);
    printf("Linked List(after deletion): ");
	Display(first);

    first = Delete(first, 50);
    printf("Linked List(after deletion of the element we want to delete): ");
	Display(first);
    
    return 0;
}
