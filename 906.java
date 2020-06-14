class Solution {
    public int superpalindromesInRange(String L, String R) {
        int ans = 0;
        long upper = Long.valueOf(R);
        long lower = Long.valueOf(L);
        for (long i = 1 ; i <= (long)Math.sqrt(Long.valueOf(R)) ; i++) {
            String root = String.valueOf(i);
            StringBuilder sb = new StringBuilder(root);
            for (int k = root.length() - 2 ; k >= 0 ; k--) {
                sb.append(sb.charAt(k));
            }
            long x = Long.valueOf(sb.toString());
            x *= x;
            if (x > upper) {
                break;
            }
            if (x >= lower && valid(x)) {
                ans++;
            }
        }
        for (long i = 1 ; i <= (long)Math.sqrt(Long.valueOf(R)) ; i++) {
            String root = String.valueOf(i);
            StringBuilder sb = new StringBuilder(root);
            for (int k = root.length() - 1 ; k >= 0 ; k--) {
                sb.append(sb.charAt(k));
            }
            long x = Long.valueOf(sb.toString());
            x *= x;
            if (x < lower) {
                continue;
            }
            if (x > upper) {
                break;
            }
            if (x >= lower && valid(x)) {
                ans++;
            }
        }
        return ans;
    }

    private boolean valid(long n) {
        if (n % 10 == 0) {
            return false;
        }
        long half = 0;
        while (half < n) {
            half = half * 10 + n % 10;
            n /= 10;
        }
        return half == n || half / 10 == n;
    }
}