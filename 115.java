class Solution {
    public int numDistinct(String s, String t) {
        int []dp = new int[t.length()+1];
        char []sa = s.toCharArray();
        char []ta = t.toCharArray();
        dp[0] = 1;
        for (int i = 1 ; i <= s.length() ; i++) {
            for (int j = t.length() ; j >= 1 ; j--) {
                if (sa[i-1] == ta[j-1]) {
                    dp[j] = dp[j-1] + dp[j];
                } else {
                    dp[j] = dp[j];
                }
            }
        }
        return dp[t.length()];
    }
}