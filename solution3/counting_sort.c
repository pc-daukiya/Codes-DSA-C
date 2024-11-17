#include <stdio.h>
#include <string.h>
#define RANGE 255

void countSort(char arr[]) {
    char output[strlen(arr)];
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    // Count each character's occurrence
    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];

    // Calculate cumulative count
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];

    // Place the characters in the output array
    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    // Copy the sorted characters back to the original array
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

int main() {
    char arr[] = "geeksforgeeks";
    printf("Unsorted character array is %s\n", arr);
    

    countSort(arr);
    printf("Sorted character array is %s\n", arr);
    return 0;
}
