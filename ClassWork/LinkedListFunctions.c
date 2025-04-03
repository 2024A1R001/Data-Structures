//24 MARCH 2025
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} Node;
Node* head = NULL;
Node* CreateNode(int element){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = element;
    newNode -> next = NULL; //Creating a node completed
    return newNode;
}
void insertNodeAtBeginning(int element) {   
    //create a node 
    Node* newNode = CreateNode(element);
    newNode -> next= head; //Head contains address of first node of existing list 
    // Newnode -> next = { NULL if head is empty
    //          address of first node if list is not empty }
    head = newNode;
    printf("Node Inserted\n");
}
void insertNodeAtEnd(int element) {
    //create a node 
    Node* newNode = CreateNode(element);
    if (head == NULL){
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    printf("Node Inserted\n");
}
}
void insertNodeAtAnyPosition(int position, int element) {
    //create a node 
    Node* newNode = CreateNode(element);
    if (head == NULL  && position != 1){
        printf("Invalid Position\n");
        return;
    }
    if (position == 1){
        insertNodeAtBeginning(element);
        return;
    }
    else{
        Node* temp = head;
        int i = 1;
        while (i < position - 1 && temp != NULL){
            temp = temp -> next;
            i++;
        }
        if (temp != NULL){
            newNode -> next = temp -> next;
            temp -> next = newNode;
            printf("Node Inserted\n");
        }
        else{
            printf("Invalid Position\n");
            free(newNode);
        }
    }
}
void deleteNodeFromBeginning() {
    if (head == NULL){
        printf("List is empty! Deletion is not possible\n");
        return;
    }
    Node* temp = head;
    head = head -> next;
    free(temp);
    printf("Node Deleted\n");
}
// void deleteNodeFromEnd() {
//     if (head == NULL){
//         printf("List is empty! Deletion is not possible\n");
//         return;
//     }
//     if (head -> next == NULL){
//         deleteNodeFromBeginning();
//         return;
//     }
//     Node* temp = head;
//     while (temp -> next -> next != NULL){
//         temp = temp -> next;
//     }
//     free(temp -> next);
//     temp -> next = NULL;
//     printf("Node Deleted\n");
// }
// void deleteNodeFromEnd() {
//     if (head == NULL){
//         printf("List is empty! Deletion is not possible\n");
//         return;
//     }
//     else{
//         Node* temp = head;
//         while (temp -> next -> next != NULL){
//             temp = temp -> next;
//         }
//         if (temp == head){
//             head = NULL;
//             free(temp);
//         }else{
//             Node* temp1 = temp -> next;
//             temp -> next = NULL;
//             free(temp1);
//         }
//     }
// }
void deleteNodeFromEnd() {
    if (head == NULL){
        printf("List is empty! Deletion is not possible\n");
        return;
    }
    else{
        Node* t= head;
        if (head -> next == NULL){
            t= head;
            head = NULL;
        }
        else{
            Node* temp = head;
            while (temp ->next -> next != NULL){
                temp = temp -> next;
            }
            t = temp -> next;
            temp -> next = NULL;
        }
        free(t);
        printf("Node Deleted\n");
    }
}
void deleteNodeFromAnyPosition(int position) {
    if (head == NULL){
        printf("List is empty! Deletion is not possible\n");
        return;
    }
    if (position == 1){
        deleteNodeFromBeginning();
        return;
    }
    Node* temp = head;
    int i = 1;
    while (i < position - 1 && temp -> next != NULL){ //Or you can use i < position - 1 && temp != NULL. it will just run one more time.
        temp = temp -> next; 
        i++;
    }
    if (temp -> next != NULL && i > 0){
        Node* temp1 = temp -> next;
        temp -> next = temp1 -> next; //Or temp -> next = temp1 -> next -> next;
        free(temp1);
        printf("Node Deleted\n");
    }
    else{
        printf("Invalid Position\n");
    }
}
void searchElement(int target) {
    if (head == NULL){
        printf("List is empty\n"); return;
    }
    Node* temp = head;
    int position = 1;
    while (temp != NULL){
        if (temp -> data == target){
            printf("Element found at position %d\n",position);
            return;
        }
        temp = temp -> next;
        position++;
    }
}

void sortList() {
    Node* last = NULL;
    for (Node* i = head; i-> next != NULL; i = i -> next){
        Node* j;
        for (j = head; j -> next != last; j = j -> next){
            if (j -> data > j -> next -> data){
                int temp = j -> data;
                j -> data = j -> next -> data;
                j -> next -> data = temp;
            }
        }
        last = j;
    }
    printf("List sorted\n");
}

void displayList() {
    if (head == NULL){
        printf("List is empty\n"); return;
    }
    printf("List elements are: ");
    Node* temp = head;
    while (temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
}
int main(){
    while (1){
        printf("----------------------------------------\n");
        printf("| **Singly Linked List Operations**    |\n");
        printf("----------------------------------------\n");
        printf("|  1. Insert Node at Beginning         |\n");
        printf("|  2. Insert Node at End               |\n");
        printf("|  3. Insert Node at Any Position      |\n");
        printf("|  4. Delete Node from Beginning       |\n");
        printf("|  5. Delete Node from End             |\n");
        printf("|  6. Delete Node from Any Position    |\n");
        printf("|  7. Search Element                   |\n");
        printf("|  8. Sort List                        |\n");
        printf("|  9. Display List                     |\n");
        printf("| 10. Exit                             |\n");
        printf("----------------------------------------\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter element: ");
                int element; scanf("%d",&element);
                insertNodeAtBeginning(element);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d",&element);
                insertNodeAtEnd(element);
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d",&element);
                printf("Enter position: ");
                int position; scanf("%d",&position);
                insertNodeAtAnyPosition(position,element);
                break;
            case 4:
                deleteNodeFromBeginning();
                break;
            case 5:
                deleteNodeFromEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d",&position);
                deleteNodeFromAnyPosition(position);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d",&element);
                searchElement(element);
                break;
            case 8:
                sortList();
                break;
            case 9:
                displayList();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        system("pause");
    }
    return 0;
}
