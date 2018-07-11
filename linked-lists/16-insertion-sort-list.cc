/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* findLesserNode(ListNode* head, ListNode* key){
    ListNode* prev = NULL;
    ListNode* cur = head;
    while(cur){
        if (cur->val > key->val){ break; }
        prev = prev->next;
        cur = cur->next;
    }
    return prev;
}
 
ListNode* Solution::insertionSortList(ListNode* A) {
    if (A == NULL or A->next == NULL) return A;
    ListNode* head = A;
    ListNode* cur = A->next;
    ListNode* prev = A;
    
    while(cur){
        ListNode* ahead = cur->next;
        if (cur->val < prev->val){
            // swapping needs to be there
            ListNode* insertAfter = findLesserNode(head, cur);
            if (insertAfter == NULL){
                // head needs to be updated
                prev->next = ahead;
                cur->next = head;
                head = cur;
                cur = ahead;
            }
            else {
                prev->next = cur->next;
                cur->next = insertAfter->next;
                insertAfter->next = cur;
                cur = ahead;
            }
        }
        else {
            prev  = cur;
            cur = ahead;
        }
    }
    return head;
}
