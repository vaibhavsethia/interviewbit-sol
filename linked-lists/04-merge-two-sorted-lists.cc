/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* mergedListHead = NULL;
    ListNode* mergedListTail = NULL;
    
    while(A && B){
        if (A->val < B->val){
            if (mergedListHead == NULL){
                mergedListHead = mergedListTail = A;
            }
            else {
                mergedListTail->next = A;
                mergedListTail = mergedListTail->next;
            }
            A = A->next;
        }
        else {
           if (mergedListHead == NULL){
                mergedListHead = mergedListTail = B;
            }
            else {
                mergedListTail->next = B;
                mergedListTail = mergedListTail->next;
            }
            B = B->next; 
        }
    }
    if (A == NULL) { mergedListTail->next = B; }
    if (B == NULL) { mergedListTail->next = A; }
    return mergedListHead;
}
