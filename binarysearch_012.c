#include <stdio.h>

int main() {
    int n, i, item;
    int low = 0, high, mid;
    int a[10];
    int pos = -1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    high = n - 1;

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &item);

    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == item) {
            pos = mid;
            break;
        } else if (a[mid] < item) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (pos != -1)
        printf("Element found at position %d\n", pos + 1); // +1 for human-friendly position
    else
        printf("Element not found\n");

    return 0;
}
