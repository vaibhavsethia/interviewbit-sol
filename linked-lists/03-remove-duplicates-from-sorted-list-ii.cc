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
    ListNode* prev = NULL;
    
    while(cur && cur->next){
        ListNode* ahead = cur->next;
        bool deleteCur = false;
        // delete all future nodes
        while(ahead && ahead->val == cur->val){
            deleteCur = true;
            cur->next = ahead->next;
            delete ahead;
            ahead = cur->next;
        }
        
        if (deleteCur){
            // delete myself and connect the ahead with the previous node
            if (prev == NULL){
                // head needs to be updated
                A = cur->next;
                delete cur;
                cur = A;
            }
            else {
                prev->next = cur->next;
                ahead = cur->next;
                delete cur;
                cur = ahead;
            }
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
    return A;
}
