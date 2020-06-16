class Solution {
    public boolean canConstruct(String s, int k) {
        if (k > s.length()) {
            return false;
        }
        int []num = new int[128];
        for (char c : s.toCharArray()) {
            num[c]++;
        }
        int twonum = 0;
        for (int i = 'a' ; i <= 'z' ; ++i) {
            if ((num[i] & 1) == 1) {
                num[i]--;
                k--;
            }
            twonum += num[i] / 2;
        }
        if (k < 0) {
            return false;
        }
        if (twonum * 2 >= k) {
            return true;
        }
        return false;
    }
}