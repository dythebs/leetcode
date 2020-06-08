class Solution {
    public int minCut(String s) {
        ans = s.length();
        
        dp = new int[s.length()][s.length()];
        for (int i = 0 ; i < s.length() ; i++) {
            dp[i][i] = 1;
            if (i + 1 < s.length() && s.charAt(i) == s.charAt(i+1)) {
                dp[i][i+1] = 1;
            }
        }
        for (int l = 3 ; l <= s.length() ; l++) {
            for (int i = 0 ; i < s.length() ; i++) {
                int j = i + l - 1;
                if (j >= s.length()) {
                    break;
                }
                if (s.charAt(i) == s.charAt(j) && dp[i+1][j-1] == 1) {
                    dp[i][j] = 1;
                }
            }
        }
        dfs(s, 0, 0);
        return ans;
    }
    int [][]dp = null;
    int ans = 0x3f3f3f3f;
    int [][]vis = new int[2000][2000];
    private void dfs(String s, int index, int depth) {
        if (vis[index][depth] == 0) {
            vis[index][depth] = 1;
        } else {
            return;
        }
        if (depth-1 > ans) return;
        if (index >= s.length()) {
            ans = Math.min(depth-1, ans);
        }
        for (int i = s.length() ; i >= index+1 ; i--) {
            //String tempS = s.substring(index, i);
            //System.out.println(tempS+"#"+(dp[index][i-1] == 1));
            if (dp[index][i-1] == 1) {
                dfs(s, i, depth+1);
            }
        }
    }
}