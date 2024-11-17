#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to insert an element at a specified position
void insertElement(int arr[], int *n, int element, int position) {
    for (int i = *n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    (*n)++;
}

int main() {
    int n, element, position;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n + 1]; 
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert the element: ");
    scanf("%d", &position);

    insertElement(arr, &n, element, position);

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
