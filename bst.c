#include <stdio.h>
#include <stdlib.h>
// Structure for a binary tree node
struct TreeNode {
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
// Function to insert a node into the BST
struct TreeNode* insert(struct TreeNode* root, int data) {
if (root == NULL) {
return createNode(data);
}
if (data < root->data) {
root->left = insert(root->left, data);
} else if (data > root->data) {
root->right = insert(root->right, data);
}
return root;
}// Function to find the minimum value node in a BST
struct TreeNode* findMin(struct TreeNode* root) {
while (root->left != NULL) {
root = root->left;
}
return root;
}
// Function to delete a node from the BST
struct TreeNode* deleteNode(struct TreeNode* root, int data) {
if (root == NULL) {
return root;
}
if (data < root->data) {
root->left = deleteNode(root->left, data);
} else if (data > root->data) {
root->right = deleteNode(root->right, data);
} else {
// Node with only one child or no child
if (root->left == NULL) {
struct TreeNode* temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
struct TreeNode* temp = root->left;
free(root);
return temp;
}
// Node with two children: Get the in-order successor (smallest in the right
subtree)
struct TreeNode* temp = findMin(root->right);
// Copy the in-order successor's data to this node
root->data = temp->data;
// Delete the in-order successor
root->right = deleteNode(root->right, temp->data);
}
return root;
}
// Function to search for a node in the BST
struct TreeNode* search(struct TreeNode* root, int key) {
if (root == NULL || root->data == key) {
return root;}
if (key < root->data) {
return search(root->left, key);
} else {
return search(root->right, key);
}
}
// Function to perform in-order traversal
void inOrderTraversal(struct TreeNode* root) {
if (root != NULL) {
inOrderTraversal(root->left);
printf("%d ", root->data);
inOrderTraversal(root->right);
}
}
// Function to perform pre-order traversal
void preOrderTraversal(struct TreeNode* root) {
if (root != NULL) {
printf("%d ", root->data);
preOrderTraversal(root->left);
preOrderTraversal(root->right);
}
}
// Function to perform post-order traversal
void postOrderTraversal(struct TreeNode* root) {
if (root != NULL) {
postOrderTraversal(root->left);
postOrderTraversal(root->right);
printf("%d ", root->data);
}
}
// Function to find the minimum value in the BST
int findMinimum(struct TreeNode* root) {
if (root == NULL) {
printf("BST is empty\n");
return -1; // Return a sentinel value to indicate an empty tree
}
while (root->left != NULL) {
root = root->left;
}
return root->data;
}// Function to find the maximum value in the BST
int findMaximum(struct TreeNode* root) {
if (root == NULL) {
printf("BST is empty\n");
return -1; // Return a sentinel value to indicate an empty tree
}
while (root->right != NULL) {
root = root->right;
}
return root->data;
}
int main() {
struct TreeNode* root = NULL;
int choice, data, key;
while (1) {
printf("\nBinary Search Tree Operations:\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Search\n");
printf("4. In-order Traversal\n");
printf("5. Pre-order Traversal\n");
printf("6. Post-order Traversal\n");
printf("7. Find Minimum\n");
printf("8. Find Maximum\n");
printf("9. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
// Insert
printf("Enter data to insert: ");
scanf("%d", &data);
root = insert(root, data);
break;
case 2:
// Delete
printf("Enter data to delete: ");
scanf("%d", &data);
root = deleteNode(root, data);
break;
case 3:
// Search
printf("Enter key to search: ");
scanf("%d", &key);
if (search(root, key) != NULL) {printf("Key %d found in the BST\n", key);
} else {
printf("Key %d not found in the BST\n", key);
}
break;
case 4:
// In-order Traversal
printf("In-order Traversal: ");
inOrderTraversal(root);
printf("\n");
break;
case 5:
// Pre-order Traversal
printf("Pre-order Traversal: ");
preOrderTraversal(root);
printf("\n");
break;
case 6:
// Post-order Traversal
printf("Post-order Traversal: ");
postOrderTraversal(root);
printf("\n");
break;
case 7:
// Find Minimum
data = findMinimum(root);
if (data != -1) {
printf("Minimum value in the BST: %d\n", data);
}
break;
case 8:
// Find Maximum
data = findMaximum(root);
if (data != -1) {
printf("Maximum value in the BST: %d\n", data);
}
break;
case 9:
// Exit
printf("Exiting the program.\n");
exit(0);
default:
printf("Invalid choice! Please enter a valid option.\n");
}
}
return 0;
}




