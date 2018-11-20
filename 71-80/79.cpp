static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    bool dfs(int deep, vector<vector<char>>& board, string& word, int rows, int cols, int x, int y, int l) {
        if(board[x][y] != word[deep])
            return false;
        deep++;
        if(deep == l)
            return true;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        char temp = board[x][y];
        board[x][y] = '#';
        for(int i = 0 ; i < 4 ; i++)
        {
            int tempx = x + dx[i];
            int tempy = y + dy[i];
            if(tempx < 0 || tempx >= rows)
                continue;
            if(tempy < 0 || tempy >= cols)
                continue;
            if(board[tempx][tempy] == '#')
                continue;
            if(dfs(deep, board, word, rows, cols, tempx, tempy, l))
                return true;
        }
        board[x][y] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.size() == 0)
            return false;
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0 ; i < rows ; i++)
            for(int j = 0 ; j < cols ; j++)
            {
                if(dfs(0, board, word, rows, cols, i, j, word.size()))
                    return true;
            }
        return false;
    }
};