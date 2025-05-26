#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 100
int tree1[SIZE];
int tree2[SIZE];
int a1[SIZE],a2[SIZE],s1=0,s2=0;
void initialise(){
    for (int i = 0; i < SIZE; i++) {
        tree1[i] = -1;
        tree2[i] = -1;
    }
}
void insert1(int root, int val) {
    if (root >= SIZE)
        return;
    if (tree1[root] == -1) {
        tree1[root] = val;
        return;
    }
    if (val < tree1[root])
        insert1(2 * root + 1, val);
    else
        insert1(2 * root + 2, val);
}
void insert2(int root, int val) {
    if (root >= SIZE)
        return;
    if (tree2[root] == -1) {
        tree2[root] = val;
        return;
    }
    if (val < tree2[root])
        insert2(2 * root + 1, val);
    else
        insert2(2 * root + 2, val);
}
void pre1(int root){
    if (tree1[root] == -1)  return;
    a1[s1++]=tree1[root];
    pre1(2*root+1);
    pre1(2*root+2);
}
void pre2(int root){
    if (tree2[root] == -1)  return;
    a2[s2++]=tree2[root];
    pre2(2*root+1);
    pre2(2*root+2);
}
void check(){
    pre1(0); pre2(0);
    if (s1 != s2) {
        printf("Not Identical");
        return;
    }
    for (int i = 0; i < s1; i++){
        if (a1[i]!=a2[i]){
            printf("Not Identical");    return;
        }
    }
    printf("Identical"); 
}
int main() {
    initialise();
    int n, val; scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d",&val); insert1(0,val);
    }
    for (int i = 0; i < n; i++){
        scanf("%d",&val); insert2(0,val);
    }
    check();
    return 0;
}
