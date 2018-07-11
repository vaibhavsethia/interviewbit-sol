/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;
    bool hasCycle = false;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
           hasCycle = true;
           break;
        }
    }
    
    if (hasCycle == false) return NULL;
    
    ListNode* cur = A;
    while(cur != slow){
        cur = cur->next;
        slow = slow->next;
    }
    return slow;
}
