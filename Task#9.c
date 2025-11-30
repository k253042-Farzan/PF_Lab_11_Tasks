#include <stdio.h>

int linearSearch(int arr[], int size, int target, int index) {
    if (index >= size)
        return -1;

    if (arr[index] == target)
        return index;

    return linearSearch(arr, size, target, index + 1);
}

int main() {
    int n, target;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int i;

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    int result = linearSearch(arr, n, target, 0);

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found in the array\n", target);

    return 0;
}

