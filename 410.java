class Solution {
    public int splitArray(int[] nums, int m) {
        int[][] dp = new int[nums.length+1][m+1];
        int[] sum = new int[nums.length+1];
        for (int i = 1 ; i <= nums.length ; i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        for (int[] array : dp) {
            Arrays.fill(array, Integer.MAX_VALUE);
        }
        dp[0][0] = 0;
        for (int i = 1 ; i <= nums.length ; i++) {
            for (int j = 1 ; j <= Math.min(i, m) ; j++) {
                for (int k = 0 ; k <= i - 1 ; k++) {
                    dp[i][j] = Math.min(dp[i][j], Math.max(dp[k][j-1], sum[i] - sum[k]));
                }
            }
        }
        return dp[nums.length][m];
    }
}