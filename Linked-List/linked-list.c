#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * link; // pointer to the next node in the linked list // self-referntial structure
};

struct node *getNode(int x){
    struct node *p = (struct node *)malloc(sizeof(struct node));

    // error handling : check for allocation failure
    if(p == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }

    p->data = x;
    p->link = NULL;     // initially the link points to no node
    return p;
}

void Display(struct node *first){
    struct node *head = first;      // create a temporary pointer to traverse the list
    while(head->link != NULL){      // loop until the end of the list(head becomes NULL)
        printf("%d -> ", head->data);   // print data of the curret node
        head = head->link;          // move to the next node
    }
    printf("%d", head->data);   // this is to print last element cuz it checks for null first
}

struct node *Find(struct node *first, int x){
    struct node *p = first;
    p = first;

    while(p != NULL){
        if(p->data == x){
            return p;
        }

        else{
            p = p->link;
        }

        return NULL;
    }
}

int main(){
	struct node *first = getNode(10);   // creating a head node
	struct node *second = getNode(20);  // creating another node
    struct node *third = getNode(30);
	
    first->link = second;
    second->link = third;
    third->link = NULL;               // linking this node to the second node

	printf("Linked List: ");
	Display(first);

    struct node *resultNode = Find(first, 10);
    if (resultNode != NULL) {
        printf("\nNode found with value %d\n", 10);
    } else {
        printf("\nNode with value %d not found\n", 10);
    }

	free(first);

	return 0;
}
