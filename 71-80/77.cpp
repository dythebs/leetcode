static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int gn, gk;
    vector<vector<int>> ans;
    vector<int> tmp;
    unordered_map<int, int> Map;
    void dfs(int deep, int start) {
        if(deep == gk)
        {
            ans.push_back(tmp);
            return;
        }
        for(int i = start ; i <= gn ; i++)
        {
            tmp.push_back(i);
            dfs(deep+1, i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        gn = n, gk = k;
        dfs(0, 1);
        return ans;
    }
};