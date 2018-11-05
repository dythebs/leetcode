static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    int col[10];
    vector<vector<string>> ans;
    vector<string> temp;
    int check(int r, int c)
    {
        for(int i = r-1, j = c-1 ; i >= 0 && j >= 0 ; i--, j--)
            if(temp[i][j] == 'Q')
                return 0;
        for(int i = r-1, j = c+1 ; i >= 0 && j < temp.size() ; i--, j++)
            if(temp[i][j] == 'Q')
                return 0;
        return 1;
    }
    void dfs(int deep)
    {
        if(deep == temp.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i < temp.size() ; i++)
        {
            if(col[i])
                continue;
            if(check(deep, i))
            {
                temp[deep][i] = 'Q';
                col[i] = 1;
                dfs(deep + 1);
                temp[deep][i] = '.';
                col[i] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        temp.clear();
        for(int i = 0 ; i < n ; i++)
            temp.push_back(string(n, '.'));
        memset(col, 0, sizeof(col));
        dfs(0);
        return ans;
    }
};