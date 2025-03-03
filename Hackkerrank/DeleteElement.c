//Delete Element From List
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
     int n; 
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    int t;
    int newsize = 0;
    scanf("%d",&t);
    int found = 0;
    for (int i = 0; i < n; i++){
        
        if (arr[i]!=t || found ==1){
            arr[newsize++]=arr[i];
        }
        if (arr[i]==t && found == 0){
            found = 1;    
        }
    }
    for (int i = 0; i < newsize; i++){
       printf("%d ",arr[i]);
    }
    return 0;
}

