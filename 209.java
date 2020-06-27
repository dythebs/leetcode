class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        if (nums.length == 0) return 0;
        int []sums = new int[nums.length+1];
        for (int i = 1 ; i < sums.length ; i++) {
            sums[i] = nums[i-1] + sums[i-1];
        }
        int i = 0, j = 0, sum = nums[0];
        int ans = Integer.MAX_VALUE;
        while (j < nums.length) {
            if (sums[j+1] - sums[i] >= s) {
                while (sums[j+1] - sums[i] >= s) {
                    i++;
                }
                ans = Math.min(ans, j-i+2);
            }
            j++;
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}