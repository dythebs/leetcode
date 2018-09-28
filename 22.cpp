static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<string> ans;
    vector<char> temp;
    int N;
    void dfs(int depth, int left, int right) {
        if(depth == N*2)
        {
            ans.push_back(string(temp.begin(), temp.end()));
            return;
        }
        if(left < N)
        {
            temp.push_back('(');
            dfs(depth+1, left+1, right);
            temp.pop_back();
        }
        if(right < left)
        {
            temp.push_back(')');
            dfs(depth+1, left, right+1);
            temp.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        ans.empty();
        N = n;
        dfs(0, 0, 0);
        return ans;
    }
};