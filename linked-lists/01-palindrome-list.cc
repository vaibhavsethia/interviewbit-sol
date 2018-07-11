/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* cur = head;
    while(cur && cur->next){
       ListNode* ahead = cur->next;
       cur->next = prev;
       prev = cur;
       cur  = ahead;
    }
    return prev;
}
 
ListNode* middle(ListNode* A){
    ListNode* slow = A;
    ListNode* fast = A;
    while(slow && fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
 
int Solution::lPalin(ListNode* A) {
    ListNode* mid = middle(A);
    ListNode* midHeadReversed = reverseList(mid->next);
    
    ListNode* curBeg = A;
    ListNode* midBeg = midHeadReversed;
    
    while(curBeg && midBeg){
        if (curBeg->val != midBeg->val) return 0;
        curBeg = curBeg->next;
        midBeg = midBeg->next;
    }
    mid->next = reverseList(midHeadReversed);
    return 1;
}
