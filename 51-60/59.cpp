static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ans(n, vector<int> (n,0));

        if(n == 0)
            return ans;

        int h = n-1, w = n;
        int total = (h+1)*w;
        int x = 0, y = -1, d = 0;
        int num = 1;

        while(1)
        {
            if(d&1) {
                for(int i = 0 ; i < h ; i++)
                {
                    x += dx[d], y += dy[d];
                    ans[x][y] = num++;
                }
                h--;
            } else {
                for(int i = 0 ; i < w ; i++)
                {
                    x += dx[d], y += dy[d];
                    ans[x][y] = num++;
                }
                w--;
            }
            d = (d+1) % 4;
            if(num > total)
                break;
        }
        
            
        return ans;
    }
};