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
        unordered_map<int, int> hashMap;
        if(head == nullptr)
            return head;
        ListNode* myHead = new ListNode(0);
        myHead->next = head;
        ListNode* l  = myHead;
        ListNode* p = head;
        while(p != nullptr)
        {
            if(p->next != nullptr && p->next->val == p->val)
            {
                hashMap[p->val] = 1;
                p = p->next;
                continue;
            }
            if(hashMap.count(p->val))
            {
                p = p->next;
                continue;
            }
            l = l->next;
            l->val = p->val;
            p = p->next;
        }
        l->next = nullptr;
        return myHead->next;
    }
};