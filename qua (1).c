#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
// Define a structure for the queue
struct Queue {
int items[MAX_SIZE];
int front, rear;
};
// Function to initialize the queue
void initialize(struct Queue* queue) {
queue->front = -1;
queue->rear = -1;
}
// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
return (queue->front == -1);
}
// Function to check if the queue is full
int isFull(struct Queue* queue) {
return ((queue->rear + 1) % MAX_SIZE == queue->front);
}
// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
if (isFull(queue)) {
printf("Queue is full. Cannot enqueue %d\n", value);
} else {
if (isEmpty(queue)) {
queue->front = 0;}
queue->rear = (queue->rear + 1) % MAX_SIZE;
queue->items[queue->rear] = value;
printf("Enqueued %d into the queue\n", value);
}
}
// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
if (isEmpty(queue)) {
printf("Queue is empty. Cannot dequeue.\n");
return -1;
} else {
int dequeued = queue->items[queue->front];
if (queue->front == queue->rear) {
queue->front = queue->rear = -1;
} else {
queue->front = (queue->front + 1) % MAX_SIZE;
}
printf("Dequeued %d from the queue\n", dequeued);
return dequeued;
}
}
// Function to display the queue
void display(struct Queue* queue) {
if (isEmpty(queue)) {
printf("Queue is empty.\n");
} else {
printf("Queue contents: ");
int i = queue->front;
while (i != queue->rear) {
printf("%d, ", queue->items[i]);
i = (i + 1) % MAX_SIZE;
}
printf("%d\n", queue->items[i]);
}
}
int main() {
struct Queue queue;
initialize(&queue);
int choice, value;
do {
printf("\nQueue Operations Menu:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
// Enqueue
printf("Enter a value to enqueue: ");
scanf("%d", &value);
enqueue(&queue, value);
break;
case 2:
// Dequeue
dequeue(&queue);
break;
case 3:
// Display
display(&queue);
break;
case 4:
// Exit
printf("Exiting the program.\n");
break;
default:
printf("Invalid choice! Please enter a valid option.\n");
}
} while (choice != 4);
return 0;
}