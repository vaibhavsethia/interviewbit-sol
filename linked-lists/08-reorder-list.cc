/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* middle(ListNode* A){
    ListNode* slow = A;
    ListNode* fast = A;
    while(slow && fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* cur = head;
    while(cur){
       ListNode* ahead = cur->next;
       cur->next = prev;
       prev = cur;
       cur  = ahead;
    }
    return prev;
}
 
ListNode* Solution::reorderList(ListNode* A) {
    ListNode* mid = middle(A);
    ListNode* first = A;
    ListNode* second = reverseList(mid->next);
    mid->next = NULL;
    
    
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    
    while(first && second){
        cur->next = first;  first = first->next; cur = cur->next;
        cur->next = second; second = second->next; cur = cur->next;
    }
    if (first) cur->next = first;
    if (second) cur->next = second;
    return dummy->next;
}
