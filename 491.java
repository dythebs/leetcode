class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        dfs(nums, 0, 200);
        return ans;
    }
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer> temp = new ArrayList<>();
    void dfs(int[] nums, int idx, int last) {
        if (idx == nums.length) {
            if (temp.size() > 1)
                ans.add(new ArrayList<Integer>(temp));
            return;
        }
        
        if (temp.isEmpty() || temp.get(temp.size()-1) <= nums[idx]) {
            temp.add(nums[idx]);
            dfs(nums, idx+1, nums[idx]);
            temp.remove(temp.size()-1);
        }

        if (last != nums[idx]) {
            dfs(nums, idx+1, last);
        }
    }
}