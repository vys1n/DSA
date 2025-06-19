// WAP to insert a node after node x and before node y [D0NE]
// WAP to insert a node with data x at the end of given linked list [DONE]
// WAP to add a node with data x at the begining of given linked list [DONE]
// WAP to add a node with data x after node with data y [DONE]
// WAP to add a node with data x before node with data y [DONE]

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

struct node *InsertAtBeginning(struct node *first, int x){
    struct node *p = getNode(x);
    if(p == NULL){
        printf("Memory Allocation failed.\n");
        //return first;
        exit;
    }

    p->link = first;    // set the link of the new node(p) to point to the current first node
    first = p;  // update the pointer to the first node to point to the new node
    //return p;
}

void InsertAtEnd(struct node *first, int x){
    struct node *p = getNode(x);
    
    if(p == NULL){
        printf("Memory Allocation failed.\n");
        return;
    }

    struct node *current = first;
    // jab tak current node NULL nahi ho jata, tab tak current node ko aage badate raho
    // traverse the list to find the last node
    while(current->link != NULL){
        current = current->link;
    }

    current->link = p;  // link the new node to the last node
}

void InsertAfter(struct node *first, int x, int y){
    struct node *p = getNode(x);
    
    if(p == NULL){
        printf("Memory Allocation Failed.\n");
        return;
    }

    struct node *current = first;
    // tab tak traverse karo jab tak current node yah toh null na ho aur data usme y ho
    while(current != NULL && current->data != y){
        current = current->link;
    }

    if(current == NULL){
        printf("Node with data %d not found.\n", y);
        free(p);
        return;
    }

    // link the new node after the node with data y
    p->link = current->link;
    current->link = p;
}

void InsertBefore(struct node *first, int x, int y){
    struct node *p = getNode(x);

    if(p == NULL){
        printf("Memory Allocation Failed.\n");
        return;
    }

    // if the list is empty, or y is at the beginning, insert node at the beginning
    if(first == NULL || first->data == y){
        p->link = first;
        first = p;
    }

    // traverse the list to find the ndoe with data y
    struct node *prev = first;
    struct node *current = first->link;
    while(current != NULL && current->data != y){
        prev = current;
        current = current->link;
    }

    // if node with data y is not found, print an error message and free the new node
    if(current == NULL){
        printf("Node with data %d not found", y);
        free(p);
        return;
    }

    // link the new node before the node with data y
    prev->link = p;
    p->link = current;
}

// x - before z ; y - after z ; z - what we are inserting
/*
We need to traverse the list until we find the node with data x. Then, we insert the new node
with data z after the node with data x. Next, we traverse the list again until we find the
node with data y. Finally, we insert the new node before the node with data y.
*/
void InsertBetween(struct node *first, int x, int y, int z){
    struct node *p = getNode(z);

    if(p == NULL){
        printf("Memory allocation failed.\n");
        return;
    }

    struct node *current = first;
    // traverse the list to find the node with data x
    while(current != NULL && current->data != x){
        current = current->link;   
    }

    // check if node with data x is not found
    if(current == NULL){
        printf("Node with data %d not found", x);
        free(p);
        return;
    }

    // link the new node after the node with data x
    p->link = current->link;
    current->link = p;

    // traverse the list to find the node with data y
    while(current != NULL && current->data != y){
        current = current->link;   
    }

    // check if node with data y is not found
    if(current == NULL){
        printf("Node with data %d not found", y);
        // now we are undoing the insertion that we did it before (z after x)
        struct node *prev = first;
        while(prev->link != p){
            prev = prev->link;
        }
        prev->link = p->link;
        free(p);
        return;
    }

    // link the new node after the node with data y
    struct node *prev = first;
    while(prev->link != current){
        prev = prev->link;
    }
    prev->link = p;
    p->link = current;
}

int main(){
	struct node *first = getNode(10);
	
	struct node *second = getNode(20);
	first->link = second;

	struct node *third = getNode(30);
	second->link = third;

	printf("Linked List: ");
	Display(first);

    first = insertatbeginning(first, 69);
    //first = InsertAtBeginning(first, 99);
    //InsertAtBeginning(&first, 99);
    printf("Linked List(after insertion at beginning): ");
	Display(first);

    insertatend(first, 100);
    //InsertAtEnd(first, 100);
    //InsertAtEnd(first, 555);
    printf("Linked List(after insertion at end): ");
	Display(first);

    InsertAfter(first, 111111, 20);
    //InsertAfter(first, 777777, 100);
    printf("Linked List(after insertion of x afer y): ");
	Display(first);

    insertbefore(first, 7, 20);
    //InsertBefore(first, 1313, 20);
    //InsertBefore(first, 6969, 100);
    printf("Linked List(after insertion of x before y): ");
	Display(first);

    InsertBetween(first, 99, 10, 9010);
    //InsertBetween(first, 100, 777777, 1070);
    printf("\nLinked List(after insertion of z after x and before y): ");
	Display(first);

	free(first);

	return 0;
}
