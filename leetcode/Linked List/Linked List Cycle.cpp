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
    bool hasCycle(ListNode *head) {
        if(head){
            ListNode* fast = head->next;
            ListNode* slow = head;
            while(fast != NULL && fast->next != NULL && fast != slow){
                fast = fast->next->next;
                slow = slow->next;
            }
            if(fast == slow) return true;
            else return false;
        }else return false;
    }
};