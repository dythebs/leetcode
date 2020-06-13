class Solution {
    public boolean validPalindrome(String s) {
        return validPalindrome0(s.toCharArray(), 0, s.length()-1, false);
    }
    
    private boolean validPalindrome0(char []array, int l, int r, boolean deleted) {
        while (l < r) {
            if (array[l] != array[r]) {
                if (deleted) {
                    return false;
                }
                return validPalindrome0(array, l, r-1, true) ||
                    validPalindrome0(array, l+1, r, true);
            }
            l++;
            r--;
        }
        return true;
    }
}