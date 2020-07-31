class Solution {
    public int getMoneyAmount(int n) {
        int[][] dp = new int[n+2][n+2];
        for (int i = 1 ; i <= n ; i++) {
            dp[i][i] = 0;
        }
        for (int l = 2 ; l <= n ; l++) {
            for (int i = 1 ; i <= n ; i++) {
                int j = i + l - 1;
                if (j > n) {
                    break;
                }
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = i ; k <= j ; k++) {
                    dp[i][j] = Math.min(dp[i][j], k + Math.max(dp[i][k-1], dp[k+1][j]));
                }
            }
        }
        return dp[1][n];
    }
}