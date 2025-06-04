/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// twins in array are arr[i] and arr [n-i-1]
int pairSum(struct ListNode* head) {
    int vals[100000];
    int i = 0;
    while (head) {
        vals[i++] = head->val;
        head = head->next;
    }
    int maxSum = 0;
    int n = i;
    for (int j = 0; j < n / 2; j++) {
        int sum = vals[j] + vals[n - j - 1];
        if (sum > maxSum)
            maxSum = sum;
    }
    return maxSum;
}
