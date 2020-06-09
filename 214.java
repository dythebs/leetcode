class Solution {
    public String shortestPalindrome(String s) {
        String o = s;
        s = s + "#" + new StringBuilder(s).reverse().toString();
        int l = s.length();
        int []next = new int [l+1];
        next[0] = next[1] = 0;
        for (int i = 1 ; i < l ; i++) {
            int k = next[i];
            while(s.charAt(i) != s.charAt(k) && k != 0) {
                k = next[k];
            }
            next[i + 1] = s.charAt(i) == s.charAt(k) ? k + 1 : 0;
        }
        return new StringBuilder(o.substring(next[l])).reverse().toString() + o;
    }
}