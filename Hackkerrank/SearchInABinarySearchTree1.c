#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100
int tree[MAX];
void initialise(){
    int i = 0;
    while (i < MAX){
        tree[i++] = -1;
    }
}
void insert(int root, int val){
    if (tree[root] == -1)   tree[root]= val;
    if (tree[root]>val) insert(2*root+1, val);
    if (tree[root]<val) insert(2*root+2, val);
}
void search(int target){
    int root = 0;
    while (root < MAX && tree[root] != -1){
        if (tree[root] == target){
            printf("Found"); return;
        }
        if (target < tree[root]){
            root = 2*root+1;
        } else{
            root = 2*root+2;
        }
    }
    printf("Not Found");
}
 int main() {
     initialise();
     int n, val; scanf("%d",&n);
     for (int i =0; i < n; i++){
        scanf("%d",&val); insert(0,val);
     }
     scanf("%d",&val);
     search(val);
    return 0;
}
