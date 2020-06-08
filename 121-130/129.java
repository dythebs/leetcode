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
    public int sumNumbers(TreeNode root) {
        dfs(root, 0);
        return ans;
    }
    int ans = 0;
    void dfs(TreeNode node, int val) {
        if (node == null) {
            return;
        }
        if (node.left == null && node.right == null) {
            val = val*10 + node.val;
            ans += val;
            return;
        }
        dfs(node.left, val*10 + node.val);
        dfs(node.right, val*10 + node.val);
    }
}