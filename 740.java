class Solution {
    public int deleteAndEarn(int[] nums) {
        if (nums.length == 0) return 0;
        int []dp = new int[10005];
        int []cnt = new int[20005];
        int maxNum = Integer.MIN_VALUE;
        for (int num : nums) {
            maxNum = Math.max(maxNum, num);
            cnt[num]++;
        }
        dp[1] = cnt[1];
        for (int i = 2 ; i <= 10000 && i <= maxNum ; i++) {
            if (cnt[i] > 0) {
                dp[i] = Math.max(dp[i-2] + cnt[i] * i, dp[i-1]);
            } else {
                dp[i] = dp[i-1];
            }
            
        }
        return dp[maxNum];
    }
}