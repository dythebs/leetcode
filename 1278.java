class Solution {
    public int palindromePartition(String s, int k) {
        int [][]dp = new int[s.length()+1][k+1];
        int [][]cost = new int[s.length()+1][s.length()+1];
        for (int i = 1 ; i < s.length () ; i++) {
            if (s.charAt(i-1) != s.charAt(i)) {
                cost[i-1][i] = 1;
            }
        }
        for (int l = 3 ; l <= s.length() ; l++) {
            for (int i = 0 ; i < s.length() ; i++) {
                int j = i + l - 1;
                if (j >= s.length()) {
                    break;
                }
                if (s.charAt(i) == s.charAt(j)) {
                    cost[i][j] = cost[i+1][j-1];
                } else {
                    cost[i][j] = cost[i+1][j-1] + 1;
                }
            }
        }
        for (int i = 1 ; i <= s.length() ; i++) {
            dp[i][1] = cost[0][i-1];
        }
        for (int m = 2 ; m <= k ; m++) {
            for (int i = m ; i <= s.length() ; i++) {
                dp[i][m] = Integer.MAX_VALUE;
                for (int j = m-1 ; j <= i ; j++) {
                    dp[i][m] = Math.min(dp[i][m], dp[j-1][m-1] + cost[j-1][i-1]);
                }
            }
        }
        return dp[s.length()][k];
    }
}