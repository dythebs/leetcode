static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    int sum;
    void dfs(int d, vector<int>& candidates, int target)
    {
        if(target < 0)
            return;
        if(target == 0)
            ans.push_back(temp);
        for(int i = d ; i < candidates.size() ; i++)
        {
            temp.push_back(candidates[i]);
            dfs(i, candidates, target-candidates[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear(), temp.clear(), sum = 0;
        dfs(0, candidates, target);
        return ans;
    }
};