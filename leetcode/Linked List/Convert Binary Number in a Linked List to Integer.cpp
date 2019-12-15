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
    int getDecimalValue(ListNode* head) {
        vector<int> num;
        ListNode* p = head;
        while(p != NULL){
            num.push_back(p->val);
            p = p->next;
        }

        int ret = 0, n = num.size();
        for(int i = 0; i < n; ++i)
            ret += num[i] * pow(2, n - i - 1);

        return ret;
    }
};