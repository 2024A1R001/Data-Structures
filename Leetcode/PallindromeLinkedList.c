/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int arr[1000000],i = 0;
    struct ListNode* temp = head;
    while (temp != NULL){
        arr[i++] = temp->val;
        temp = temp-> next;
    }
    int start = 0, end = i-1;
    while (start <= end){
        if (arr[start] != arr[end]){
            return false;
        }
        start++; end--;
    }
    return true;
}
