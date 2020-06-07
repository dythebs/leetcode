class Solution {
    public int maxProfit(int[] prices) {
        int l = prices.length;
        if (l <= 1) return 0;
        int [][]dp = new int[l+1][2];
        dp[0][0] = 0;
        dp[0][1] = -0x3f3f3f3f;
        dp[1][0] = 0;
        dp[1][1] = -prices[0];
        for (int i = 2 ; i <= l ; i++) {
            dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            dp[i][1] = Math.max(dp[i-1][1], dp[i-2][0] - prices[i-1]);
        }
        return dp[l][0];
    }
}