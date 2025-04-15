//Implement a Queue using Linked List and develop functions to perform enqueue and dequeue operations. 
// //15 April 2025
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node{
    int data;
    struct Node* next;
} Node;
Node* front = NULL;
Node* rear = NULL;
void enqueue(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Queue Overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
int dequeue(){

}
int peek(){

}
void display(){

}
int main(){
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(isFull()){
                    printf("Queue is full\n");
                    break;
                }
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                if(isEmpty()){
                    printf("Queue is empty\n");
                    break;
                }
                printf("%d is dequeued\n", dequeue());
                break;
            case 3:
                printf("Element at front: %d\n", peek());
                break;
            case 4:
                if (isEmpty()){
                    printf("Queue is empty\n");
                    break;
                }
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        system("Pause");
    }
    return 0;
}
