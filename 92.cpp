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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* myHead = new ListNode(0);
        myHead->next = head;
        int index = 1;
        ListNode* p = myHead;
        while(p != nullptr && index < m)
        {
            p = p->next;
            index++;
        }
        //p是要反转的节点前面的元素
        ListNode* pre = p;
        ListNode* node = p->next;
        ListNode* Next = node->next;
        for(int i = 0 ; i < (n-m+1) ; i++)
        {
            node->next = pre;
            pre = node;
            node = Next;
            if(Next != nullptr)
                Next = Next->next;
        }
        p->next->next = node;
        p->next = pre;
        cout<<m<<" "<<n<<endl;
        return myHead->next;
    }
};