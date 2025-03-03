#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n; scanf("%d",&n);
    int stack[n], top=-1;
    for (int i = 0; i < n; i++){
        int num; scanf("%d",&num);
        stack[++top]=num;
        
    }
    for (int i = 0; i < n; i++){
        for (int j= i+1; j<n; j++){
            if (stack[i]>stack[j]){
                int temp= stack[i]; stack[i]=stack[j]; stack[j]=temp;    
            }
        }
    }
    for (int i = top; i >=0; i--){
printf("%d ",stack[i]);}
    return 0;
}
