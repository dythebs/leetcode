static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int heights[matrix[0].size()+1];
        memset(heights, 0, sizeof(heights));
        int ans = 0;
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            for(int j = 0 ; j < matrix[0].size() ; j++)
                heights[j] = matrix[i][j] == '1' ? heights[j]+1 : 0;
            stack<int> s;
            for(int j = 0 ; j <= matrix[0].size() ; j++)
            {
                if(s.empty() || heights[s.top()] <= heights[j])
                {
                    s.push(j);
                    continue;
                }
                while(!s.empty() && heights[s.top()] > heights[j])
                {
                    int h = heights[s.top()];
                    s.pop();
                    int l = s.empty() ? -1 : s.top();
                    ans = max(ans, h*(j-l-1));
                }
                s.push(j);
            }
        }
        return ans;
    }
};