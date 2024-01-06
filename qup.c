#include <stdio.h>
#include <stdlib.h>
// Define a structure for a queue node
struct QueueNode {
int data;
struct QueueNode* next;
};
// Define a structure for the queue
struct Queue {
struct QueueNode* front;
struct QueueNode* rear;
};
// Function to initialize the queuevoid initialize(struct Queue* queue) {
queue->front = queue->rear = NULL;
}
// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
return (queue->front == NULL);
}
// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct
QueueNode));
if (newNode == NULL) {
printf("Memory allocation failed\n");
exit(1);
}
newNode->data = value;
newNode->next = NULL;
if (isEmpty(queue)) {
queue->front = queue->rear = newNode;
} else {
queue->rear->next = newNode;
queue->rear = newNode;
}
printf("Enqueued %d into the queue\n", value);
}
// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
if (isEmpty(queue)) {
printf("Queue is empty. Cannot dequeue.\n");
return -1;
}
struct QueueNode* temp = queue->front;
int dequeued = temp->data;
queue->front = temp->next;
free(temp);
if (queue->front == NULL) {
queue->rear = NULL;
}
printf("Dequeued %d from the queue\n", dequeued);
return dequeued;}
// Function to display the queue
void display(struct Queue* queue) {
if (isEmpty(queue)) {
printf("Queue is empty.\n");
} else {
printf("Queue contents: ");
struct QueueNode* current = queue->front;
while (current != NULL) {
printf("%d, ", current->data);
current = current->next;
}
printf("\n");
}
}
int main() {
struct Queue queue;
initialize(&queue);
int choice, value;
do {
printf("\nQueue Operations Menu:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Display\n");
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
// Free the memory allocated for the queue nodes
while (!isEmpty(&queue)) {
dequeue(&queue);
}
return 0;
}