#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
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
// Function to insert a node into the BST
struct TreeNode* insert(struct TreeNode* root, int data) {
if (root == NULL) {
return createNode(data);
}
if (data &lt; root-&gt;data) {
root-&gt;left = insert(root-&gt;left, data);
} else if (data &gt; root-&gt;data) {
root-&gt;right = insert(root-&gt;right, data);
}
return root;
}

34

// Function to find the minimum value node in a BST
struct TreeNode* findMin(struct TreeNode* root) {
while (root-&gt;left != NULL) {
root = root-&gt;left;
}
return root;
}
// Function to delete a node from the BST
struct TreeNode* deleteNode(struct TreeNode* root, int data) {
if (root == NULL) {
return root;
}
if (data &lt; root-&gt;data) {
root-&gt;left = deleteNode(root-&gt;left, data);
} else if (data &gt; root-&gt;data) {
root-&gt;right = deleteNode(root-&gt;right, data);
} else {
// Node with only one child or no child
if (root-&gt;left == NULL) {
struct TreeNode* temp = root-&gt;right;
free(root);
return temp;
} else if (root-&gt;right == NULL) {
struct TreeNode* temp = root-&gt;left;
free(root);
return temp;
}
// Node with two children: Get the in-order successor (smallest in the right
subtree)
struct TreeNode* temp = findMin(root-&gt;right);
// Copy the in-order successor&#39;s data to this node
root-&gt;data = temp-&gt;data;
// Delete the in-order successor
root-&gt;right = deleteNode(root-&gt;right, temp-&gt;data);
}
return root;
}
// Function to search for a node in the BST
struct TreeNode* search(struct TreeNode* root, int key) {
if (root == NULL || root-&gt;data == key) {
return root;

35

}
if (key &lt; root-&gt;data) {
return search(root-&gt;left, key);
} else {
return search(root-&gt;right, key);
}
}
// Function to perform in-order traversal
void inOrderTraversal(struct TreeNode* root) {
if (root != NULL) {
inOrderTraversal(root-&gt;left);
printf(&quot;%d &quot;, root-&gt;data);
inOrderTraversal(root-&gt;right);
}
}
// Function to perform pre-order traversal
void preOrderTraversal(struct TreeNode* root) {
if (root != NULL) {
printf(&quot;%d &quot;, root-&gt;data);
preOrderTraversal(root-&gt;left);
preOrderTraversal(root-&gt;right);
}
}
// Function to perform post-order traversal
void postOrderTraversal(struct TreeNode* root) {
if (root != NULL) {
postOrderTraversal(root-&gt;left);
postOrderTraversal(root-&gt;right);
printf(&quot;%d &quot;, root-&gt;data);
}
}
// Function to find the minimum value in the BST
int findMinimum(struct TreeNode* root) {
if (root == NULL) {
printf(&quot;BST is empty\n&quot;);
return -1; // Return a sentinel value to indicate an empty tree
}
while (root-&gt;left != NULL) {
root = root-&gt;left;
}
return root-&gt;data;
}

36

// Function to find the maximum value in the BST
int findMaximum(struct TreeNode* root) {
if (root == NULL) {
printf(&quot;BST is empty\n&quot;);
return -1; // Return a sentinel value to indicate an empty tree
}
while (root-&gt;right != NULL) {
root = root-&gt;right;
}
return root-&gt;data;
}
int main() {
struct TreeNode* root = NULL;
int choice, data, key;
while (1) {
printf(&quot;\nBinary Search Tree Operations:\n&quot;);
printf(&quot;1. Insert\n&quot;);
printf(&quot;2. Delete\n&quot;);
printf(&quot;3. Search\n&quot;);
printf(&quot;4. In-order Traversal\n&quot;);
printf(&quot;5. Pre-order Traversal\n&quot;);
printf(&quot;6. Post-order Traversal\n&quot;);
printf(&quot;7. Find Minimum\n&quot;);
printf(&quot;8. Find Maximum\n&quot;);
printf(&quot;9. Exit\n&quot;);
printf(&quot;Enter your choice: &quot;);
scanf(&quot;%d&quot;, &amp;choice);
switch (choice) {
case 1:
// Insert
printf(&quot;Enter data to insert: &quot;);
scanf(&quot;%d&quot;, &amp;data);
root = insert(root, data);
break;
case 2:
// Delete
printf(&quot;Enter data to delete: &quot;);
scanf(&quot;%d&quot;, &amp;data);
root = deleteNode(root, data);
break;
case 3:
// Search
printf(&quot;Enter key to search: &quot;);
scanf(&quot;%d&quot;, &amp;key);
if (search(root, key) != NULL) {

37

printf(&quot;Key %d found in the BST\n&quot;, key);
} else {
printf(&quot;Key %d not found in the BST\n&quot;, key);
}
break;
case 4:
// In-order Traversal
printf(&quot;In-order Traversal: &quot;);
inOrderTraversal(root);
printf(&quot;\n&quot;);
break;
case 5:
// Pre-order Traversal
printf(&quot;Pre-order Traversal: &quot;);
preOrderTraversal(root);
printf(&quot;\n&quot;);
break;
case 6:
// Post-order Traversal
printf(&quot;Post-order Traversal: &quot;);
postOrderTraversal(root);
printf(&quot;\n&quot;);
break;
case 7:
// Find Minimum
data = findMinimum(root);
if (data != -1) {
printf(&quot;Minimum value in the BST: %d\n&quot;, data);
}
break;
case 8:
// Find Maximum
data = findMaximum(root);
if (data != -1) {
printf(&quot;Maximum value in the BST: %d\n&quot;, data);
}
break;
case 9:
// Exit
printf(&quot;Exiting the program.\n&quot;);
exit(0);
default:
printf(&quot;Invalid choice! Please enter a valid option.\n&quot;);
}
}
return 0;
}
