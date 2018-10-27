static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    int used[10000];
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> *p;
    void dfs(int deep) {
        if(deep == p->size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i < p->size() ; i++)
        {
            int t = (*p)[i];
            if(i < p->size() - 1 && t == (*p)[i+1] && used[i+1])
                continue;
            if(!used[i])
            {
                used[i] = 1;
                temp.push_back(t);
                dfs(deep + 1);
                used[i] = 0;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ans.clear();temp.clear();
        memset(used, 0, sizeof(used));
        p = &nums;
        dfs(0);
        return ans;
    }
};