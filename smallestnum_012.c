#include <stdio.h>

int main() {
    int n, i;
    int a[100];
    int min, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    min = a[0];
    pos = 0;
    for (i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
            pos = i;
        }
    }
    printf("The smallest element is %d at position %d\n", min, pos + 1);
    return 0;
}
