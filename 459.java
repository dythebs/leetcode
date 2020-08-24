class Solution {
    public boolean repeatedSubstringPattern(String s) {
        char[] ca = s.toCharArray();
        for (int i = 1 ; i < s.length() ; i++) {
            int k = s.length() / i;
            if (k * i != s.length()) continue;
            boolean flag = true;
            for (int j = 0 ; j < i ; j++) {
                if (!flag) {
                    break;
                }
                for (int l = 1 ; l < k ; l++) {
                    if (ca[l*i+j] != ca[(l-1)*i+j]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) return true;
        }
        return false;
    }
}