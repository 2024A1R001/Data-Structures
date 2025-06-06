#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int tree1[100], tree2[100];
void init(){
    for (int i = 0; i < 100; i++){   tree1[i] = -1; tree2[i]=-1;
}
}
void insert(int tree[], int val, int root){
    if (tree[root] == -1){
        tree[root]= val;
    } else if (val < tree[root]){
        insert(tree,val, 2*root+1);
    } else if (val > tree[root]){
        insert(tree,val, 2*root+2);
    }
}
int left(int root){return 2*root+1;}
int right(int root){return 2*root+2;}
int check(int root1, int root2){
    if (tree1[root1] == -1 && tree2[root1] == -1){
        return 1;
    }
    if (tree1[root1] == -1 || tree2[root1] == -1){
        return 0;
    }
    return (tree1[root1] == tree2[root2] && check(left(root1),left(root2)) && check(right(root1),right(root2)));
}
int main() {
     init();
    int n; scanf("%d",&n); int val;
    for (int i = 0; i < n; i++){
        scanf("%d",&val); insert(tree1,val,0);
    }
    for (int i = 0; i < n; i++){
        scanf("%d",&val); insert(tree2,val,0);
    }
    int m = check(0,0);
    printf("%s ", m == 1?"Identical":"Not Identical");
    return 0;
}
