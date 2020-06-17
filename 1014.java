class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        int max = A[A.length-1] - (A.length-1);
        int ans = Integer.MIN_VALUE;
        for (int i = A.length - 2; i >= 0 ; i--) {
            if (A[i] + i + max > ans) {
                ans = A[i] + i + max;
            }
            if (max < A[i] - i) {
                max = A[i] - i;
            }
        }
        return ans;
    }
}