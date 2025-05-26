#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100
int tree[MAX];
    int sum = 0;
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
int sumnode(int root){
    if (tree[root] == -1)   return 0;
    int left = 2*root+1, right = 2*root+2;
    if (tree[left]==-1 && tree[right]== -1){ //root's a leaf node
        sum+=tree[root];
    }else{
        sumnode(left); sumnode(right);
    }
    return sum;
}
int main() {
    initialise();
    int n, val; scanf("%d",&n);
     for (int i =0; i < n; i++){
        scanf("%d",&val); insert(0,val);
     }
    sumnode(0);
    printf("%d",sum);
    return 0;
}
