static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int deep, vector<int> &n, int start) {
        if(deep <= n.size())
            ans.push_back(temp);
        for(int i = start ; i < n.size() ; i++)
        {
            temp.push_back(n[i]);
            dfs(deep+1, n, i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        temp.clear();
        dfs(0, nums, 0);
        return ans;
    }
};