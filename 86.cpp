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
    ListNode* partition(ListNode* head, int x) {
        queue<int> big, small;
        ListNode* p = head;
        while(p != nullptr)
        {
            if(p->val < x)
                small.push(p->val);
            else big.push(p->val);
            p = p->next;
        }
        p = head;
        while(p != nullptr && !small.empty())
        {
            p->val = small.front();
            small.pop();
            p = p->next;
        }
        while(p != nullptr && !big.empty())
        {
            p->val = big.front();
            big.pop();
            p = p->next;
        }
        return head;
    }
};