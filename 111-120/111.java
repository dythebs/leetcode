/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private int ans = Integer.MAX_VALUE;
    private void dfs(TreeNode root, int deep) {
        if (root.left == null && root.right == null) {
            ans = Math.min(ans, deep);
            return;
        }
        if (root.left != null)
        dfs(root.left, deep+1);
        if (root.right != null)
        dfs(root.right, deep+1);
    }
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        dfs(root, 1);
        return ans;
    }
}