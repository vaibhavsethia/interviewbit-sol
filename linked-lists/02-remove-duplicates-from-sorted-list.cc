/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* cur = A;
    while(cur and cur->next){
        ListNode* ahead = cur->next;
        while(ahead && ahead->val == cur->val){
            ListNode* tmp = ahead;
            cur->next = ahead->next;
            delete tmp;
            ahead = cur->next;
        }
        cur = ahead;
    }
    return A;
}
