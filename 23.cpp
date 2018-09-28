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
class Cmp {
    public:
        bool operator() (const ListNode* a,const ListNode* b) const
        {
            return a->val > b->val;
        }
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> q;
        for(auto list : lists)
        {
            ListNode *p = list;
            while(p)
            {
                q.push(p);
                p = p->next;
            }
        }
        if(q.size() == 0)
            return nullptr;
        ListNode *res = q.top();
        q.pop();
        ListNode *p = res;
        while(!q.empty())
        {
            p->next = q.top();
            p = p->next;
            q.pop();
        }
        p->next = nullptr;
        return res;
    }
};