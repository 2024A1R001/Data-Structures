#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int size; scanf("%d",&size);
    int arr[size];
    for (int i = 0; i < size; i++){
        scanf("%d",&arr[i]);
    }
    int target; scanf("%d",&target);
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++){
            if (arr[i]+arr[j]==target){
                printf("%d %d",i,j);
            }
        }
    }
    return 0;
}
