class Solution {
    public int maxProfit(int k, int[] prices) {
        int l = prices.length;
        if (l <= 1) return 0;
        if (k == 0) return 0;
        if (k > l/2) k = l/2;
        int [][]dp = new int[k+1][2];
        for (int i = 0 ; i < k ; i++) {
            dp[i][0] = -0x3f3f3f3f;
            dp[i][1] = -0x3f3f3f3f;
        }
        dp[k-1][1] = -prices[0];
        for (int i = 2 ; i <= l ; i++) {
            for (int j = 0 ; j < k ; j++) {
                dp[j][0] = Math.max(dp[j][0], dp[j][1] + prices[i-1]);
                dp[j][1] = Math.max(dp[j][1], dp[j+1][0] - prices[i-1]);
            }
        }
        int ans = -0x3f3f3f3f;
        for (int i = 0 ; i <= k ; i++) {
            ans = Math.max(ans, dp[i][0]);
        }
        return ans;
    }
}