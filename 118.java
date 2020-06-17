class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        if (numRows == 0) {
            return ans;
        }
        List<Integer> one = new ArrayList<>(Arrays.asList(1));
        ans.add(one);
        if (numRows == 1) {
            return ans;
        }
        for (int i = 2 ; i <= numRows ; i++) {
            List<Integer> irow = new ArrayList<>(ans.get(i-2));
            for (int j = irow.size()-1 ; j > 0 ; j--) {
                irow.set(j, irow.get(j) + irow.get(j-1));
            }
            irow.add(1);
            ans.add(irow);
        }
        return ans;
    }
}