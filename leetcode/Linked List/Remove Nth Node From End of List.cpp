/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tmp = new ListNode(0);
        tmp->next = head;
        ListNode *p, *q, *r;
        p = q = r = tmp;
        for(int i = 0; i < n - 1; ++i){
            r = r->next;
        }
        
        while(r->next != NULL){
            r = r->next;
            q = p;
            p = p->next;
        }
        
        q->next = p->next;
        
        return tmp->next;
    }
};