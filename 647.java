class Solution {
    public int countSubstrings(String s) {
        int ans = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            for (int j = 0 ; ; j++) {
                if (i-j < 0 || i+j >= s.length()) {
                    break;
                }
                if (s.charAt(i-j) == s.charAt(i+j)) {
                    ans++;
                } else {
                    break;
                }
            }
        }
        for (int i = 0 ; i < s.length() ; i++) {
            for (int j = 0 ; ; j++) {
                if (i-j < 0 || i+1+j >= s.length()) {
                    break;
                }
                if (s.charAt(i-j) == s.charAt(i+1+j)) {
                    ans++;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
}