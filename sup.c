#include <stdio.h>
#include <stdlib.h>
// Define a structure for a stack node
struct StackNode {
int data;
struct StackNode* next;
};
// Function to create a new stack node
struct StackNode* createNode(int data) {
struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct
StackNode));
if (newNode == NULL) {
printf("Memory allocation failed\n");
exit(1);
}
newNode->data = data;
newNode->next = NULL;
return newNode;
}
// Function to check if the stack is empty
int isEmpty(struct StackNode* top) {
return (top == NULL);
}
// Function to push an element onto the stack
void push(struct StackNode** top, int value) {
struct StackNode* newNode = createNode(value);
newNode->next = *top;
*top = newNode;
printf("Pushed %d onto the stack\n", value);
}
// Function to pop an element from the stack
int pop(struct StackNode** top) {
if (isEmpty(*top)) {
printf("Stack is empty. Cannot pop.\n");
return -1;
}
struct StackNode* temp = *top;
int popped = temp->data;
*top = temp->next;
free(temp);
printf("Popped %d from the stack\n", popped);
return popped;
}
// Function to display the stack
void display(struct StackNode* top) {
if (isEmpty(top)) {
printf("Stack is empty.\n");
return;
}
printf("Stack contents: ");
while (top != NULL) {
printf("%d ", top->data);
top = top->next;
}
printf("\n");
}
int main() {
struct StackNode* top = NULL;
int choice, value;
do {
printf("\nStack Operations Menu:\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
// Push
printf("Enter a value to push: ");
scanf("%d", &value);
push(&top, value);
break;
case 2:
// Pop
pop(&top);
break;
case 3:
// Display
display(top);
break;
case 4:
// Exit
printf("Exiting the program.\n");
break;
default:
printf("Invalid choice! Please enter a valid option.\n");
}
} while (choice != 4);
// Free the memory allocated for the stack nodes
while (!isEmpty(top)) {
pop(&top);
}
return 0;
}
