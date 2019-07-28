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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode *p = head, *q = head->next;
        while(q != NULL){
            if(q->val == p->val){
                p->next = q->next;
                q = q->next;
            }else{
                p = p->next;
                q = q->next;
            }
            
        }
        return head;
        
        
    }
};