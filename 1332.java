class Solution {
    public int removePalindromeSub(String s) {
        if (s == null || s.equals("")) {
            return 0;
        }
        boolean flag = true;
        for (int i = 0 ; i < s.length () / 2 ; i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return 1;
        }
        boolean a = false, b = false;
        for (int i = 0 ; i < s.length() ; i++) {
            if (!a && s.charAt(i) == 'a') {
                a = true;
            }
            if (!b && s.charAt(i) == 'b') {
                b = true;
            }
            if (a && b) {
                return 2;
            }
        }
        return 1;
    }
}