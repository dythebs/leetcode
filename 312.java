class Solution {
    public int maxCoins(int[] nums) {
        int[] vals = new int[nums.length+2];
        for (int i = 0 ; i < nums.length ; i++) {
            vals[i+1] = nums[i];
        }
        vals[0] = 1;
        vals[nums.length+1] = 1;
        int[][] dp = new int[nums.length+2][nums.length+2];
        for (int l = 1 ; l <= nums.length+2 ; l++) {
            for (int i = 0 ; i < nums.length+2 ; i++) {
                int j = i + l - 1;
                if (j >= nums.length+2) {
                    break;
                }
                for (int k = i + 1 ; k < j ; k++) {
                    dp[i][j] = Math.max(dp[i][j], dp[i][k] + dp[k][j] + vals[i] * vals[j] * vals[k]);
                }
            }
        }
        return dp[0][nums.length+1];
    }
}