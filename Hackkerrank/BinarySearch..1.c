#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n; scanf("%d",&n); int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    int t; scanf("%d",&t);
    int start = 0, end = n-1;
    while (start <= end){
        int mid = start + (end-start)/2;
        if (arr[mid] == t){
            printf("Found"); return 0;
        }
        if (arr[mid] < t){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    printf("Not Found");
    return 0;
}
