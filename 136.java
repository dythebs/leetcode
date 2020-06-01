class Solution {
    public int singleNumber(int[] nums) {
        int o = 0;
        for(int i = 0 ; i < nums.length ; i++) {
            o = o ^ nums[i];
        }
        return o;
    }
}