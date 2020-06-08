class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet();
        for (int i = 0 ; i < nums.length ; i++) {
            set.add(nums[i]);
        }
        int ans = 0;
        int tempAns = 0;
        for (int i = 0 ; i < nums.length ; i++) {
            if (set.contains(nums[i]-1)) {
                continue;
            } else {
                for (int j = nums[i] ; ; j++) {
                    if (set.contains(j)) {
                        tempAns++;
                        ans = Math.max(ans, tempAns);
                    } else {
                        tempAns = 0;
                        break;
                    }
                }
            }
        }
        return ans;
    }
}