class Solution {
    public int minInsertions(String s) {
        int [][]dp = new int[s.length()+1][s.length()+1];
        char []ca = s.toCharArray();
        for (int i = 0 ; i < s.length() ; i++) {
            dp[i][i] = 1;
            if (i + 1 < s.length()) {
                if (ca[i] == ca[i+1]) {
                    dp[i][i+1] = 2;
                } else {
                    dp[i][i+1] = 1;
                }
            }
        }
        for (int l = 3 ; l <= s.length() ; l++) {
            for (int i = 0 ; i < s.length() ; i++) {
                int j = i + l - 1;
                if (j >= s.length()) {
                    break;
                }
                if (ca[i] == ca[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return s.length() - dp[0][s.length()-1];
    }
}