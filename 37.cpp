static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    int row[10][10];
    int col[10][10];
    int g[4][4][10];
    int pos[90][2];
    int k;
    bool check(int v, int num)
    {
        return !(row[pos[v][0]][num] || col[pos[v][1]][num] || g[pos[v][0]/3][pos[v][1]/3][num]);
    }
    bool dfs(int v, vector<vector<char>>& board)
    {
        if(v == k)
            return true;
        for(int i = 1 ; i <= 9 ; i++)
        {
            if(!check(v, i))
                continue;
            row[pos[v][0]][i] = 1;
            col[pos[v][1]][i] = 1;
            g[pos[v][0]/3][pos[v][1]/3][i] = 1;
            board[pos[v][0]][pos[v][1]] = '0' + i;
            if(dfs(v + 1, board))
                return true;
            row[pos[v][0]][i] = 0;
            col[pos[v][1]][i] = 0;
            g[pos[v][0]/3][pos[v][1]/3][i] = 0;
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(g, 0, sizeof(g));
        memset(pos, 0, sizeof(pos));
        k = 0;
        for(int i = 0 ; i < 9 ; i++)
            for(int j = 0 ; j < 9 ; j++)
            {
                if(board[i][j] == '.')
                {
                    pos[k][0] = i;
                    pos[k][1] = j;
                    k++;
                }
                else
                {
                    int num = board[i][j] - '0';
                    row[i][num] = 1;
                    col[j][num] = 1;
                    g[i/3][j/3][num] = 1;
                }
            }
        dfs(0, board);
    }
};