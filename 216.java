class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        dfs(n, k, 0, 0);
        return ans;
    }
    List<Integer> temp = new ArrayList<>();
    List<List<Integer>> ans = new ArrayList<>();
    private void dfs(int n, int k, int sum, int last) {
        if (k == 1) {
            if (n - sum > last && n - sum <= 9) {
                temp.add(n-sum);
                ans.add(new ArrayList<>(temp));
                temp.remove(temp.size()-1);
            }
            return;
        }
        for (int i = last + 1 ; i <= 9 ; i++) {
            temp.add(i);
            dfs(n, k-1, sum + i, i);
            temp.remove(temp.size()-1);
        }
    }
}