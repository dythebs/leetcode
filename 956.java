class Solution {
    public int tallestBillboard(int[] rods) {
        int[][] dp = new int[2][5005];
        int sum = 0;
        Arrays.fill(dp[0], -1);
        Arrays.fill(dp[1], -1);
        dp[0][0] = 0;
        for (int i = 1 ; i <= rods.length ; i++) {
            for (int j = 0 ; j <= sum ; j++) {
                int preindex = (i-1)&1;
                int index = i&1;
                int k = dp[preindex][j];
                if (k == -1) continue;
                int j1 = j + rods[i-1];
                int j2 = Math.abs(j - rods[i-1]);
                dp[index][j] = Math.max(dp[index][j], dp[preindex][j]);
                dp[index][j1] = Math.max(dp[index][j1], k);
                dp[index][j2] =  Math.max(dp[index][j2], k + Math.min(j, rods[i-1]));
            }
            sum += rods[i-1];
        }
        return Math.max(dp[0][0], dp[1][0]);
    }
}