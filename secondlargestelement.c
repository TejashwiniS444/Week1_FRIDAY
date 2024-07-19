// Code tofind the second largest element in the array
#include <stdio.h>
#include <limits.h>

int findSecondLargest(int arr[], int size) {
    if (size < 2) {
        printf("Array should have at least two elements\n");
        return INT_MIN;
    }

    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        printf("There is no second largest element\n");
        return INT_MIN;
    }

    return second;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size < 2) {
        printf("Array should have at least two elements\n");
        return 1;
    }

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int secondLargest = findSecondLargest(arr, size);

    if (secondLargest != INT_MIN) {
        printf("The second largest element is %d\n", secondLargest);
    }

    return 0;
}
