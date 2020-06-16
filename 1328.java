class Solution {
    public String breakPalindrome(String palindrome) {
        if (palindrome.length() == 1) {
            return "";
        }
        char []ca = palindrome.toCharArray();
        for (int i = 0 ; i < ca.length / 2 ; i++) {
            if (ca[i] != 'a') {
                ca[i] = 'a';
                return new String(ca);
            }
        }
        ca[ca.length-1] += 1;
        return new String(ca);
    }
}