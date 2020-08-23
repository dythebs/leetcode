class Solution {
    public boolean judgePoint24(int[] nums) {
        return dfs(new double[]{nums[0], nums[1], nums[2], nums[3]});
    }

    boolean dfs(double[] nums) {
        if (nums.length == 1) {
            return Math.abs(nums[0] - 24) < 1e-6;
        }
        for (int i = 0 ; i < nums.length ; i++) {
            for (int j = i + 1 ; j < nums.length ; j++) {
                ArrayList<Double> list = new ArrayList<>();
                for (int k = 0 ; k < nums.length ; k++) {
                    if (k != i && k != j) {
                        list.add(nums[k]);
                    }
                }
                list.add(0d);
                double[] nnums = list.stream().mapToDouble(Double::valueOf).toArray();
                nnums[nums.length-2] = nums[i] + nums[j];
                if (dfs(nnums)) return true;
                nnums[nums.length-2] = nums[i] * nums[j];
                if (dfs(nnums)) return true;
                nnums[nums.length-2] = nums[i] - nums[j];
                if (dfs(nnums)) return true;
                nnums[nums.length-2] = nums[j] - nums[i];
                if (dfs(nnums)) return true;
                if (Math.abs(nums[i]) > 1e-6) {
                    nnums[nums.length-2] = nums[j] / nums[i];
                    if (dfs(nnums)) return true;
                }
                if (Math.abs(nums[j]) > 1e-6) {
                    nnums[nums.length-2] = nums[i] / nums[j];
                    if (dfs(nnums)) return true;
                }
            }
        }
        return false;
    }
}