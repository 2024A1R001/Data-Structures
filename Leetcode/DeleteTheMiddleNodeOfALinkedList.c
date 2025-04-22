//leetcode 2095
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL || head -> next == NULL){
        return NULL; //head is the only node, so list will be empty
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL; //to stay one node before slow
    while (fast != NULL && fast -> next != NULL){
        prev = slow; slow = slow->next;
        fast = fast -> next -> next;
    } 
    // Now slow is at middle node and prev is at node before previous
    prev -> next = slow -> next;
    free(slow);
    return head;
}
