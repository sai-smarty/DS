#include <stdio.h>
// Function to swap two elements in an array
void swap(int* a, int* b) {
int temp = *a;
*a = *b;
*b = temp;
}
// Function to partition the array and place the pivot element in its correct position
int partition(int arr[], int low, int high) {
int pivot = arr[high]; // Choose the last element as the pivot
int i = (low - 1); // Initialize the index of the smaller element
for (int j = low; j <= high - 1; j++) {
// If the current element is smaller than or equal to the pivot
if (arr[j] <= pivot) {
i++;
// Swap arr[i] and arr[j]
swap(&arr[i], &arr[j]);
}
}
// Swap arr[i + 1] and arr[high] (pivot)
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}
// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
if (low < high) {
// Partition the array into two sub-arrays
int pi = partition(arr, low, high);
// Recursive call to sort the sub-arrays
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
int main() {
int arr[] = {12, 11, 13, 5, 6};
int n = sizeof(arr) / sizeof(arr[0]);
printf("Original array: ");
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
quickSort(arr, 0, n - 1);
printf("Sorted array (ascending order): ");
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
return 0;
}
