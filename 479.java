class Solution {
    public int largestPalindrome(int n) {
        int upper = (int)Math.pow(10, n);
        int lower = upper / 10;
        for (int i = upper - 1 ; i > lower ; i--) {
            String s = String.valueOf(i);
            s = s + new StringBuilder(s).reverse().toString();
            long l = Long.valueOf(s);
            for (int j = upper-1 ; j >= Math.sqrt(l) ; j--) {
                if (l % j == 0) {
                    return (int)(l % 1337);
                }
            }
        }
        return 9;
    }
}