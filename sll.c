#include <stdio.h>
#include <stdlib.h>
// Define a structure for a singly linked list node
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
// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
struct Node* newNode = createNode(data);
newNode->next = head;
return newNode;}
// Function to delete a node by value
struct Node* deleteNode(struct Node* head, int key) {
struct Node* current = head;
struct Node* prev = NULL;
// If the head node itself holds the key to be deleted
if (current != NULL && current->data == key) {
head = current->next;
free(current);
return head;
}
// Search for the key to be deleted, keep track of the previous node
while (current != NULL && current->data != key) {
prev = current;
current = current->next;
}
// If the key is not present in the list
if (current == NULL) {
printf("Key not found in the list\n");
return head;
}
// Unlink the node and free memory
prev->next = current->next;
free(current);
return head;
}// Function to traverse and print the linked list
void traverse(struct Node* head) {
struct Node* current = head;
printf("Linked List: ");
while (current != NULL) {
printf("%d -> ", current->data);
current = current->next;
}
printf("NULL\n");
}
int main() {
struct Node* head = NULL;
int choice, data, key;
do {
printf("\nSingly Linked List Operations Menu:\n");
printf("1. Create a linked list\n");
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
scanf("%d", &data);head = createNode(data);
break;
case 2:
// Insertion at the beginning
printf("Enter data to insert at the beginning: ");
scanf("%d", &data);
head = insertAtBeginning(head, data);
break;
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