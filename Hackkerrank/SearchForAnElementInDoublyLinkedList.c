#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
} Node;
Node* head = NULL;

void insert(int val) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = val;
    new->prev = NULL;
    new->next = head;

    if (head != NULL)
        head->prev = new;

    head = new;
}
int main() {
    int n; scanf("%d",&n);
    for (int i = 0; i < n; i++){
        int k; scanf("%d",&k);
        insert(k);
    }
    int t; scanf("%d",&t);
    Node* temp = head;
    while (temp != NULL){
        if (temp->data==t){
            printf("Found"); return 0;
        }
        temp= temp->next;
    }
    printf("Not Found");
    return 0;
}
