//leetcode 203
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* temp = head;
    if (head == NULL)   return NULL;
    while (head != NULL && head->val == val) { //if multiple occurences in beginning
       struct ListNode* t = head;
       head = head->next;
       free(t);
    }
    temp = head;
    while (temp!= NULL && temp->next != NULL){
        if (temp->next->val == val){
            struct ListNode* t = temp->next;
            temp->next = t->next;
            free(t);
        }else{
        temp = temp-> next;
        }
    }
    return head;
}
