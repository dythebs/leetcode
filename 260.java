class Solution {
    public int[] singleNumber(int[] nums) {
        int n = 0;
        for (int i = 0 ; i < nums.length ; i++) {
            n = n ^ nums[i];
        }
        int index = 0;
        for (; index < 32 ; index++) {
            if (((1<<index)&n)>0) {
                break;
            }
        }
        int ans1 = 0, ans2 = 0;
        for (int i = 0 ; i < nums.length ; i++) {
            if (((1<<index)&nums[i])>0) {
                ans1 = ans1 ^ nums[i];
            } else {
                ans2 = ans2 ^ nums[i];
            }
        }
        return new int[] {ans1, ans2};
    }
}