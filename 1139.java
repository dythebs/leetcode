class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int [][]left = new int[grid.length + 1][grid[0].length + 1];
        int [][]top = new int[grid.length + 1][grid[0].length + 1];
        for (int i = 1 ; i <= grid.length ; i++) {
            left[i][1] = grid[i-1][0];
        }
        for (int i = 1 ; i <= grid[0].length ; i++) {
            top[1][i] = grid[0][i-1];
        }
        for (int i = 1 ; i <= grid.length ; i++) {
            for (int j = 1 ; j <= grid[0].length ; j++) {
                if (grid[i-1][j-1] == 1) {
                    top[i][j] = top[i-1][j] + 1;
                    left[i][j] = left[i][j-1] + 1;
                }
            }
        }
        int ans = Integer.MIN_VALUE;
        for (int i = grid.length ; i >= 1 ; i--) {
            for (int j = grid[0].length ; j >= 1 ; j--) {
                for (int k = Math.min(i, j) ; k >= 1 && k > ans ; k--) {
                    if (top[i][j] >= k && left[i][j] >= k) {
                        if (top[i][j-k+1] >= k && left[i-k+1][j] >= k) {
                            ans = Math.max(ans, k);
                            break;
                        }
                    }
                }
            }
        }
        return ans*ans;
    }
}