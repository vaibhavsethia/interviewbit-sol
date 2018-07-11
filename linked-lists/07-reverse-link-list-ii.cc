/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    auto mthNode = head;
    ListNode* mthPrev = NULL;
    
    for(int i = 1; mthNode && i < m; ++i){
        mthPrev = mthNode;
        mthNode = mthNode->next;
    }
    
    // reverse m to n
    ListNode* cur = mthNode;
    ListNode* prev = NULL;
    for(int i = m; cur && i <= n; ++i){
        ListNode* ahead = cur->next;
        cur->next = prev;
        prev = cur;
        cur = ahead;
    }
    mthNode->next = cur;
    if (mthPrev) {
        mthPrev->next = prev;
    }
    else {
        head = prev;
    }
    return head;
}
