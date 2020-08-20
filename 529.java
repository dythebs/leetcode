class Solution {
    int[] dirX = {0, 1, 0, -1, 1, 1, -1, -1};
    int[] dirY = {1, 0, -1, 0, 1, -1, 1, -1};

    public char[][] updateBoard(char[][] board, int[] click) {
        dfs(board, click[0], click[1]);
        return board;
    }

    public void dfs(char[][] board, int x, int y) {
        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length) {
            return;
        }
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }
        if (board[x][y] == 'E') {
            int n = 0;
            for (int i = 0 ; i < 8 ; i++) {
                int nx = x + dirX[i];
                int ny = y + dirY[i];
                if (nx < 0 || nx >= board.length || ny < 0 || ny >= board[0].length) {
                    continue;
                }
                if (board[nx][ny]  == 'M' || board[nx][ny] == 'X') {
                    n++;
                }
            }
            if (n == 0) {
                board[x][y] = 'B';
                for (int i = 0 ; i < 8 ; i++) {
                    int nx = x + dirX[i];
                    int ny = y + dirY[i];
                    dfs(board, nx, ny);
                }
            } else {
                board[x][y] = (char)('0' + n);
            }
        }
        

    }
}
