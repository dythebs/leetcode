/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int x = []() {
     std::ios::sync_with_stdio(false);
     cin.tie(NULL);
     return 0;
}();
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(0);
        ListNode* p = l;
        int carry = 0;
        while(l1||l2)
        {
            int i = carry;
            if(l1) i += l1->val;
            if(l2) i += l2->val;
            carry = 0;
            if(i > 9)
            {
                i %= 10;
                carry = 1;
            }
            p->next = new ListNode(i);
            p = p->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry)
        {
            p->next = new ListNode(1);
        }
        return l->next;
    }
};