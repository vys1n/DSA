#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
	int front;
	int rear;
	int items[MAX];
} Queue;

Queue * createQueue(){
	Queue *q = (Queue *)(malloc(sizeof(Queue)));
	q -> front = -1;
	q -> rear = -1;
	return q;
}

int isFull(Queue *q){
	return (q -> rear == MAX - 1);
}

int isEmpty(Queue *q){
	return (q -> front == -1);
}

void enQueue(Queue *q, int value){
	if (isFull(q)){
		printf("Queue Overflow");
	}

	else{
		if (q -> front == -1){
			q -> front ++;
		}

		q -> rear ++;
		q -> items[q -> rear] = value;
	}
}

int deQueue(Queue *q){
	int item;

	if (isEmpty(q)){
		printf("Queue Underflow");
		return -1;
	}

	else{
		item = q -> items[q -> front];
		q -> front++;

		if (q -> front > q -> rear){
			q -> front = q -> rear = -1;
		}
	}

	return item;
}

void Display(Queue *q){
	if (isEmpty(q)){
		printf("dafa ho ja");
	}

	else{
		printf("Queue Elements: ");
		for (int i = q -> front; i <= q -> rear; i++){
			printf("%d || ", q -> items[i]);
		}
		printf("\n");
	}
}

int main(){
	Queue *q = createQueue();

	//enQueue some elements
	enQueue(q, 10);
	enQueue(q, 20);
	enQueue(q, 30);
	enQueue(q, 40);

	//Display the queue
	printf("After enQueue Operations:- \n");
	Display(q);

	//deQueue an element
	int num = deQueue(q);
	printf("Removed Element: %d\n", num);

	//Display the queue after the deQueue
	printf("After deQueue Operation:- \n");
	Display(q);

	//enQueue more elements
	enQueue(q, 50);
	enQueue(q, 60);

	//Display the queue after more enQueue operations
	printf("After More enQueue Operations:- \n");
	Display(q);

	free(q);

	return 0;
}
