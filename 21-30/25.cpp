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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* myHead = new ListNode(0);
        myHead->next = head;
        ListNode* lastHead = myHead;
        while(1)
        {
            if(p == nullptr)
                return myHead->next;
            ListNode* tmp = p;
            for(int i = 0 ; i < k - 1 ; i++)
            {
                if(tmp->next)
                    tmp = tmp->next;
                else
                    return myHead->next;
            }
            ListNode* nextHead = tmp->next;
            lastHead->next = tmp;
            lastHead = p;
            ListNode* pre = nextHead;
            for(int i = 0 ; i < k ; i++)
            {
                ListNode *nextNode = p->next;
                p->next = pre;
                pre = p;
                p = nextNode;
            }
            p = lastHead->next;
            ListNode *show = myHead->next;
        }
    }
};