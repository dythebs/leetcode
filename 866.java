class Solution {
    public int primePalindrome(int N) {
        for (int l = 1 ; l <= 5 ; l++) {
            for (int i = (int)Math.pow(10, l-1) ; i < Math.pow(10, l) ; i++) {
                StringBuilder sb = new StringBuilder(String.valueOf(i));
                for (int j = l - 2 ; j >= 0 ; j--) {
                    sb.append(sb.charAt(j));
                }
                int x = Integer.valueOf(sb.toString());
                if (x >= N && isPrime(x)) {
                    return x;
                }
            }
            for (int i = (int)Math.pow(10, l-1) ; i < Math.pow(10, l) ; i++) {
                StringBuilder sb = new StringBuilder(String.valueOf(i));
                for (int j = l - 1 ; j >= 0 ; j--) {
                    sb.append(sb.charAt(j));
                }
                int x = Integer.valueOf(sb.toString());
                if (x >= N && isPrime(x)) {
                    return x;
                }
            }
        }
        return 0;
    }
    private boolean isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2 ; i <= (int)Math.sqrt(n) ; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
}