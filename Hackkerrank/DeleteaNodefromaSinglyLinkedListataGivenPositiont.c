//Error fix: if the deletion is not possible, i.e if invalid position is displayed, dont display the list

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
} node;
node* head = NULL;
void insert(int val){
    node* nd = (node*)malloc(sizeof(node));
    nd->data = val; nd->next = NULL;
    if (head == NULL){
        nd->next = head;
        head = nd;  return;
    }
    node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = nd;
}
int delete(int pos){
    if (head == NULL){
        printf("Invalid position"); return 1;
    }
    if (pos == 0) {
        node* temp = head;
        head = head->next;
        free(temp);
        return 0;
    }
    int i = 0; node* temp = head;
    while (i < pos -1 && temp -> next != NULL){
        i++; temp = temp -> next;
    }
    if(temp -> next == NULL){
        printf("Invalid position\n"); return 1;
    }
    node* t = temp -> next;
    temp->next = t->next;
    free(t);
    return 0;
}
int main() {
    int n; scanf("%d",&n);
    for (int i = 0; i < n; i++){
        int v; scanf("%d",&v); insert(v);
    }
    scanf("%d",&n); int a =delete(n);
    if (a == 0){
    node* t = head;
    
    while (t != NULL){
        printf("%d ",t->data);
        t= t-> next;
    }
    }
    return 0;
}
