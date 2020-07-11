class Solution {
    public List<Integer> countSmaller(int[] nums) {
        node tree = null;
        List<Integer> ans = new ArrayList<>();
        for (int i = nums.length-1; i >= 0 ; i--) {
            temp = 0;
            tree = insert(tree, nums[i]);
            a.add(temp);
        }
        Collections.reverse(ans);
        return ans;
    }

    private static class node {
        public int val;
        public int leftnum;
        public node left;
        public node right;
        public node() {
            val = 0;
            leftnum = 0;
            left = null;
            right = null;
        }
    }
    int temp = 0;
    private node insert(node tree, int val) {
        if (tree == null) {
            node n = new node();
            n.val = val;
            return n;
        }
        if (val < tree.val) {
            tree.leftnum++;
            tree.left = insert(tree.left, val);
        } else {
            tree.right = insert(tree.right, val);
            if (val > tree.val) {
                temp++;
            }
            temp += tree.leftnum;
        }
        return tree;
    }
}