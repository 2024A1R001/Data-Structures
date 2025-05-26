#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 100
int tree[SIZE];
void initialise(){
    int i = 0;
    while (i < 100){
        tree[i++]=-1;
    }
}
void insert(int root, int val) {
    if (root >= SIZE)
        return;
    if (tree[root] == -1) {
        tree[root] = val;
        return;
    }
    if (val < tree[root])
        insert(2 * root + 1, val);
    else
        insert(2 * root + 2, val);
}
void preorder(int root){
    if(tree[root] == -1)    return;
    printf("%d ",tree[root]);
    preorder(2*root+1); preorder(2*root+2);
}
void inorder(int root){
    if(tree[root] == -1)    return;
    inorder(2*root+1); printf("%d ",tree[root]); inorder(2*root+2);
}
void postorder(int root){
    if(tree[root] == -1)    return;
    postorder(2*root+1); postorder(2*root+2); printf("%d ",tree[root]); 
}
int main() {
    initialise();
    int n; scanf("%d",&n);
    for (int i = 0; i< n; i++){
        int val; scanf("%d",&val); insert(0, val);
    }
    preorder(0);printf("\n"); inorder(0);printf("\n"); postorder(0);
    return 0;
}
