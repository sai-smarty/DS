#include <stdio.h>
#include <stdlib.h>
// Structure for an AVL tree node
struct AVLNode {
int data;
struct AVLNode* left;
struct AVLNode* right;
int height;
};
// Function to calculate the height of a node
int getHeight(struct AVLNode* node) {
if (node == NULL)
return 0;
return node->height;
}
// Function to calculate the balance factor of a node
int getBalanceFactor(struct AVLNode* node) {
if (node == NULL)
return 0;
return getHeight(node->left) - getHeight(node->right);
}
// Function to create a new AVL tree node
struct AVLNode* createNode(int data) {
struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
if (newNode == NULL) {
perror("Memory allocation failed");
exit(1);
}
newNode->data = data;
newNode->left = newNode->right = NULL;
newNode->height = 1;
return newNode;
}
// Function to perform a right rotation
struct AVLNode* rightRotate(struct AVLNode* y) {
struct AVLNode* x = y->left;
struct AVLNode* T2 = x->right;
x->right = y;
y->left = T2;
y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) :
getHeight(y->right));
x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) :
getHeight(x->right));return x;
}
// Function to perform a left rotation
struct AVLNode* leftRotate(struct AVLNode* x) {
struct AVLNode* y = x->right;
struct AVLNode* T2 = y->left;
y->left = x;
x->right = T2;
x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) :
getHeight(x->right));
y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) :
getHeight(y->right));
return y;
}
// Function to insert a key into the AVL tree
struct AVLNode* insert(struct AVLNode* root, int data) {
if (root == NULL)
return createNode(data);
if (data < root->data)
root->left = insert(root->left, data);
else if (data > root->data)
root->right = insert(root->right, data);
else
return root; // Duplicate keys are not allowed
root->height = 1 + (getHeight(root->left) > getHeight(root->right) ?
getHeight(root->left) : getHeight(root->right));
int balance = getBalanceFactor(root);
// Left Heavy
if (balance > 1) {
if (data < root->left->data) {
// Left-Left Case
return rightRotate(root);
} else {
// Left-Right Case
root->left = leftRotate(root->left);
return rightRotate(root);
}
}
// Right Heavy
if (balance < -1) {
if (data > root->right->data) {
// Right-Right Case
return leftRotate(root);
} else {
// Right-Left Case
root->right = rightRotate(root->right);
return leftRotate(root);
}
}
return root;
}
// Function to find the minimum value node in an AVL tree
struct AVLNode* findMin(struct AVLNode* root) {
while (root->left != NULL)
root = root->left;
return root;
}
// Function to delete a key from the AVL tree
struct AVLNode* deleteNode(struct AVLNode* root, int data) {
if (root == NULL)
return root;
if (data < root->data)
root->left = deleteNode(root->left, data);
else if (data > root->data)
root->right = deleteNode(root->right, data);
else {
// Node with only one child or no child
if (root->left == NULL) {
struct AVLNode* temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
struct AVLNode* temp = root->left;
free(root);
return temp;
}
// Node with two children
struct AVLNode* temp = findMin(root->right);
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);}
root->height = 1 + (getHeight(root->left) > getHeight(root->right) ?
getHeight(root->left) : getHeight(root->right));
int balance = getBalanceFactor(root);
// Left Heavy
if (balance > 1) {
if (getBalanceFactor(root->left) >= 0) {
// Left-Left Case
return rightRotate(root);
} else {
// Left-Right Case
root->left = leftRotate(root->left);
return rightRotate(root);
}
}
// Right Heavy
if (balance < -1) {
if (getBalanceFactor(root->right) <= 0) {
// Right-Right Case
return leftRotate(root);
} else {
// Right-Left Case
root->right = rightRotate(root->right);
return leftRotate(root);
}
}
return root;
}
// Function to perform in-order traversal of the AVL tree
void inOrderTraversal(struct AVLNode* root) {
if (root == NULL)
return;
inOrderTraversal(root->left);
printf("%d ", root->data);
inOrderTraversal(root->right);
}
int main() {
struct AVLNode* root = NULL;
int keys[] = {3, 7, 1, 5, 9, 2, 8, 4, 6};
int numKeys = sizeof(keys) / sizeof(keys[0]);
for (int i = 0; i < numKeys; i++) {
root = insert(root, keys[i]);
}
printf("In-order Traversal of AVL tree: ");
inOrderTraversal(root);
printf("\n");
int deleteKey = 5;
root = deleteNode(root, deleteKey);
printf("In-order Traversal after deleting %d: ", deleteKey);
inOrderTraversal(root);
printf("\n");
return 0;
}