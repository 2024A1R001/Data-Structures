#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100
typedef struct PriorityQueue{ // Structure for priority queue
    int element;
    int priority;
} PQueue;
PQueue pq[SIZE];
    int front =-1, rear = -1;
bool isEmpty() {
    return front == -1;
}
bool isFull() {
    return rear == SIZE-1;
}
void enqueue(int data, int priority) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
        pq[rear].element = data;
        pq[rear].priority = priority;
        return;
    }

    int i;
    for (i = front; i <= rear; i++) {
        if (pq[i].priority < priority) {
            for (int j = rear; j >= i; j--) {
                pq[j + 1] = pq[j];
            }
            pq[i].element = data;
            pq[i].priority = priority;
            rear++;
            return;
        }
    }
    if (i == rear + 1) {
        rear++;
        pq[rear].element = data;
        pq[rear].priority = priority;
    }
}
int dequeue(){
   int data = pq[front].element;
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return data;
}
int peek(){
    return pq[front].element;
}
void display() {
    printf("Queue elements in increasing order of priority:\n");
    for (int i = front; i <=rear; i++) { // Displaying elements in decreasing order of priority
        printf("Element: %d => Priority: %d\n", pq[i].element, pq[i].priority);
    }
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
                int data, priority;
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                enqueue(data, priority);
                break;
            case 2:
                if(isEmpty()){
                    printf("Queue is empty\n");
                    break;
                }
                printf("%d is dequeued\n", dequeue());
                break;
            case 3:
                printf("Element at front: %d", peek());
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
