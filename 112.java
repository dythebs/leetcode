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
    private boolean dfs(TreeNode node, int sumTarget, int sum) {
        if (node == null) return false;
        if (node.left == null && node.right == null) {
            return sum + node.val == sumTarget;
        }
        return dfs(node.left, sumTarget, sum + node.val) ||
        dfs(node.right, sumTarget, sum + node.val) ;
    }

    public boolean hasPathSum(TreeNode root, int sum) {
        return dfs(root, sum, 0);
    }
}