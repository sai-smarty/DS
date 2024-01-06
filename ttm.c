#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Structure for a binary tree nodestruct TreeNode {
int data;
struct TreeNode* left;
struct TreeNode* right;
};
// Function to create a new binary tree node
struct TreeNode* createNode(int data) {
struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
if (newNode == NULL) {
printf("Memory allocation failed\n");
exit(1);
}
newNode->data = data;
newNode->left = newNode->right = NULL;
return newNode;
}
// Function to perform pre-order traversal (recursive)
void preOrderRecursive(struct TreeNode* root) {
if (root != NULL) {
printf("%d ", root->data);
preOrderRecursive(root->left);
preOrderRecursive(root->right);
}
}
// Function to perform in-order traversal (recursive)
void inOrderRecursive(struct TreeNode* root) {
if (root != NULL) {
inOrderRecursive(root->left);
printf("%d ", root->data);
inOrderRecursive(root->right);
}
}
// Function to perform post-order traversal (recursive)
void postOrderRecursive(struct TreeNode* root) {
if (root != NULL) {
postOrderRecursive(root->left);
postOrderRecursive(root->right);
printf("%d ", root->data);
}
}
// Structure for a stack node (used for non-recursive traversal)
struct StackNode {
struct TreeNode* data;
struct StackNode* next;
};
// Structure for a stack (used for non-recursive traversal)
struct Stack {
struct StackNode* top;
};
// Function to initialize a stack
struct Stack* createStack() {
struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
if (stack == NULL) {
printf("Memory allocation failed\n");
exit(1);
}
stack->top = NULL;
return stack;
}
// Function to check if a stack is empty
bool isEmpty(struct Stack* stack) {
return (stack->top == NULL);
}
// Function to push a tree node onto the stack
void push(struct Stack* stack, struct TreeNode* node) {
struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
if (newNode == NULL) {
printf("Memory allocation failed\n");
exit(1);
}
newNode->data = node;
newNode->next = stack->top;
stack->top = newNode;
}
// Function to pop a tree node from the stack
struct TreeNode* pop(struct Stack* stack) {
if (isEmpty(stack)) {
printf("Stack is empty\n");
exit(1);
}
struct StackNode* temp = stack->top;
stack->top = stack->top->next;
struct TreeNode* popped = temp->data;
free(temp);
return popped;
}
// Function to perform pre-order traversal (non-recursive)
void preOrderNonRecursive(struct TreeNode* root) {
if (root == NULL) {
return;
}
struct Stack* stack = createStack();
push(stack, root);
while (!isEmpty(stack)) {
struct TreeNode* current = pop(stack);
printf("%d ", current->data);
// Push the right child first, so it will be processed after the left child
if (current->right != NULL) {
push(stack, current->right);
}
if (current->left != NULL) {
push(stack, current->left);
}
}
}
// Function to perform in-order traversal (non-recursive)
void inOrderNonRecursive(struct TreeNode* root) {
if (root == NULL) {
return;
}
struct Stack* stack = createStack();
struct TreeNode* current = root;
while (current != NULL || !isEmpty(stack)) {
while (current != NULL) {
push(stack, current);
current = current->left;
}
current = pop(stack);
printf("%d ", current->data);
current = current->right;
}
}
// Function to perform post-order traversal (non-recursive)
void postOrderNonRecursive(struct TreeNode* root) {
if (root == NULL) {
return;
}
struct Stack* stack1 = createStack();
struct Stack* stack2 = createStack();
push(stack1, root);
while (!isEmpty(stack1)) {
struct TreeNode* current = pop(stack1);
push(stack2, current);
if (current->left != NULL) {
push(stack1, current->left);
}
if (current->right != NULL) {
push(stack1, current->right);
}
}
while (!isEmpty(stack2)) {
struct TreeNode* current = pop(stack2);
printf("%d ", current->data);
}
}
int main() {
// Create a sample binary tree
struct TreeNode* root = createNode(1);
root->left = createNode(2);
root->right = createNode(3);
root->left->left = createNode(4);
root->left->right = createNode(5);
printf("Recursive Pre-order Traversal: ");
preOrderRecursive(root);
printf("\n");
printf("Recursive In-order Traversal: ");
inOrderRecursive(root);
printf("\n");
printf("Recursive Post-order Traversal: ");
postOrderRecursive(root);
printf("\n");
printf("Non-recursive Pre-order Traversal: ");
preOrderNonRecursive(root);
printf("\n");
printf("Non-recursive In-order Traversal: ");
inOrderNonRecursive(root);
printf("\n");
printf("Non-recursive Post-order Traversal: ");
postOrderNonRecursive(root);
printf("\n");
return 0;
}
    