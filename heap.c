#include <stdio.h>
// Function to swap two elements in an array
void swap(int* a, int* b) {
int temp = *a;
*a = *b;
*b = temp;
}
// Function to heapify a subtree with the root at the given index
void heapify(int arr[], int n, int i) {
int largest = i; // Initialize largest as the root
int left = 2 * i + 1; // Left child
int right = 2 * i + 2; // Right child
// If the left child is larger than the root
if (left < n && arr[left] > arr[largest]) {
largest = left;
}
// If the right child is larger than the largest so far
if (right < n && arr[right] > arr[largest]) {
largest = right;
}
// If the largest is not the root, then swap and heapify the affected subtree
if (largest != i) {
swap(&arr[i], &arr[largest]);
heapify(arr, n, largest);
}
}
// Function to perform Heap Sort
void heapSort(int arr[], int n) {
// Build a max heap
for (int i = n / 2 - 1; i >= 0; i--) {
heapify(arr, n, i);
}
// Extract elements from the heap one by one
for (int i = n - 1; i >= 0; i--) {
// Move the current root to the end
swap(&arr[0], &arr[i]);
// Call heapify on the reduced heap
heapify(arr, i, 0);
}
}
int main() {
int arr[] = {12, 11, 13, 5, 6, 7};
int n = sizeof(arr) / sizeof(arr[0]);
printf("Original array: ");
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
heapSort(arr, n);
printf("Sorted array (ascending order): ");
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
return 0;
}