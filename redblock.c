#include <stdio.h>
#include <stdlib.h>
// Define colors for Red-Black Tree nodes
#define RED 0
#define BLACK 1
// Structure for a Red-Black Tree node
struct RBNode {
int data;
struct RBNode* parent;
struct RBNode* left;
struct RBNode* right;
int color;
};
struct RBNode* root = NULL; // Global variable for the root of the tree
// Function to create a new Red-Black Tree node
struct RBNode* createNode(int data) {
struct RBNode* newNode = (struct RBNode*)malloc(sizeof(struct RBNode));
if (newNode == NULL) {
perror("Memory allocation failed");
exit(1);
}
newNode->data = data;
newNode->parent = NULL;
newNode->left = NULL;
newNode->right = NULL;newNode->color = RED;
return newNode;
}
// Function to perform left rotation
void leftRotate(struct RBNode** root, struct RBNode* x) {
struct RBNode* y = x->right;
x->right = y->left;
if (y->left != NULL)
y->left->parent = x;
y->parent = x->parent;
if (x->parent == NULL)
*root = y;
else if (x == x->parent->left)
x->parent->left = y;
else
x->parent->right = y;
y->left = x;
x->parent = y;
}
// Function to perform right rotation
void rightRotate(struct RBNode** root, struct RBNode* y) {
struct RBNode* x = y->left;
y->left = x->right;
if (x->right != NULL)
x->right->parent = y;
x->parent = y->parent;
if (y->parent == NULL)
*root = x;
else if (y == y->parent->left)
y->parent->left = x;
else
y->parent->right = x;
x->right = y;
y->parent = x;
}
// Function to fix Red-Black Tree violations after insertion
void fixInsertion(struct RBNode** root, struct RBNode* z) {
while (z != *root && z->parent->color == RED) {
if (z->parent == z->parent->parent->left) {
struct RBNode* y = z->parent->parent->right;
if (y != NULL && y->color == RED) {
z->parent->color = BLACK;
y->color = BLACK;
z->parent->parent->color = RED;
z = z->parent->parent;
} else {
if (z == z->parent->right) {
z = z->parent;
leftRotate(root, z);
}
z->parent->color = BLACK;
z->parent->parent->color = RED;
rightRotate(root, z->parent->parent);
}
} else {
struct RBNode* y = z->parent->parent->left;
if (y != NULL && y->color == RED) {
z->parent->color = BLACK;
y->color = BLACK;
z->parent->parent->color = RED;
z = z->parent->parent;
} else {
if (z == z->parent->left) {
z = z->parent;
rightRotate(root, z);
}
z->parent->color = BLACK;
z->parent->parent->color = RED;
leftRotate(root, z->parent->parent);
}
}
}
(*root)->color = BLACK;
}
// Function to insert a key into the Red-Black Tree
void insert(struct RBNode** root, int data) {
struct RBNode* z = createNode(data);
struct RBNode* y = NULL;
struct RBNode* x = *root;
while (x != NULL) {
y = x;
if (z->data < x->data)
x = x->left;
else
x = x->right;
}
z->parent = y;
if (y == NULL)
*root = z;
else if (z->data < y->data)y->left = z;
else
y->right = z;
fixInsertion(root, z);
}
// Function to perform in-order traversal of the Red-Black Tree
void inOrderTraversal(struct RBNode* node) {
if (node != NULL) {
inOrderTraversal(node->left);
printf("%d ", node->data);
inOrderTraversal(node->right);
}
}
int main() {
int keys[] = {3, 7, 1, 5, 9, 2, 8, 4, 6};
int numKeys = sizeof(keys) / sizeof(keys[0]);
for (int i = 0; i < numKeys; i++) {
insert(&root, keys[i]);
}
printf("In-order Traversal of Red-Black Tree: ");
inOrderTraversal(root);
printf("\n");
return 0;
}