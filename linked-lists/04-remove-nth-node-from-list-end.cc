/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* nAhead= A;
    // let nAhead point to the B nodes ahead of A
    for(int curNodeCount = 0; nAhead && curNodeCount < B; ++curNodeCount){
        nAhead = nAhead->next;
    }
        
    ListNode* cur = A;
    ListNode* prev = NULL;
    while(cur && nAhead){
        prev = cur;
        cur = cur->next;
        nAhead = nAhead->next;
    }
    
    if (prev){
        prev->next = cur->next;
        delete cur;
    }
    else {
        A = cur->next;
        delete cur;
    }
    return A;
    