#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // -1 means null
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) continue; // skip nulls
        sum += arr[i];
    }

    printf("%d", sum);
    return 0;
}
