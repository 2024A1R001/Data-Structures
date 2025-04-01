//https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list
//Leetcode # 2095
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int countNodes(struct ListNode* head){
    int count = 0;
        while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
struct ListNode* deleteMiddle(struct ListNode* head) {
    int size = countNodes(head);
    int mid = size /2;
    if (mid == 0){
        head = NULL;
        return head;
    }
    struct ListNode* temp = head;
    int i = 1;
    while (i < mid && temp -> next != NULL){
        i++; temp = temp->next;
    }
    if (temp -> next != NULL){
        struct ListNode* t= temp->next;
        temp->next = temp->next->next;
        free(t);
    }
    return head;

}
