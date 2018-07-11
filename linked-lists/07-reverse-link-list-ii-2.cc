/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* mthNode = head;
    ListNode* prevMthNode = dummy;

    for(int i = 1; mthNode && i < m; ++i){
        prevMthNode = mthNode;
        mthNode = mthNode->next;
    }

    // reverse
    ListNode* cur = mthNode;
    ListNode* prevCur = NULL;
    int cnt = m;
    while(cur &&  cnt <= n){
        ListNode* ahead = cur->next;
        cur->next = prevCur;
        prevCur = cur;
        cur = ahead;
    }

    prevMthNode->next = prevCur;
    mthNode->next = ahead;
    return dummy->next;
}
