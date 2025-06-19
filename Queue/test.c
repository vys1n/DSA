#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int front;
    int rear;
    int items[SIZE];
} CircQ;

CircQ* initQ() {
    CircQ* q = (CircQ*)(malloc(sizeof(CircQ)));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(CircQ* q) {
    return ((q->rear + 1) % SIZE == q->front);
}

int isEmpty(CircQ* q) {
    return (q->front == -1);
}

void enQueue(CircQ* q, int item) {
    if (isFull(q)) {
        printf("Queue is full\n");
    }

	else{
        
		if (q->front == -1) {
            q->front = 0;
        }
        
		q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = item;
    }
}

int deQueue(CircQ* q) {
    int element;
    if (isEmpty(q)) {
        printf("Queue Empty\n");
        return -1;
    } else {
        element = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % SIZE;
        }
    }
    return element;
}

void Display(CircQ* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue Elements: ");
        for (int i = q->front; i != q->rear; i = (i + 1) % SIZE) {
            printf("%d | ", q->items[i]);
        }
        printf("%d\n", q->items[q->rear]); // Print the last element
    }
}

int main() {
    CircQ* q = initQ();

    // enqueue some elements
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);

    // display the queue
    Display(q);

    // dequeue an element
    int element = deQueue(q);
    printf("Removed element is: %d\n", element);

    // display the queue after the deQueue
    Display(q);

    // enqueue some more elements
    enQueue(q, 100);
    enQueue(q, 2000);

    // display after more enqueue
    Display(q);

    // dequeue remaining elements
    while (!isEmpty(q)) {
        int dequeued = deQueue(q);
        printf("Dequeued element: %d\n", dequeued);
    }

    // display the queue (should be empty)
    Display(q);

    free(q);

    return 0;
}

