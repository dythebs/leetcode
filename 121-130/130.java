class Solution {
    public void solve(char[][] board) {
        int row = board.length;
        if (row == 0) return;
        int col = board[0].length;
        for (int i = 0 ; i < row ; i++) {
            dfs(board, i, 0);
            dfs(board, i, col-1);
        }
        for (int i = 0 ; i < col ; i++) {
            dfs(board, 0, i);
            dfs(board, row-1, i);
        }
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
    int []dx = {0, 0, 1, -1};
    int []dy = {1, -1, 0, 0};
    private void dfs(char[][] board, int x, int y) {
        int row = board.length;
        int col = board[0].length;
        if (x < 0 || x >= row || y < 0 || y >= col) return;
        if (board[x][y] != 'O') return;
        board[x][y] = '-';
        for (int i = 0 ; i < 4 ; i++) {
            dfs(board, x + dx[i], y + dy[i]);
        }
    }
}