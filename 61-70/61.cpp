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
    ListNode* rotateRight(ListNode* head, int k) {
        int l = 0;
        ListNode* p = head;
        ListNode* last = nullptr;
        while(p != nullptr)
            l++, last = p, p = p->next;
        if(l == 0)
            return head;
        //获得链表的长度
        k %= l;
        if(k == 0)
            return head;
        int left = l-k-1;
        //获得位移的长度
        p = head;
        while(left--)
            p = p->next;
        ListNode* myHead = p->next;
        p->next = nullptr;
        last->next = head;
        return myHead;
    }
};