#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;stdbool.h&gt;
#include &lt;limits.h&gt;
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
printf(&quot;Memory allocation failed\n&quot;);
exit(1);
}
newNode-&gt;data = data;
newNode-&gt;left = newNode-&gt;right = NULL;
return newNode;
}
// Function to perform pre-order traversal (recursive)
void preOrderRecursive(struct TreeNode* root) {
if (root != NULL) {
printf(&quot;%d &quot;, root-&gt;data);
preOrderRecursive(root-&gt;left);
preOrderRecursive(root-&gt;right);
}
}
// Function to perform in-order traversal (recursive)
void inOrderRecursive(struct TreeNode* root) {
if (root != NULL) {
inOrderRecursive(root-&gt;left);
printf(&quot;%d &quot;, root-&gt;data);
inOrderRecursive(root-&gt;right);
}
}
// Function to perform post-order traversal (recursive)
void postOrderRecursive(struct TreeNode* root) {
if (root != NULL) {
postOrderRecursive(root-&gt;left);
postOrderRecursive(root-&gt;right);
printf(&quot;%d &quot;, root-&gt;data);
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
printf(&quot;Memory allocation failed\n&quot;);
exit(1);
}
stack-&gt;top = NULL;
return stack;
}
// Function to check if a stack is empty
bool isEmpty(struct Stack* stack) {
return (stack-&gt;top == NULL);
}
// Function to push a tree node onto the stack
void push(struct Stack* stack, struct TreeNode* node) {
struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
if (newNode == NULL) {
printf(&quot;Memory allocation failed\n&quot;);
exit(1);
}
newNode-&gt;data = node;
newNode-&gt;next = stack-&gt;top;
stack-&gt;top = newNode;
}
// Function to pop a tree node from the stack
struct TreeNode* pop(struct Stack* stack) {
if (isEmpty(stack)) {
printf(&quot;Stack is empty\n&quot;);
exit(1);
}
struct StackNode* temp = stack-&gt;top;
stack-&gt;top = stack-&gt;top-&gt;next;
struct TreeNode* popped = temp-&gt;data;
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
printf(&quot;%d &quot;, current-&gt;data);
// Push the right child first, so it will be processed after the left child
if (current-&gt;right != NULL) {
push(stack, current-&gt;right);
}
if (current-&gt;left != NULL) {
push(stack, current-&gt;left);
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
current = current-&gt;left;
}
current = pop(stack);
printf(&quot;%d &quot;, current-&gt;data);
current = current-&gt;right;
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
if (current-&gt;left != NULL) {
push(stack1, current-&gt;left);
}
if (current-&gt;right != NULL) {
push(stack1, current-&gt;right);
}
}
while (!isEmpty(stack2)) {
struct TreeNode* current = pop(stack2);
printf(&quot;%d &quot;, current-&gt;data);
}
}
int main() {
// Create a sample binary tree
struct TreeNode* root = createNode(1);
root-&gt;left = createNode(2);
root-&gt;right = createNode(3);
root-&gt;left-&gt;left = createNode(4);
root-&gt;left-&gt;right = createNode(5);
printf(&quot;Recursive Pre-order Traversal: &quot;);
preOrderRecursive(root);
printf(&quot;\n&quot;);
printf(&quot;Recursive In-order Traversal: &quot;);
inOrderRecursive(root);
printf(&quot;\n&quot;);
printf(&quot;Recursive Post-order Traversal: &quot;);
postOrderRecursive(root);
printf(&quot;\n&quot;);
printf(&quot;Non-recursive Pre-order Traversal: &quot;);
preOrderNonRecursive(root);
printf(&quot;\n&quot;);
printf(&quot;Non-recursive In-order Traversal: &quot;);
inOrderNonRecursive(root);
printf(&quot;\n&quot;);
printf(&quot;Non-recursive Post-order Traversal: &quot;);
postOrderNonRecursive(root);
printf(&quot;\n&quot;);
return 0;
}
