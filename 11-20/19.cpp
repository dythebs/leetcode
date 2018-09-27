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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *myHead = new ListNode(0);
        myHead->next = head;
        ListNode *first = myHead;
        for(int i = 0 ; i < n ; i++)
            first = first->next;
        ListNode *second = myHead;
        while(first->next != nullptr)
            first = first->next, second = second->next;
        second->next = second->next->next;
        return myHead->next;
    }
};