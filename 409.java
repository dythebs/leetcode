class Solution {
    public int longestPalindrome(String s) {
        int []nums = new int[128];
        for (char c : s.toCharArray()) {
            nums[c]++;
        }
        boolean single = false;
        int ans = 0;
        for(int i = 'A' ; i <= 'z' ; i++) {
            if ((nums[i] & 1) > 0) {
                ans += nums[i]-1;
                single = true;
            } else {
                ans += nums[i];
            }
        }
        if (single) {
            ans++;
        }
        return ans;
    }
}