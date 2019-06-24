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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;

        vector<int> vals;
        ListNode* p = head;
        while(p != NULL){
            vals.push_back(p->val);
            p = p->next;
        }

        ListNode* res = new ListNode(vals.back());
        p = res;
        for(int i = vals.size() - 2; i >= 0; --i){
            p->next = new ListNode(vals[i]);
            p = p->next;
        }

        return res;
    }
};