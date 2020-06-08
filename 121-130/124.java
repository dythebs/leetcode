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
    int ans = -0x3f3f3f3f;
    int getMax(TreeNode node) {
        if (node == null) return 0;
        int l = Math.max(0, getMax(node.left));
        int r = Math.max(0, getMax(node.right));
        ans = Math.max(ans, l + r + node.val);
        return Math.max(l, r) + node.val;
    }
    public int maxPathSum(TreeNode root) {
        if (root == null) return 0;
        getMax(root);
        return ans;
    }
}