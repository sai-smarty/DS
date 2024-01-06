#include <stdio.h>
#include <stdlib.h>
// Define a structure for a circular linked list node
struct Node {
int data;
struct Node* next;
};
// Function to create a new node
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Memory allocation failed\n");
exit(1);
}
newNode->data = data;
newNode->next = NULL;
return newNode;
}
// Function to insert a node at the beginning of the circular list
struct Node* insertAtBeginning(struct Node* head, int data) {
struct Node* newNode = createNode(data);
if (head == NULL) {
newNode->next = newNode; // Create a self-referencing node
return newNode;
} else {
struct Node* current = head;
while (current->next != head) {
current = current->next;
}
current->next = newNode;
newNode->next = head;
return newNode;
}
}
// Function to delete a node by value
struct Node* deleteNode(struct Node* head, int key) {
if (head == NULL) {
printf("List is empty\n");
return NULL;
}
struct Node* current = head;
struct Node* prev = NULL;
do {
if (current->data == key) {
if (current->next == head) {
if (prev == NULL) {
free(current);
return NULL;
} else {
prev->next = head;
free(current);
return head;
}
} else {
if (prev == NULL) {
struct Node* last = current;
while (last->next != head) {
last = last->next;
}
head = head->next;
last->next = head;
free(current);
return head;
} else {
prev->next = current->next;
free(current);
return head;
}
}
}
prev = current;
current = current->next;
} while (current != head);
printf("Key not found in the list\n");
return head;
}
// Function to traverse and print the circular linked list
void traverse(struct Node* head) {
if (head == NULL) {
printf("List is empty\n");
return;
}
struct Node* current = head;
do {
printf("%d -> ", current->data);
current = current->next;} while (current != head);
printf("\n");
}
int main() {
struct Node* head = NULL;
int choice, data, key;
do {
printf("\nCircular Linked List Operations Menu:\n");
printf("1. Create a circular linked list\n");
printf("2. Insert at the beginning\n");
printf("3. Delete a node\n");
printf("4. Traverse the list\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
// Creation
printf("Enter data to create a node: ");
scanf("%d", &data);
head = insertAtBeginning(head, data);
break;
case 2:
// Insertion at the beginning
printf("Enter data to insert at the beginning: ");
scanf("%d", &data);
head = insertAtBeginning(head, data);break;
case 3:
// Deletion
printf("Enter the value to delete: ");
scanf("%d", &key);
head = deleteNode(head, key);
break;
case 4:
// Traversal
traverse(head);
break;
case 5:
// Exit
printf("Exiting the program.\n");
break;
default:
printf("Invalid choice! Please enter a valid option.\n");
}
} while (choice != 5);
return 0;
}

