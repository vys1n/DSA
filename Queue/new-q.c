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
		printf("bhara hua hai");
	}

	else{
		if (q -> front == -1){
			q -> front++;
		}

		q -> rear++;
		q -> items[q -> rear] = value;
	}
}

int deQueue(Queue *q){
	int item;

	if (isEmpty(q)){
		printf("khali hai");
		return -1;
	}

	else{
		item = q -> items[q -> front];
		q -> front++;

		if(q -> front > q -> rear){
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
		printf("Queue elements: ");
		for (int i = q -> front; i <= q -> rear; i++){
			printf("%d || ", q -> items[i]);
		}
		printf("\n");
	}
}

int main(){
	Queue *q = createQueue();

	//insert some elments
	enQueue(q, 1);
	enQueue(q, 2);
	enQueue(q, 3);
	enQueue(q, 4);
	enQueue(q, 5);

	//display the queue
	printf("After enQueue operations:- \n");
	Display(q);

	//delete some elements
	int num = deQueue(q);
	printf("Removed Element: %d\n", num);

	//display new queue
	printf("After deQueue operations:- \n");
	Display(q);

	//insert more elements
	enQueue(q, 8);
	enQueue(q, 9);

	//display new queue
	printf("After more enQueue operations:- \n");
	Display(q);

	free(q);

	return 0;
}
