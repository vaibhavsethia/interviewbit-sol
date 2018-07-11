/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* nthFrmLast(ListNode* head, int n, ListNode* &prev, ListNode* &tail){
    ListNode* nAhead = head; //n Nodes Ahead from head
    ListNode* cur = head;
    tail = NULL;
    prev = NULL;
    
    for(int i = 0; nAhead && i < n; ++i){
        tail = nAhead;
        nAhead = nAhead->next;
    }
    
    while(nAhead && cur){
        prev = cur;
        tail = nAhead;
        cur = cur->next;
        nAhead = nAhead->next;
    }
    return cur;
}

int lengthLL(ListNode* A){
    int cnt = 0;
    while(A){
        ++cnt;
        A = A->next;
    }
    return cnt;
}

ListNode* Solution::rotateRight(ListNode* A, int B) {
    B = B % lengthLL(A);
    if (B == 0) return A;
    ListNode* prev = NULL;
    ListNode* tail = NULL;
    ListNode* headNode = nthFrmLast(A, B, prev, tail);
    if (tail) tail->next = A;
    if (prev) prev->next = NULL;
    return headNode;
}
