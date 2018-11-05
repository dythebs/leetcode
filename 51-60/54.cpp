static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans {};

        if(matrix.size() == 0)
            return ans;

        int h = matrix.size()-1, w = matrix[0].size();
        int total = (h+1)*w;
        int x = 0, y = -1, d = 0;

        while(1)
        {
            if(d&1) {
                for(int i = 0 ; i < h ; i++)
                {
                    x += dx[d], y += dy[d];
                    ans.push_back(matrix[x][y]);
                }
                h--;
            } else {
                for(int i = 0 ; i < w ; i++)
                {
                    x += dx[d], y += dy[d];
                    ans.push_back(matrix[x][y]);
                }
                w--;
            }
            d = (d+1) % 4;
            if(ans.size() == total)
                break;
        }
        
            
        return ans;
    }
};