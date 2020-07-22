class Solution {
    public int findMin(int[] numbers) {
        int l = 0, r = numbers.length - 1;
        while (r > l && numbers[r] == numbers[l]) {
            r--;
        }
        if (numbers[r] > numbers[l]) {
            return numbers[l];
        }
        while (l < r) {
            int mid = (l + r + 1) >>> 1;
            if (numbers[mid] >= numbers[0]) {
                l = mid;
            } else {
                r = mid-1;
            }
        }
        if (l == numbers.length - 1) return numbers[l];
        else return numbers[l+1];
    }
}