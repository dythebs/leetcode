static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[10][10];
        int col[10][10];
        int g[4][4][10];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(g, 0, sizeof(g));
        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0 ; j < 9 ; j++)
            {
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                if(row[i][num] || col[j][num] || g[i/3][j/3][num])
                    return false;
                row[i][num] = col[j][num] = g[i/3][j/3][num] = 1;
            }
        }
        return true;
    }
};