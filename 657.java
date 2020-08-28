class Solution {
    public boolean judgeCircle(String moves) {
        int r = 0, l = 0;
        for (char c : moves.toCharArray()) {
            switch (c) {
                case 'U': r++; break;
                case 'D': r--; break;
                case 'L': l++; break;
                case 'R': l--; break;
            }
        }
        return r == 0 && l == 0;
    }
}