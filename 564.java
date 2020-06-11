class Solution {
    public String nearestPalindromic(String n) {
        String mirrorN = mirror(n);
        if (mirrorN.equals(n)) {
            return choose(big(n), small(n), n);
        } else {
            long mirrorNum = Long.valueOf(mirrorN);
            long num = Long.valueOf(n);
            return choose(num < mirrorNum ? small(n) : big(n), mirrorN, n);
        }
    }
    
    private String mirror(String s) {
        int half = s.length() / 2;
        return s.substring(0, half + (s.length() % 2)) + new StringBuilder(s.substring(0, half)).reverse().toString();
    }

    private String big(String s) {
        int half = s.length() / 2;
        String left = s.substring(0, half + (s.length() % 2));
        String right = s.substring(half + (s.length() % 2));
        String bigleft = String.valueOf(Long.valueOf(left) + 1);
        return mirror(bigleft + right);
    }

    private String small(String s) {
        int half = s.length() / 2;
        String left = s.substring(0, half + (s.length() % 2));
        String right = s.substring(half + (s.length() % 2));
        String bigleft = String.valueOf(Long.valueOf(left) - 1);
        if (bigleft.equals("0") || bigleft.length() < left.length()) {
            char []charArray = new char[s.length()-1];
            Arrays.fill(charArray, '9');
            return new String(charArray);
        }
        return mirror(bigleft + right);
    }

    private String choose(String s1, String s2, String n) {
        if (s1.equals("")) s1 = "0";
        if (s2.equals("")) s2 = "0";
        long diff1 = Math.abs(Long.valueOf(s1) - Long.valueOf(n));
        long diff2 = Math.abs(Long.valueOf(s2) - Long.valueOf(n));
        if (diff1 == diff2) {
            return String.valueOf(Long.valueOf(n)-diff1);
        }
        return diff1 < diff2 ? s1 : s2;
    }
}