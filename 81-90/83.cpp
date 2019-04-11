/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* l  = head;
        int last = head->val;
        ListNode* p = head->next;
        while(p != nullptr)
        {
            if(p->val == last)
            {
                p = p->next;
                continue;
            }
            last = p->val;
            l = l->next;
            l->val = p->val;
            p = p->next;
        }
        l->next = nullptr;
        return head;
    }
};