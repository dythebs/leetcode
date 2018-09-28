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
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp = head;
        ListNode* p = head;
        while(p != nullptr && p->next != nullptr)
        {
            tmp = p->next->next;
            swap(p->val, p->next->val);
            p = tmp;
        }
        return head;
    }
};