class Solution {
    public int countBinarySubstrings(String s) {
        int[] same = new int[s.length()+1];
        same[0] = 1;
        for (int i = 1 ; i < s.length() ; i++) {
            if (s.charAt(i) == s.charAt(i-1)) {
                same[i] = same[i-1] + 1;
            } else {
                same[i] = 1;
            }
        }
        int ans = 0;
        for (int i = 1 ; i < s.length() ; i++) {
            int leftlen = same[i];
            if (i - leftlen < 0) continue;
            char rightC = s.charAt(i - leftlen);
            if (s.charAt(i) != rightC) {
                if (same[i - leftlen] >= leftlen) {
                    ans++;
                }
            }
        }
        return ans;
    }
}